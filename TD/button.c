#include "button.h"

void button_init(void) {

  //Active horloge bloc C et met PC13 en input
  SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN);
  GPIOC->MODER = GPIOC->MODER & ~GPIO_MODER_MODE13_Msk;

  //Active EXTI13
  SET_BIT(EXTI->IMR1, EXTI_IMR1_IM13);

  //Mode détection de front descendant
  CLEAR_BIT(EXTI->RTSR1, EXTI_RTSR1_RT13);
  SET_BIT(EXTI->FTSR1, EXTI_FTSR1_FT13);

  //Link PB13 sur EXTI13
  SYSCFG->EXTICR[3] = SYSCFG->EXTICR[3] & (SYSCFG_EXTICR1_EXTI3_PC << SYSCFG_EXTICR4_EXTI13_Pos);
}

// Toggle led verte en cas d'appui sur le bouton B2
void EXTI4_IRQHandler(void) {
  if(READ_BIT(EXTI->PR1, EXTI_PR1_PIF13)) {
    SET_BIT(EXTI->PR1, EXTI_PR1_PIF13);
    led_toggle();
  } else {
    default_handler();
  }
}
