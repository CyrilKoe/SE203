#define RCC_AHB2ENR (*(volatile uint32_t *) 0x4002104C)
#define GPIOB_MODER (*(volatile uint32_t *) 0x4800 0400)

/* Active l'horloge du bloc GPIO B
(Place dans le registre RCC_AHB2ENR la valeur 1 au bit 1 (GPIOBEN))
Met la broche 15 du bloc GPIO B en mode sortie
*/
void led_init() {
  RCC_AHB2ENR = (1 << 1);
  GPIOB_MODER = (01 << (15*2));
}
