#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


//UART���ڷ�����Ϣ
void UART_Init(void)
{
	//1.��GPA1_0��GPA1_1���ó�UART2�Ľ������źͷ������� GPA1CON[7:0]
	GPA1.CON = GPA1.CON & (~(0xFF << 0)) | (0x22 << 0);
	//2.����UART2��֡��ʽ 8λ����λ 1λֹͣλ ��У��λ ����ģʽ ULCON2
	UART2.ULCON2 = UART2.ULCON2 & (~(0x7F << 0)) | (0x3 << 0);
	//����UART2�Ľ��պͷ���ģʽΪ��ѯģʽ UCON2[3:0]
	UART2.UCON2 = UART2.UCON2 & (~(0xF << 0)) | (0x5 << 0);
	//����UART2�Ĳ�����Ϊ115200  UBRDIV2/UFRACVAL2
	UART2.UBRDIV2 = 53;
	UART2.UFRACVAL2 = 4;
}


char UART_Rec_Byte(void)
{
	char Dat = 0;
	//�жϽ��ռĴ����Ƿ���յ�����
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
	////�ȴ����ͼĴ����Ĵ���Ϊ��
	//while (!(UART2.UTRSTAT2 & (1 << 1)));
	////�����͵�����д�뷢�ͼĴ���URXH2
	//UART2.UTXH2 = Dat;

	while (*pstr != '\0')
		UART_Send_Byte(*pstr++);
}

char UART_Rec_Byte(void)
{
	char Dat = 0;
	//�жϽ������Ĵ����Ƿ���յ�����
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