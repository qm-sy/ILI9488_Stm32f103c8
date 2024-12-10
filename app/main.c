/*
 * 立创开发板软硬件资料与相关扩展板软硬件资料官网全部开源
 * 开发板官网：www.lckfb.com
 * 技术支持常驻论坛，任何技术问题欢迎随时交流学习
 * 立创论坛：https://oshwhub.com/forum
 * 关注bilibili账号：【立创开发板】，掌握我们的最新动态！
 * 不靠卖板赚钱，以培养中国工程师为己任
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
	
    LCD_Init();   //液晶屏初始化

    while(1)
    {
        main_test();            //测试主界面
        Test_Color();           //简单刷屏填充测试
        Test_FillRec();         //GUI矩形绘图测试
        Test_Circle();          //GUI画圆测试
        Test_Triangle();            //GUI三角形绘图测试
        English_Font_test();        //英文字体示例测试
        Chinese_Font_test();        //中文字体示例测试
        Pic_test();             //图片显示示例测试
        Rotate_Test();                   //旋转显示测试
        //如果不带触摸，或者不需要触摸功能，请注释掉下面触摸屏测试项
        //Touch_Test();           //触摸屏手写测试  
    }
	
}
