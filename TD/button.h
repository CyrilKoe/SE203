#ifndef BUTTON_H
#define BUTTON_H

#include "./CMSIS/Device/ST/STM32L4xx/Include/stm32l475xx.h"
#include "./CMSIS/Device/ST/STM32L4xx/Include/stm32l4xx.h"
#include "led.h"
#include "irq.h"

void button_init(void);
void EXTI4_IRQHandler(void);

#endif
