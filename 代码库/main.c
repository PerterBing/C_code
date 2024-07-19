#include "stm32f10x.h"                  // Device header

void delay_ms(u16 time)
{    
   u16 i=0;  
   while(time--)
   {
      i=12000;  //自己定义
      while(i--) ;    
   }
}

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	//配置端口模式
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	int i=0;
	while(1)
	{
		GPIO_SetBits(GPIOC,GPIO_Pin_13);//置高电平
		delay_ms(500);
//		GPIO_ResetBits(GPIOC,GPIO_Pin_13);//置低电平
//		delay_ms(500);
	}
	while(1)
	{
		
	}
}
