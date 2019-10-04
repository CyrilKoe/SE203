#ifndef LED_H
#define LED_H

typedef enum led_state {LED_OFF, LED_YELLOW,LED_BLUE} led_state;


void led_init();
void led_on();
void led_off();
void led(led_state);

#endif
