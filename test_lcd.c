/**
 * @file   <test_lcd.c>
 * @brief  <test file for basic LCD functions>
 * 	    
 * 	    displays some line on LCD using HAL functions
 *
 * @author <Kaushal dekivadia>
 * @date   <August 10 2021>
 *
 */
#include "stm32f10x.h"
#include "gpio.h"
#include "delay.h"
#include "lcd_16x2.h"
#include <stdio.h>


int main(){

	LCD_Init();

	
     
	while(1){

			LCD_Clear();
			LCD_Print_Line("SUBJECT :4EL31");
			Delay_ms(3000);

			LCD_Clear();
			LCD_Print_Line("PROJECT TITLE :");
			LCD_Setcursor(1,2);
			LCD_Print_Line("BLUE-LIB");
			Delay_ms(3000);

			LCD_Clear();
			LCD_Print_Line("TEST:           LCD APIs");
			Delay_ms(3000);
	}

	return 0;
}


