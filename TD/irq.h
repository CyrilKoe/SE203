#ifndef IRQ_H
#define IRQ_H

#include <stdint.h>
#include "./CMSIS/Device/ST/STM32L4xx/Include/stm32l475xx.h"

void irq_init(void);
void default_handler(void);

#endif  //IRQ_H