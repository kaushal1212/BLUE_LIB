
#include "stm32f10x.h"
#include "gpio.h"
#include "delay.h"
#include "spi.h"

int main(){

	Delay_Init();
	SPI_Init(SPI1,MASTER,0,0,MSB,8);



	while(1){
		SPI_WriteReg(SPI1,0x33,0XAA);
		Delay_us(1);


		SPI_WriteReg(SPI1,0x54,0X34);
		Delay_us(1);
			
		SPI_WriteReg(SPI1,0x16,0X40);
		Delay_us(1);
	}

	return 0;
}