#ifndef GPIO_H
#define GPIO_H

#define RCC_AHB2ENR (*(volatile uint32_t *) 0x4002104C)

#define GPIOB_MODER (*(volatile uint32_t *) 0x48000400)
#define GPIOB_BSRR (*(volatile uint32_t *) 0x48000418)
#define GPIOB_ODR (*(volatile uint32_t *) 0x48000414)

#define GPIOC_MODER (*(volatile uint32_t *) 0x48000800)
#define GPIOC_BSRR (*(volatile uint32_t *) 0x48000818)
#define GPIOC_ODR (*(volatile uint32_t *) 0x48000814)

#endif
