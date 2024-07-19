/*
 * Copyright (c) 2023 Beijing HuaQing YuanJian Education Technology Co., Ltd
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "ohos_init.h"
#include "cmsis_os2.h"

#include "hi_io.h"
#include "hi_gpio.h"
#include "hi_i2c.h"
#include "hi_errno.h"

#include "hal_bsp_structAll.h"
#include "hal_bsp_sht20.h"
#include "hal_bsp_aw2013.h"
#include "hal_bsp_ap3216c.h"
#include "hal_bsp_ssd1306.h"
#include "hal_bsp_pcf8574.h"
#include "hal_bsp_nfc.h"
#include "hal_bsp_wifi.h"
#include "wifi_device.h"
#include "lwip/netifapi.h"
#include "lwip/sockets.h"
#include "lwip/api_shell.h"
#include "hal_bsp_mqtt.h"
#define MS(sec) (sec * 1000)
typedef struct {
    short ir;
    short als;
    short ps;
}sensor;
sensor apsensor;

float humi = 0,temp =0;
int signal_time=0;


//通过光照红外接近传感器判断是否有行人的函数
sensor hqyj_person()
{
    while(1)
    {
        AP3216C_ReadData(&apsensor.ir,&apsensor.als,&apsensor.ps);
        printf("als=%d,ps=%d\n",apsensor.als,apsensor.ps);
        return apsensor;
    }
}

//当绿灯到达后5s时，开始闪烁并且蜂鸣器随时间开始响
int hqyj_beep_green(int signal)
{
 
    while(1)
    {
        AW2013_Control_RGB(0,0,0);
        usleep(MS(500));
        set_buzzer(1);
        AW2013_Control_RGB(0,50,0);
        usleep(MS(500));
        set_buzzer(0);
        
        if(hqyj_person().ps>310)
        {
            set_buzzer(0);
            set_fan(1);
            set_led(0);
            SSD1306_ShowStr(0,1,"Person acrossing",8);
            SSD1306_ShowStr(0,2,"fan working",8);
        }else{SSD1306_ShowStr(0,1,"                 ",8);
              SSD1306_ShowStr(0,2,"                 ",8);}  
        if(apsensor.als<15)
              {
                AW2013_Control_RGB(50,50,50);
              }else
              {
                AW2013_Control_RGB(0,0,0);
              }   
        hqyj_control_humi();
        signal++;
        printf("%d\n",signal);
        if(signal==15)
        {
            return signal;
        }
    }
}

//黄灯亮时开始闪烁
int hqyj_control_yellow(int signal)
{
    while(1)
    {
        usleep(MS(500));
        AW2013_Control_RGB(0,0,0);
        usleep(MS(500));
        AW2013_Control_RGB(50,50,0);
        hqyj_control_humi();
        if(apsensor.als<15)
        {
            AW2013_Control_RGB(50,50,50);
        }else{
            AW2013_Control_RGB(50,50,0);
        }
        
        if(hqyj_person().ps>310)
        {
            SSD1306_ShowStr(0,1,"Person acrossing",8);
            SSD1306_ShowStr(0,2,"led working",8);
            set_led(1);
            set_buzzer(0);
            set_fan(0);
        }else{
                set_led(0);
                SSD1306_ShowStr(0,1,"                 ",8);
                SSD1306_ShowStr(0,2,"                 ",8);
            } 

        signal++;
        if(signal==5)
        {
            return signal;
        }   
    }
}

//判断湿度模块,将温湿度显示在OLED屏幕
void hqyj_control_humi()
{
    char show_buf[128] = {0};
    SHT20_ReadData(&temp,&humi);
    sprintf(show_buf,"T:%.2f H:%.2f",temp,humi);
    SSD1306_ShowStr(0,3,show_buf,8);
    if(humi>60)
    {
        SSD1306_ShowStr(0,4,"waring slippery road",8);
    }
    if(temp>50)
    {
        SSD1306_ShowStr(0,6,"waring slippery road",8);
    }
}

//初始化OLED屏幕
void hqyj_oled_init(){
    SSD1306_Init();//初始化
    SSD1306_CLS();//清屏
    SSD1306_ON();//打开屏幕显示
}

//当红灯亮有行人时，蜂鸣器随时间开始响
int hqyj_beep_instep(int signal)
{
    int k=0;
    int cout=0;
    while(1)
    {
        SSD1306_ShowStr(0,1,"Person acrossing",8);
        SSD1306_ShowStr(0,2,"beep working",8);
        set_buzzer(1);
        usleep(MS(250));
        set_buzzer(0);
        usleep(MS(250));
        hqyj_control_humi();
        if(apsensor.als<15)
        {
            AW2013_Control_RGB(50,50,50);
        }
        else{
            AW2013_Control_RGB(50,0,0);
        }
        k++;
        printf("%d\n",k);
        if(!(k%2))
        {
            signal++;
            printf("%d\n",signal);
            while(signal==15)
            {
                return signal;
            }
        }
        
        if(hqyj_person().ps<310)
        {
            return signal;
        }
    }

}

//模拟红绿灯
void hqyj_control_hld()
{
    while(1)
    {
        AW2013_Control_RGB(0,50,0);//绿灯亮，如果有行人，风扇转
        SSD1306_ShowStr(1,0,"Green ON    ",8);
        SSD1306_ShowStr(0,1,"                 ",8);
        SSD1306_ShowStr(0,2,"                 ",8);
        SSD1306_ShowStr(0,4,"                     ",8);
        SSD1306_ShowStr(0,5,"                 ",8);
        SSD1306_ShowStr(0,6,"                     ",8);
        signal_time=0;
        while(signal_time<15)
        {
            if(signal_time==10)
            {
                signal_time=hqyj_beep_green(signal_time);
            }
            if(hqyj_person().ps>310)
            {
                set_buzzer(0);
                set_fan(1);
                set_led(0);
                SSD1306_ShowStr(0,1,"Person acrossing",8);
                SSD1306_ShowStr(0,2,"fan working",8);
            }else{
                set_fan(0);
                SSD1306_ShowStr(0,1,"                 ",8);
                SSD1306_ShowStr(0,2,"                 ",8);
            }            
            hqyj_control_humi();

            if(apsensor.als<15)
            {
                AW2013_Control_RGB(50,50,50);
            }else{
                AW2013_Control_RGB(0,50,0);
            }
            usleep(MS(1000));
            signal_time++;
        }
        
        
        AW2013_Control_RGB(50,50,0);//黄灯,如果有行人，led亮
        SSD1306_ShowStr(1,0,"Yellow ON    ",8);
        SSD1306_ShowStr(0,1,"                 ",8);
        SSD1306_ShowStr(0,2,"                 ",8);
        SSD1306_ShowStr(0,4,"                     ",8);
        SSD1306_ShowStr(0,5,"Please slow down!",8);
        SSD1306_ShowStr(0,6,"                     ",8);
        signal_time=0;
        hqyj_control_yellow(signal_time);


        AW2013_Control_RGB(50,0,0);//红灯,如果有行人，蜂鸣器响
        SSD1306_ShowStr(1,0,"Red ON    ",8);
        SSD1306_ShowStr(0,1,"                 ",8);
        SSD1306_ShowStr(0,2,"                 ",8);
        SSD1306_ShowStr(0,4,"                     ",8);
        SSD1306_ShowStr(0,5,"                 ",8);
        SSD1306_ShowStr(0,6,"                     ",8);
        signal_time=0;
        while(signal_time<15)
        {
           if(hqyj_person().ps>310)
        {
            set_fan(0);
            signal_time=hqyj_beep_instep(signal_time);
            set_led(0);
        }else{
                set_buzzer(0);
                SSD1306_ShowStr(0,1,"                 ",8);
                SSD1306_ShowStr(0,2,"                 ",8);
            } 
            hqyj_control_humi();
            if(apsensor.als<15)
            {
                AW2013_Control_RGB(50,50,50);
            }else{
                AW2013_Control_RGB(50,0,0);
            }
            
            usleep(MS(1000));
            signal_time++;
        }  
    }
}

//初始化外设
void hqyj_dev()
{
    set_led(0);
    set_buzzer(0);
    set_fan(0);
}

//主函数
void mytest(void)
{
    SHT20_Init();//初始化温湿度传感器,需要检测湿度来判断是否下雨
    AP3216C_Init();//初始化红外光感接近传感器，需要通过接近传感器判断行人，通过光照传感器判断天气变化来控制红路灯亮度
    AW2013_Init();//初始化红绿灯
    PCF8574_Init();//初始化外设，红绿黄灯时来行人改变外设状态
    hqyj_dev();//初始化外设
    hqyj_oled_init(); //oled屏幕相关初始化操作

    hqyj_control_hld();

    while (1)
    {
        usleep(MS(1000));
    }
}

SYS_RUN(mytest);