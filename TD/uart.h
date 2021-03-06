#ifndef UART_H
#define UART_H

#include "./CMSIS/Device/ST/STM32L4xx/Include/stm32l475xx.h"
#include "./CMSIS/Device/ST/STM32L4xx/Include/stm32l4xx.h"
#include <stddef.h>
#include "image.h"

void uart_init();
void uart_putchar(uint8_t c);
uint8_t uart_getchar();
void uart_puts(const uint8_t *s);
void uart_gets(uint8_t *s, size_t size);

extern rgb_color my_image[8][8];

#endif