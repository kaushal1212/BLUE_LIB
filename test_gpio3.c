
#include "stm32f10x.h"
#include "gpio.h"
#include "delay.h"


int main(){

	uint8_t value = 0;
	Delay_Init();
	GPIO_Init(GPIOC,15,OUTPUT,PUSHPULL);
	GPIO_Init(GPIOA,5,INPUT,PULL_UP);

	while(1){
		value = GPIO_Read(GPIOA,5);

		GPIO_Write(GPIOC,15,value);
	}

	return 0;
}