#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


//UART串口发送信息
void UART_Init(void)
{
	//1.将GPA1_0和GPA1_1设置成UART2的接收引脚和发送引脚 GPA1CON[7:0]
	GPA1.CON = GPA1.CON & (~(0xFF << 0)) | (0x22 << 0);
	//2.设置UART2的帧格式 8位数据位 1位停止位 无校验位 正常模式 ULCON2
	UART2.ULCON2 = UART2.ULCON2 & (~(0x7F << 0)) | (0x3 << 0);
	//设置UART2的接收和发送模式为轮询模式 UCON2[3:0]
	UART2.UCON2 = UART2.UCON2 & (~(0xF << 0)) | (0x5 << 0);
	//设置UART2的波特率为115200  UBRDIV2/UFRACVAL2
	UART2.UBRDIV2 = 53;
	UART2.UFRACVAL2 = 4;
}


char UART_Rec_Byte(void)
{
	char Dat = 0;
	//判断接收寄存器是否接收到数据
	if (UART.UTRSTAT2 & 1)
	{
		Dat = UART.URXH2;
		return Dat;
	}
	else
	{
		return 0;
	}

void UART_Send_Str(char* pstr)
{
	////等待发送寄存器寄存器为空
	//while (!(UART2.UTRSTAT2 & (1 << 1)));
	////将发送的数据写入发送寄存器URXH2
	//UART2.UTXH2 = Dat;

	while (*pstr != '\0')
		UART_Send_Byte(*pstr++);
}

char UART_Rec_Byte(void)
{
	char Dat = 0;
	//判断接收器寄存器是否接收到数据
	if (UART2.UTRSTAT2 & 1)
	{
		Dat = UART2.UARXH2;
		return Dat;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char RecDat = 0;
	UART_Init();

	while (1)
	{
		//RecDat = UART_Byte();
		//if (RecDat == 0)
		//{

		//}
		//else
		//{
		//	RecDat = RecDat + 1;
		//	UART_Send_Byte(RecDat);

		UART_Send_Str("Hello World\n");
		}
	}
	return 0;
}