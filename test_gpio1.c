/**
 * @file   <test_gpio1.c>
 * @brief  <test file for basic gpio and delay function>
 * 	    
 * 	     OUTPUT-blinking led every 1s in pushpull mode
 *
 * @author <Kaushal dekivadia>
 * @date   <july 29 2021>
 *
 */

#include "stm32f10x.h"
#include "gpio.h"
#include "timer_delay.h"

int main(){

	GPIO_Init(GPIOC,13,OUTPUT,PUSHPULL); //Initialization of GPIO - C13 for output pushpull mode

	// infinite loop..

	while(1){

		GPIO_Set(GPIOC,13);  // set C13 GPIO value to HIGH
		TDelay_ms(1000);	// delay of 1s
		GPIO_Reset(GPIOC,13);  // set C13 GPIO value to LOW
		TDelay_ms(1000);	// delay of 1s
	}

	return 0;
}
