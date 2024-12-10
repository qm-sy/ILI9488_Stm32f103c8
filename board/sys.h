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
 
#ifndef __SYS_H__
#define __SYS_H__
 
#include "stm32f10x.h"

#define BIT_ADDR(Addr, Bit_Num) 		*((volatile uint32_t *)(0x42000000 + ((Addr - 0x40000000) * 32) + (Bit_Num * 4)))


#define GPIOA_ODR_ADDR    (GPIOA_BASE+12) //0x40000000 + 0x10000 + 0x0800 + 0x0C
#define GPIOB_ODR_ADDR    (GPIOB_BASE+12) //0x40000000 + 0x10000 + 0x0C00 + 0x0C
#define GPIOC_ODR_ADDR    (GPIOC_BASE+12) //0x40000000 + 0x10000 + 0x1000 + 0x0C


#define GPIOA_IDR_ADDR    (GPIOA_BASE+8) //0x40000000 + 0x10000 + 0x0800 + 0x08
#define GPIOB_IDR_ADDR    (GPIOB_BASE+8) //0x40000000 + 0x10000 + 0x0C00 + 0x08
#define GPIOC_IDR_ADDR    (GPIOC_BASE+8) //0x40000000 + 0x10000 + 0x1000 + 0x08


#define PAout(Pin)	BIT_ADDR(GPIOA_ODR_ADDR, Pin) // GPIOA���
#define PBout(Pin)	BIT_ADDR(GPIOB_ODR_ADDR, Pin) // GPIOB���
#define PCout(Pin)	BIT_ADDR(GPIOC_ODR_ADDR, Pin) // GPIOC���

#define PAin(Pin)	BIT_ADDR(GPIOA_IDR_ADDR, Pin) // GPIOA����
#define PBin(Pin)	BIT_ADDR(GPIOB_IDR_ADDR, Pin) // GPIOB����
#define PCin(Pin)	BIT_ADDR(GPIOC_IDR_ADDR, Pin) // GPIOC����

#endif
