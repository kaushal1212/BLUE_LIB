/*
 * @file  <spi.h>
 * @brief <header file for declaration & Documantation of functions and MACROs of spi.c>
 *
 *  This implementation file provides declaration for functions to initialize, read
 *  and write SPI for stm32f10xx microcontrollers
 *
 * @author <Kaushal dekivadia>
 * @date   <sept 13 2021>
 *
 */

#ifndef __SPI_H
#define __SPI_H

#include <stdint.h>
#include "stm32f10x.h"
#include "gpio.h"

#define MASTER 0U
#define SLAVE 1U

#define MSB 2U
#define LSB 3U


#define SPI_NSS_ON(SPIx) ( (SPIx == SPI1) ? (GPIO_Reset(GPIOA,4)) : (GPIO_Reset(GPIOB,12))) 

#define SPI_NSS_OFF(SPIx) ( (SPIx == SPI1) ? (GPIO_Set(GPIOA,4)) : (GPIO_Set(GPIOB,12))) 


extern void SPI_Init(SPI_TypeDef *SPIx , uint8_t mode , uint8_t c_pol , uint8_t c_phase, uint8_t first_tr_bit,uint8_t size_data);


extern void SPI_Set_Clk_Prescaler(SPI_TypeDef *SPIx,uint32_t prescaler);

extern uint16_t SPI_SendByte(SPI_TypeDef *SPIx , uint16_t data);

extern void SPI_WriteReg(SPI_TypeDef *SPIx,uint16_t address , uint16_t value);

extern uint16_t SPI_ReadReg(SPI_TypeDef* SPIx,uint16_t address);



 #endif