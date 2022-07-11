

 
 #include "stm32f10x.h"
 #include "gpio.h"
 #include "delay.h"


 int main(){

    Delay_Init(); /// Initialization of Delay (Systick (timer) configuration)
    GPIO_Init(GPIOB,6,OUTPUT,OPENDRAIN); // //Initialization of GPIO - B6 for output opendrain mode

    while(1){

        GPIO_Toggle(GPIOB,6); // Toggle the value of pin B6 every 1s

        Delay_ms(1000);
    }


    return 0;
 }
