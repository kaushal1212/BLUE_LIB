/******************************************************************************
 * Copyright (C) 2021 by Kaushal - BVM engineering college
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. . 
 *
 *****************************************************************************/
/**
 * @file   <gpio.c>
 * @brief  <Abstraction of GPIO initialization, bit_set, bit_reset, bit_write, bit_read operations>
 *
 * This implementation file provides an abstraction of initialization, set
 * reset and read GPIO registers for stm32f103xx platform.
 *
 * @author <Kaushal dekivadia>
 * @date   <june 22 2021>
 *
 */


#include <stdint.h>
#include "gpio.h"
#include "stm32f10x.h"

void GPIO_Initialize(GPIO_TypeDef *GPIOx , uint8_t pin , uint8_t GPIO_MODE , uint8_t GPIO_CNF )
{
    if (GPIOx == GPIOA)
            RCC->APB2ENR |= RCC_APB2ENR_IOPAEN ;

    else if (GPIOx == GPIOB)
            RCC->APB2ENR |= RCC_APB2ENR_IOPBEN ;

    else if (GPIOx == GPIOC)
            RCC->APB2ENR |= RCC_APB2ENR_IOPCEN ;

    else if (GPIOx == GPIOD)
            RCC->APB2ENR |= RCC_APB2ENR_IOPDEN ;

     //--- GPIO conf = pushpull output ---------------------------------------
    if((pin <= 7)&&(GPIO_MODE == OUTPUT )&&(GPIO_CNF == PUSHPULL))
    {
         GPIOx->CRL |= (3<<(4*pin));
         GPIOx->CRL &= ~(12<<(4*pin));
    }

    else if((pin > 7)&&(GPIO_MODE == OUTPUT )&&(GPIO_CNF == PUSHPULL))
    {    
         pin = pin - 8;
         GPIOx->CRH |= (3<<(4*pin));
         GPIOx->CRH &= ~(12<<(4*pin));
    }

     //--- GPIO conf = opendrain output ---------------------------------------
    else if((pin <= 7)&&(GPIO_MODE == OUTPUT )&&(GPIO_CNF == OPENDRAIN))
    {    
         GPIOx->CRL |= (7<<(4*pin));
         GPIOx->CRL &= ~(8<<(4*pin));
    }
    
    else if((pin > 7)&&(GPIO_MODE == OUTPUT )&&(GPIO_CNF == OPENDRAIN))
    {    
         pin = pin -8 ;      
         GPIOx->CRH |= (7<<(4*pin));
         GPIOx->CRH &= ~(8<<(4*pin));
    }

    
     //--- GPIO conf = floating input ---------------------------------------
    else if((pin <= 7)&&(GPIO_MODE == INPUT )&&(GPIO_CNF == FLOATING ))
    {
        GPIOx->CRL |= (4<<(4*pin));
        GPIOx->CRL &= ~(8<<(4*pin)); 
    }
    
    else if((pin > 7)&&(GPIO_MODE == INPUT )&&(GPIO_CNF == FLOATING ))
    {   
        pin = pin - 8;
        GPIOx->CRH |= (4<<(4*pin));
        GPIOx->CRH &= ~(8<<(4*pin)); 
    }


     //--- GPIO conf = altenate function pushpull ---------------------------------------

    else if((pin <= 7)&&(GPIO_MODE == OUTPUT )&&(GPIO_CNF == AF_PUSHPULL ))
    {
        GPIOx->CRL |= (11<<(4*pin));
        GPIOx->CRL &= ~(4<<(4*pin)); 
    }
    
    else if((pin > 7)&&(GPIO_MODE == INPUT )&&(GPIO_CNF == AF_PUSHPULL ))
    {   
        pin = pin - 8;
        GPIOx->CRH |= (11<<(4*pin));
        GPIOx->CRH &= ~(4<<(4*pin));  
    }
     //--- GPIO conf = input pull-up ---------------------------------------

    else if((pin <= 7)&&(GPIO_MODE == INPUT )&&(GPIO_CNF == PULL_UP))
    {    
        GPIOx->CRL |= (8<<(4*pin));
        GPIOx->CRL &= ~(7<<(4*pin));
    }

    
    else if((pin > 7)&&(GPIO_MODE == INPUT )&&(GPIO_CNF == PULL_UP))
    {   
        pin = pin - 8;
        GPIOx->CRH |= (8<<(4*pin));
        GPIOx->CRH &= ~(7<<(4*pin));
    }

    //--- GPIO conf = input analog ---------------------------------------

    else if((pin <= 7)&&(GPIO_MODE == INPUT )&&(GPIO_CNF == ANALOG))
    {    
        GPIOx->CRL &= ~(15<<(4*pin));
    }

    
    else if((pin > 7)&&(GPIO_MODE == INPUT )&&(GPIO_CNF == ANALOG))
    {   
        pin = pin - 8;
        GPIOx->CRH &= ~(15<<(4*pin));
    }

}



void GPIO_Set (GPIO_TypeDef *GPIOx , uint8_t pin)
{

    GPIOx->BSRR |= (1<<pin);
}

void GPIO_Reset (GPIO_TypeDef *GPIOx , uint8_t pin)
{
    GPIOx->BRR |= (1<<pin);
}

uint8_t GPIO_Read(GPIO_TypeDef *GPIOx , uint8_t pin)
{
    if(GPIOx->IDR & (1 << pin ))
        return 1;
     else
        return 0;
}


void GPIO_Write(GPIO_TypeDef *GPIOx , uint8_t pin, uint8_t value)
{
    if(value == 1)
      GPIOx->BSRR |= (1<<pin);
    
    if(value == 0)
      GPIOx->BRR |= (1<<pin);
    
}