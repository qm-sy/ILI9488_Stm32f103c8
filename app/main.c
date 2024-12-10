/*
 * ������������Ӳ�������������չ����Ӳ�����Ϲ���ȫ����Դ
 * �����������www.lckfb.com
 * ����֧�ֳ�פ��̳���κμ������⻶ӭ��ʱ����ѧϰ
 * ������̳��https://oshwhub.com/forum
 * ��עbilibili�˺ţ������������塿���������ǵ����¶�̬��
 * ��������׬Ǯ���������й�����ʦΪ����
 * Change Logs:
 * Date           Author       Notes
 * 2024-03-28     LCKFB-LP    first version
 */
#include "stm32f10x.h"
#include "board.h"
#include "bsp_uart.h"
#include "stdio.h"
#include "Lcd.h"
#include "gui.h"
#include "test.h"
#include "spi.h"
#include "touch.h"

int main(void)
{
	
	board_init();
	
	uart1_init(115200);
	
    LCD_Init();   //Һ������ʼ��

    while(1)
    {
        main_test();            //����������
        Test_Color();           //��ˢ��������
        Test_FillRec();         //GUI���λ�ͼ����
        Test_Circle();          //GUI��Բ����
        Test_Triangle();            //GUI�����λ�ͼ����
        English_Font_test();        //Ӣ������ʾ������
        Chinese_Font_test();        //��������ʾ������
        Pic_test();             //ͼƬ��ʾʾ������
        Rotate_Test();                   //��ת��ʾ����
        //����������������߲���Ҫ�������ܣ���ע�͵����津����������
        //Touch_Test();           //��������д����  
    }
	
}
