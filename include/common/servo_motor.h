#ifndef __SERVO_H
#define __SERVO_H

#include <stdint.h>
#include "stm32f10x.h"

#define ARR_VAL 1000U


/**
 * @brief Function to Initialize servo and set at 0 angle
 * 
 * @param GPIOx - Port of GPIO
 * @param pin - Pin of GPIO
 */
void Servo_Init(GPIO_TypeDef *GPIOx,uint8_t pin);


/**
 * @brief Function to set servo angle
 * 
 * @param GPIOx - Port of GPIO
 * @param pin - Pin of GPIO
 * @param angle - angle of servo shaft
 */
void Servo_Angle(GPIO_TypeDef *GPIOx,uint8_t pin,uint8_t angle);

#endif
