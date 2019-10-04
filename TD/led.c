#include <stdint.h>
#include "led.h"
#include "GPIO.h"


/* Active l'horloge du bloc GPIO B
(Place dans le registre RCC_AHB2ENR la valeur 1 au bit 1 (GPIOBEN))
Puis du bloc GPIO C (bit 2)
Met la broche 15 du bloc GPIO B en mode sortie
*/
void led_init() {
  RCC_AHB2ENR |= (1 << 1);
  RCC_AHB2ENR |= (1 << 2);
  GPIOB_MODER &= ~(0b11<<(14*2));
  GPIOB_MODER |= (0b01<<(14*2));
}

// Place le bit 1 sur la partie SET de la Led 2 (PB14)
void led_on() {
  GPIOB_BSRR = (1<<14);
}

// Place le bit 1 sur la partie RESET de la Led 2 (PB14)
void led_off() {
  GPIOB_BSRR = (1<<14) << 16;
}

/* Change l'était des leds 3 et 4
en modifiant le mode d'utilisation et la valeur sortie en PC9
Rq : Il y a un scintillement d'un cycle avec cette implémentation,
est ce problématique?
*/
void led(led_state state) {
  GPIOC_MODER &= ~(0b11<<(9*2));
  switch(state){
    case LED_YELLOW:
      GPIOC_MODER |= (0b01<<(9*2));
      GPIOC_BSRR = (1<<9);
      break;
    case LED_BLUE:
      GPIOC_MODER |= (0b01<<(9*2));
      GPIOC_BSRR = (1<<9)<<16;
      break;
    case LED_OFF:
      break;
  }
}
