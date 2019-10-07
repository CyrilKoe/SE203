#include <stdint.h>
#include "led.h"
#include "GPIO.h"
#include "./CMSIS/Device/ST/STM32L4xx/Include/stm32l475xx.h"


/* Active l'horloge du bloc GPIO B
(Place dans le registre RCC_AHB2ENR la valeur 1 au bit 1 (GPIOBEN))
Puis du bloc GPIO C (bit 2)
Met la broche 15 du bloc GPIO B en mode sortie
*/
void led_init() {
  RCC->AHB2ENR = RCC->AHB2ENR | RCC_AHB2ENR_GPIOBEN;
  RCC->AHB2ENR = RCC->AHB2ENR | RCC_AHB2ENR_GPIOCEN;
  GPIOB -> MODER = (GPIOB -> MODER & ~GPIO_MODER_MODE14_Msk) | (0b01 << GPIO_MODER_MODE14_Pos);
}

// Place le bit 1 sur la partie SET de la Led 2 (PB14)
void led_on() {
  GPIOB -> BSRR = GPIO_BSRR_BS14;
}

// Place le bit 1 sur la partie RESET de la Led 2 (PB14)
void led_off() {
  GPIOB -> BSRR = GPIO_BSRR_BR14;
}

/* Change l'était des leds 3 et 4
en modifiant le mode d'utilisation et la valeur sortie en PC9
*/
void led(led_state state) {
  switch(state){
    case LED_YELLOW:
      GPIOC -> MODER = (GPIOC -> MODER & ~GPIO_MODER_MODE9_Msk) | (0b01 << GPIO_MODER_MODE9_Pos);
      GPIOC -> BSRR = GPIO_BSRR_BS9;
      break;
    case LED_BLUE:
      GPIOC -> MODER = (GPIOC -> MODER & ~GPIO_MODER_MODE9_Msk) | (0b01 << GPIO_MODER_MODE9_Pos);
      GPIOC -> BSRR = GPIO_BSRR_BR9;
      break;
    case LED_OFF:
      GPIOC -> MODER = (GPIOC -> MODER & ~GPIO_MODER_MODE9_Msk);
      break;
  }
}
