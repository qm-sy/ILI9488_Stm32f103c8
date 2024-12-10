/*
 * ������������Ӳ�������������չ����Ӳ�����Ϲ���ȫ����Դ
 * �����������www.lckfb.com
 * ����֧�ֳ�פ��̳���κμ������⻶ӭ��ʱ����ѧϰ
 * ������̳��https://oshwhub.com/forum
 * ��עbilibili�˺ţ������������塿���������ǵ����¶�̬��
 * ��������׬Ǯ���������й�����ʦΪ����
 * Change Logs:
 * Date           Author       Notes
 * 2024-03-26     LCKFB-LP    first version
 */
#include "board.h"

static uint32_t systick_us = 0;
//static uint32_t systick_ms = 0;

void board_init(void)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	//ѡ���ⲿʱ��
	systick_us=SystemCoreClock/8000000;	      				//Ϊϵͳʱ�ӵ�1/8
//	systick_ms=(uint32_t)systick_us*1000;					//ÿ����SysTick��VAL������Ŀ  	
}

void delay_us(uint32_t us)
{
	uint32_t systickCount;	
	uint32_t count = us * systick_us;
	
	if(us == 1)
	{
		SysTick->LOAD=count - 8;
	}
	else
	{
		SysTick->LOAD=count -10; 	//ʱ�����
	}	
	
	SysTick->VAL=0x00;        	//��ռ�����	
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ; //��ʼ����	  
	
	do
	{
		systickCount=SysTick->CTRL;
	}while((systickCount&0x01)&&!(systickCount&(1<<16))); //�ȴ�ʱ�䵽��   
	SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk; //�رռ�����
	SysTick->VAL =0X00;       //��ռ�����		
	
}

void delay_ms(uint32_t ms){ delay_us(ms * 1000); }

void delay_1us(uint32_t us){ delay_us(us); }

void delay_1ms(uint32_t ms){ delay_us(ms * 1000); }

