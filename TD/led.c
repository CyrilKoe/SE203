#include <stdint.h>
#include "GPIO.h"


/* Active l'horloge du bloc GPIO B
(Place dans le registre RCC_AHB2ENR la valeur 1 au bit 1 (GPIOBEN))
Puis du bloc GPIO C (bit 2)
Met la broche 15 du bloc GPIO B en mode sortie
*/
void led_init() {
  RCC_AHB2ENR |= (1 << 1);
  RCC_AHB2ENR |= (1 << 2);
  GPIOB_MODER &= ~(0b11<<28);
  GPIOB_MODER |= (0b01<<28);
}

// Place le bit 1 sur la partie SET
void led_on() {
  GPIOB_BSRR = (1<<14);
}

// Place le bit 1 sur la partie RESET
void led_off() {
  GPIOB_BSRR = (1<<14) << 16;
}
