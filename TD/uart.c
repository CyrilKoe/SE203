
#include "uart.h"



// USART1 Tx = PB6, USART1 Rx = PB7
void uart_init(int baudrate) {

  //Enable clock GPIOB et USART1
  RCC->AHB2ENR = RCC->AHB2ENR | RCC_AHB2ENR_GPIOBEN;
  RCC->APB2ENR = RCC->APB2ENR | RCC_APB2ENR_USART1EN;

  //Disable UART1
  USART1->CR1 = USART1->CR1 & ~USART_CR1_UE_Msk;

	//Active les modes USART sur les Rx Tx correspondants
  // USART1 Tx = PB6, USART1 Rx = PB7
  GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE6_Msk) | (0b10 << GPIO_MODER_MODE6_Pos);
  GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODE7_Msk) | (0b10 << GPIO_MODER_MODE7_Pos);
	GPIOB->AFR[0] = (GPIOB->AFR[0] & ~GPIO_AFRL_AFSEL6) | (0b0111 << GPIO_AFRL_AFSEL6_Pos);
  GPIOB->AFR[0] = (GPIOB->AFR[0] & ~GPIO_AFRL_AFSEL7) | (0b0111 << GPIO_AFRL_AFSEL7_Pos);

	//Choix horloge PCLK
  RCC->CCIPR = RCC->CCIPR & ~RCC_CCIPR_USART1SEL_Msk;

	//Reset port série
  RCC->APB2RSTR = RCC_APB2RSTR_USART1RST;
  RCC->APB2RSTR = 0;

  int coef = 80000000/baudrate;
  USART1->BRR = USART1->BRR & ~USART_BRR_DIV_FRACTION_Msk;
  USART1->BRR = USART1->BRR & ~USART_BRR_DIV_FRACTION_Msk;
  USART1->BRR = USART1->BRR | (coef << USART_BRR_DIV_FRACTION_Pos);
  USART1->CR1 = USART1->CR1 & ~USART_CR1_OVER8_Msk;

  //1 start, 8 data
  USART1->CR1 = 0;
  USART1->CR2 = 0;

  //Enable
  USART1->CR1 = USART1->CR1 | USART_CR1_UE;
  USART1->CR1 = USART1->CR1 | USART_CR1_RE;
  USART1->CR1 = USART1->CR1 | USART_CR1_TE;

  //Active interrupts from UART
  SET_BIT(USART1->CR1, USART_CR1_RXNEIE);
  //Active EXTI26
  SET_BIT(EXTI->IMR1, EXTI_IMR1_IM26);
  //Active interrupts form NVIC
  NVIC_EnableIRQ(37);

}

void uart_putchar(uint8_t c){
  while(!READ_BIT(USART1->ISR,USART_ISR_TXE)){}
  USART1->TDR = c;
}

uint8_t uart_getchar() {
	while (!READ_BIT(USART1->ISR,USART_ISR_RXNE)){}
	return (USART1->RDR & USART_RDR_RDR);
}

void uart_puts(const uint8_t *s){
  uint8_t c = *s;
  while(c != '\0') {
    uart_putchar(c);
    s++;
    c = *s;
  }
  uart_putchar('\0');
}

void uart_gets(uint8_t *s, size_t size){
  unsigned int k = 0;

  do{
    *s = uart_getchar();
    if(*s == '\r') {
      *s = '\0';
      break;
    }
    s++;
    k++;
  } while(k < size);
}

void USART1_IRQHandler(void) {
  uint8_t octet = uart_getchar();
  if(octet == 0xff){
  }
}