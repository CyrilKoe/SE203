#include <stdint.h>


#define RCC_AHB2ENR (*(volatile uint32_t *) 0x4002104C)
#define GPIOB_MODER (*(volatile uint32_t *) 0x48000400)
#define GPIOB_BSRR (*(volatile uint32_t *) 0x48000418)
#define GPIOB_ODR (*(volatile uint32_t *) 0x48000414)

/* Active l'horloge du bloc GPIO B
(Place dans le registre RCC_AHB2ENR la valeur 1 au bit 1 (GPIOBEN))
Met la broche 15 du bloc GPIO B en mode sortie
*/
void led_init() {
  RCC_AHB2ENR |= (1 << 1);
  GPIOB_MODER = 0xDFFFFEBF;
}

// Place le bit 1 sur la partie SET
void led_on() {
  GPIOB_BSRR = 0b0100000000000000;
}

// Place le bit 1 sur la partie RESET
void led_off() {
  GPIOB_BSRR = 0b0100000000000000 << 16;
}
