
/**
 * @file   <delay.c>
 * @brief  <Abstraction of SysTick_init , Delay_ms and Delay_us functions >
 *
 * @author <Kaushal dekivadia>
 * @date   <mar 8 2021>
 *
 */



#include <stdint.h>
#include "delay.h"
#include "delay.h"

// For store tick counts in us
static __IO uint32_t usTicks;

// SysTick_Handler function will be called every 1 us
void SysTick_Handler()
{
    if (usTicks != 0)
    {
        usTicks--;
    }
}

void DelayInit()
{
    // Update SystemCoreClock value
    SystemCoreClockUpdate();
    // Configure the SysTick timer to overflow every 1 us
    SysTick_Config(SystemCoreClock / 1000000);
}

void delay_us(uint32_t us)
{
    // Reload us value
    usTicks = us;
    // Wait until usTick reach zero
    while (usTicks);
}

void delay_ms(uint32_t ms)
{
    // Wait until ms reach zero
    while (ms--)
    {
        // Delay 1ms
        delay_us(1000);
    }
}
