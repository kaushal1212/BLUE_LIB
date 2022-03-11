

#include "stm32f10x.h"
#include "gpio.h"
#include "delay.h"
#include "pwm.h"
#include "servo_motor.h"

int main(){

    Servo_Init(GPIOB,6);

    while(1){

        Servo_Angle(GPIOB,6,0);
        Delay_ms(2000);
        Servo_Angle(GPIOB,6,45);
        Delay_ms(2000);
        Servo_Angle(GPIOB,6,90);
        Delay_ms(2000);
        Servo_Angle(GPIOB,6,135);
        Delay_ms(2000);
        Servo_Angle(GPIOB,6,180);
        Delay_ms(2000);
    }

}