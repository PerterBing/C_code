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
    ON,//����0
    OFF,//����1
}io_sw;
uint8_t iodata;


//�򴫸����������ݵĺ���
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

//��������ʼ��
void hqyj_sht20_init()
{
    //1.IO���Ź��ܵĸ���
    hi_io_set_func(HI_IO_NAME_GPIO_9, HI_IO_FUNC_GPIO_9_I2C0_SCL);
    hi_io_set_func(HI_IO_NAME_GPIO_10, HI_IO_FUNC_GPIO_10_I2C0_SDA);
    //������������
    hi_io_set_pull(HI_IO_NAME_GPIO_9, HI_IO_PULL_UP);
    hi_io_set_func(HI_IO_NAME_GPIO_10, HI_IO_PULL_UP);
    //i2c��ʼ��
    hi_i2c_init(HI_I2C_IDX_0, 100000);
    //�򴫸�������0xFE������λ
    hqyj_sht20_write(0xFE);
    //����15ms�ȴ���������λ���
    usleep(MS(20));
}

//��sht20�������ݺ���
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
    //1.���Ͳ����¶�ָ��
    hqyj_sht20_write(0xF3);
    //2.���ߵȴ��������
    usleep(MS(100));
    //3.��ȡ�¶�����
    hqyj_sht20_read(rcv_buf);
    //�Զ��������ݽ��н���
    *temp = ((((rcv_buf[0] << 8) | rcv_buf[1]) / 65536.0) * 175.72) - 46.85;
    //ʪ�����ݵĻ�ȡ
    //1.���Ͳ���ʪ�ȵ�ָ��
    hqyj_sht20_write(0xF5);
    //2.���ߵȴ�ʪ�Ȳ������
    usleep(MS(40));
    //3.��ȡʪ������
    hqyj_sht20_read(rcv_buf);
    //4.�Խ��յ���ʪ�ȵ����ݽ��н���
    *humi = ((((rcv_buf[0] << 8) | rcv_buf[1]) / 65536.0) * 125.0) - 6.0;
}

//���Ʒ������ĺ���
void hqyj_control_beep(int sw)
{
    if (sw == OFF)
    {
        //2.���Ʒ�������
        iodata = iodata | (1 << 1);
    }
    else if (sw == ON)
    {
        //2.���Ʒ�������
        iodata = iodata & (~(1 << 1));
    }
    PCF8574_Write(iodata);
}

void hqyj_control_led(io_sw sw)//p3�ڽӵ͵�ƽ��ͨ
{
    if (sw == OFF)
    {
        //2.���Ƶ�����
        iodata = iodata | (1 << 2);
    }
    else if (sw == ON)
    {
        //2.���Ƶ���
        iodata = iodata & (~(1 << 2));
    }
    PCF8574_Write(iodata);
}

//�¶ȳ�����ֵ����������,ʪ�ȳ�����ֵ��LED����
void hqyj_temp_thr()
{
    float temp = 0, humi = 0;
    while (1)
    {
        hqyj_read_temp_humi(&temp, &humi);
        //%.2f�ǿ��ƴ�ӡ��ʽ��ֻ��ӡС�������λ
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

    //1.��������ʼ��
    PCF8574_Init();
    hqyj_sht20_init();
    hqyj_temp_thr();
    while (1)
    {
        usleep(50000);
    }

}
SYS_RUN(mytest);