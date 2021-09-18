/**
 * @file   <test_gpio1.c>
 * @brief  <test file for basic gpio and delay function>
 * 	    
 * 	     OUTPUT-blinking led every 1s
 *
 * @author <Kaushal dekivadia>
 * @date   <july 29 2021>
 *
 */

#include "stm32f10x.h"
#include "gpio.h"
#include "delay.h"

int main(){

	 // Initialization of Delay (Systick (timer) configuration)
	GPIO_Init(GPIOB,8,OUTPUT,PUSHPULL); //Initialization of GPIO - A5 for output pushpull mode

	// infinite loop..

	while(1){

		GPIO_Set(GPIOB,8);  // set A5 GPIO value to HIGH
		Delay_ms(1);	// delay of 1s
		GPIO_Reset(GPIOB,8);  // set A5 GPIO value to LOW
		Delay_ms(1);	// delay of 1s
	}


	return 0;
}