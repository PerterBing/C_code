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
#define MS(sec) (sec*1000)
#define SHT20_SLA_ADDR 0x80
typedef enum IO_sw {
    ON,//代表0
    OFF,//代表1
}io_sw;
uint8_t iodata;


//向传感器发送数据的函数
void hqyj_sht20_write(uint8_t data)
{
    int ret = 0;
    hi_i2c_data i2c_data;
    i2c_data.send_buf = &data;
    i2c_data.send_len = sizeof(data);
    ret = hi_i2c_write(HI_I2C_IDX_0, SHT20_SLA_ADDR, &i2c_data);
    if (ret != 0)
    {
        printf("hi_i2c_read error ret:%#x\n", ret);
    }
}

//传感器初始化
void hqyj_sht20_init()
{
    //1.IO引脚功能的复用
    hi_io_set_func(HI_IO_NAME_GPIO_9, HI_IO_FUNC_GPIO_9_I2C0_SCL);
    hi_io_set_func(HI_IO_NAME_GPIO_10, HI_IO_FUNC_GPIO_10_I2C0_SDA);
    //设置引脚上拉
    hi_io_set_pull(HI_IO_NAME_GPIO_9, HI_IO_PULL_UP);
    hi_io_set_func(HI_IO_NAME_GPIO_10, HI_IO_PULL_UP);
    //i2c初始化
    hi_i2c_init(HI_I2C_IDX_0, 100000);
    //向传感器发送0xFE进行软复位
    hqyj_sht20_write(0xFE);
    //休眠15ms等待传感器软复位完毕
    usleep(MS(20));
}

//从sht20接收数据函数
void hqyj_sht20_read(uint8_t* buf)
{
    int ret = 0;
    hi_i2c_data i2c_data;
    i2c_data.receive_buf = buf;
    i2c_data.receive_len = 3;
    ret = hi_i2c_read(HI_I2C_IDX_0, SHT20_I2C_ADDR, &i2c_data);
    if (ret != 0)
    {
        printf("hi_i2c_read error ret:%#x\n", ret);
    }
}

void hqyj_read_temp_humi(float* temp, float* humi)
{
    uint8_t rcv_buf[3] = { 0 };
    //1.发送测量温度指令
    hqyj_sht20_write(0xF3);
    //2.休眠等待测量完毕
    usleep(MS(100));
    //3.读取温度数据
    hqyj_sht20_read(rcv_buf);
    //对读到的数据进行解析
    *temp = ((((rcv_buf[0] << 8) | rcv_buf[1]) / 65536.0) * 175.72) - 46.85;
    //湿度数据的获取
    //1.发送测量湿度的指令
    hqyj_sht20_write(0xF5);
    //2.休眠等待湿度测量完毕
    usleep(MS(40));
    //3.读取湿度数据
    hqyj_sht20_read(rcv_buf);
    //4.对接收到的湿度的数据进行解析
    *humi = ((((rcv_buf[0] << 8) | rcv_buf[1]) / 65536.0) * 125.0) - 6.0;
}

//控制蜂鸣器的函数
void hqyj_control_beep(int sw)
{
    if (sw == OFF)
    {
        //2.控制蜂鸣器关
        iodata = iodata | (1 << 1);
    }
    else if (sw == ON)
    {
        //2.控制蜂鸣器开
        iodata = iodata & (~(1 << 1));
    }
    PCF8574_Write(iodata);
}

void hqyj_control_led(io_sw sw)//p3口接低电平导通
{
    if (sw == OFF)
    {
        //2.控制灯亮灭
        iodata = iodata | (1 << 2);
    }
    else if (sw == ON)
    {
        //2.控制灯亮
        iodata = iodata & (~(1 << 2));
    }
    PCF8574_Write(iodata);
}

//温度超过阈值，蜂鸣器响,湿度超过阈值，LED灯亮
void hqyj_temp_thr()
{
    float temp = 0, humi = 0;
    while (1)
    {
        hqyj_read_temp_humi(&temp, &humi);
        //%.2f是控制打印格式，只打印小数点后两位
        printf("temp=%.2f,humi=%.2f\n", temp, humi);
        usleep(MS(1000));
        if (temp < 31 || temp>33)
        {
            iodata = iodata & (~(1 << 1));
            PCF8574_Write(iodata);
        }
        else {
            iodata = iodata | (1 << 1);
            PCF8574_Write(iodata);
        }
        if (humi < 40 || humi>60)
        {
            iodata = iodata & (~(1 << 2));
            PCF8574_Write(iodata);
        }
        else {
            iodata = iodata | (1 << 2);
            PCF8574_Write(iodata);
        }
    }
}

void mytest(void)
{

    //1.传感器初始化
    PCF8574_Init();
    hqyj_sht20_init();
    hqyj_temp_thr();
    while (1)
    {
        usleep(50000);
    }

}
SYS_RUN(mytest);