#ifndef LED_H
#define LED_H

#include "./CMSIS/Device/ST/STM32L4xx/Include/stm32l475xx.h"
#include <stdint.h>

typedef enum led_state {LED_OFF, LED_YELLOW,LED_BLUE} led_state;


void led_init();
void led_on();
void led_off();
void led_toggle();
void led(led_state);

#endif
