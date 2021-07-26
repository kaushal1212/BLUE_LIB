/******************************************************************************
 * Copyright (C) 2021 by Kaushal - BVM engineering college
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. . 
 *
 *****************************************************************************/
/**
 * @file  <gpio.h>
 * @brief <header file for declaration & Documantation of functions and MACROs of gpio.c>
 *
 * This implementation file provides declaration   of initialization, set
 * reset and read GPIO functions for stm32f103xx platform.
 *
 * @author <Kaushal dekivadia>
 * @date   <june 22 2021>
 *
 */
 

#ifndef __GPIO_H
#define __GPIO_H

#include <stdint.h>
#include "stm32f10x.h"


 #define OUTPUT 1U
 #define INPUT  0U

 #define PUSHPULL    0U
 #define OPENDRAIN   1U
 #define FLOATING    2U
 #define PULL_UP     3U
 #define AF_PUSHPULL 4U
 #define ANALOG      5U

/**
 * @brief function to initialize GPIO MODES.
 *  
 * @param GPIOx     - Port of GPIO
 * @param pin       - pin number of GPIO
 * @param GPIO_MODE - MODE of GPIO :- OUTPUT/INPUT
 * @param GPIO_CNF  - Configuration of GPIO    
 *      
 * This function initialize diffrent GPIO modes as below
 *    
 *    1.GPIO_MODE = OUTPUT , GPIO_CNF = PUSHPULL
 *    2.GPIO_MODE = OUTPUT , GPIO_CNF = OPENDRAIN
 *    3.GPIO_MODE = OUTPUT , GPIO_CNF = AF_PUSHPULL
 *    4.GPIO_MODE = INPUT  , GPIO_CNF = FLOATING
 *    5.GPIO_MODE = INPUT  , GPIO_CNF = PULL_UP
 *    6.GPIO_MODE = INPUT  , GPIO_CNF = ANALOG
 *    
 * @return void
 */

extern void GPIO_Initialize (GPIO_TypeDef *GPIOx , uint8_t pin , uint8_t GPIO_MODE , uint8_t GPIO_CNF );



/**
 * @brief function to set GPIO pin( BSSR register bit)
 * 
 * @param GPIOx - Port of GPIO
 * @param pin   - pin of GPIO
 
 * @return void
 */

extern void GPIO_Set (GPIO_TypeDef *GPIOx , uint8_t pin);



/**
 * @brief function to reset GPIO pin( BRR register bit)
 * 
 * @param GPIOx - Port of GPIO
 * @param pin   - pin of GPIO
 
 * @return void
 */

 extern void GPIO_Reset (GPIO_TypeDef *GPIOx , uint8_t pin);




/**
 * @brief function to read GPIO input bit (IDR register bit)
 * 
 * @param GPIOx - Port of GPIO
 * @param pin   - pin of GPIO
 * 
 * @return 0 -> GPIO IDR bit is 0
 * @return 1 -> GPIO IDR bit is 1
 */

 extern uint8_t GPIO_Read(GPIO_TypeDef *GPIOx , uint8_t pin);

 /**
 * @brief function to read GPIO input bit (IDR register bit)
 * 
 * @param GPIOx - Port of GPIO
 * @param pin   - pin of GPIO
 * @param value - value of bit to be wriiten ( 0 or 1)
 * 
 * @return void
 */


 extern void GPIO_Write(GPIO_TypeDef *GPIOx , uint8_t pin, uint8_t value);

#endif