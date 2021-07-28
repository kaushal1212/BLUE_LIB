/**
 * @file  <gpio.h>
 * @brief <header file for delay_init , delay_us and delay_ms functions >
 *
 *
 * @author <Kaushal dekivadia>
 * @date   <mar 2 2021>
 *
 */


#ifndef __DELAY_H
#define __DELAY_H


#include "stm32f10x.h"

void DelayInit(void);

void delay_us(uint32_t us);
void delay_ms(uint32_t ms);


#endif
