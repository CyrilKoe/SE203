#ifndef UART_H
#define UART_H

#include "./CMSIS/Device/ST/STM32L4xx/Include/stm32l475xx.h"
#include "./CMSIS/Device/ST/STM32L4xx/Include/stm32l4xx.h"

void uart_init();
void uart_putchar(uint8_t c);

#endif