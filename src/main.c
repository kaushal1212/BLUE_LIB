
#include "stm32f10x.h"
#include "gpio.h"
#include "delay.h"

int main(){

       DelayInit();
	GPIO_Initialize(GPIOA,6,OUTPUT,PUSHPULL);

	while(1){

		GPIO_Set(GPIOA,6);

		delay_us(10);

		GPIO_Reset(GPIOA,6);

		delay_us(10);
	}

	return 0;
}
