#include "matrix.h"

/*
SB=PC5 LAT=PC4 RST=PC3 SCK=PB1 SDA=PA4
C0=PB2 C1=PA15 C2=PA2 C3=PA7 C4=PA6 C5=PA5 C6=PB0 C7=PA3
*/

#define RST(x) = GPIOC -> BSRR = GPIO_BSRR_BR3 >> (16*x)
#define SB(x) = GPIOC -> BSRR = GPIO_BSRR_BR5 >> (16*x)
#define LAT(x) = GPIOC -> BSRR = GPIO_BSRR_BR4 >> (16*x)
#define SDA(x) = GPIOA -> BSRR = GPIO_BSRR_BR4 >> (16*x)
#define ROW0(x) = GPIOB -> BSRR = GPIO_BSRR_BR2 >> (16*x)
#define ROW1(x) = GPIOA -> BSRR = GPIO_BSRR_BR15 >> (16*x)
#define ROW2(x) = GPIOA -> BSRR = GPIO_BSRR_BR2 >> (16*x)
#define ROW3(x) = GPIOA -> BSRR = GPIO_BSRR_BR7 >> (16*x)
#define ROW4(x) = GPIOA -> BSRR = GPIO_BSRR_BR6 >> (16*x)
#define ROW5(x) = GPIOA -> BSRR = GPIO_BSRR_BR5 >> (16*x)
#define ROW6(x) = GPIOB -> BSRR = GPIO_BSRR_BR0 >> (16*x)
#define ROW7(x) = GPIOA -> BSRR = GPIO_BSRR_BR3 >> (16*x)
#define pulse_SCK = do{SCK(0); wait(3); SCK(1); wait(3); SCK(0); wait(3)}while()
#define pulse_LAT = do{LAT(1); wait(3); LAT(0); wait(3); LAT(1); wait(3)}while()

static void wait(unsigned int n);
void send_byte(uint8_t val, int bank);

void matrix_init() {
    //Enable clock GPIOB  et USART1
    RCC->AHB2ENR = RCC->AHB2ENR | RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOBEN | RCC_AHB2ENR_GPIOCEN;

    GPIOC -> MODER = (GPIOC -> MODER & (~GPIO_MODER_MODE5_Msk & ~GPIO_MODER_MODE4_Msk & ~GPIO_MODER_MODE3_Msk))
        | (0b01 << GPIO_MODER_MODE5_Pos) | (0b01 << GPIO_MODER_MODE4_Pos) | (0b01 << GPIO_MODER_MODE3_Pos);

    GPIOA -> MODER = (GPIOA -> MODER & (~GPIO_MODER_MODE4_Msk & ~GPIO_MODER_MODE15_Msk & ~GPIO_MODER_MODE2_Msk))
        | (0b01 << GPIO_MODER_MODE4_Pos) | (0b01 << GPIO_MODER_MODE15_Pos) | (0b01 << GPIO_MODER_MODE2_Pos);

    GPIOA -> MODER = (GPIOA -> MODER & (~GPIO_MODER_MODE7_Msk & ~GPIO_MODER_MODE6_Msk & ~GPIO_MODER_MODE5_Msk & ~GPIO_MODER_MODE3_Msk))
        | (0b01 << GPIO_MODER_MODE7_Pos) | (0b01 << GPIO_MODER_MODE6_Pos) | (0b01 << GPIO_MODER_MODE5_Pos) | (0b01 << GPIO_MODER_MODE3_Pos);

    GPIOB -> MODER = (GPIOB -> MODER & (~GPIO_MODER_MODE1_Msk & ~GPIO_MODER_MODE2_Msk & ~GPIO_MODER_MODE0_Msk))
        | (0b01 << GPIO_MODER_MODE1_Pos) | (0b01 << GPIO_MODER_MODE2_Pos) | (0b01 << GPIO_MODER_MODE0_Pos);

    //RST = 0  LAT = 1  SB = 1
    GPIOC -> BSRR = GPIO_BSRR_BR3 | GPIO_BSRR_BS4 | GPIO_BSRR_BS5;
    //SCK = 0  SDA = 0
    GPIOB -> BSRR = GPIO_BSRR_BR1 | GPIO_BSRR_BR4;
    //C0-7 = 0
    GPIOB -> BSRR = GPIO_BSRR_BR0 | GPIO_BSRR_BR14;
    GPIOA -> BSRR = GPIO_BSRR_BR15 | GPIO_BSRR_BR2 | GPIO_BSRR_BR7 | GPIO_BSRR_BR6 | GPIO_BSRR_BR5 | GPIO_BSRR_BR3;

    wait(10000);
    //RST = 1
    GPIOC -> BSRR = GPIO_BSRR_BS3;
}

void send_byte(uint8_t val, int bank){
    SB(bank);
    for(int k = 7; k>=0; i++) {
        SDA((val >> k) & 1);
        wait(1);
        pulse_SCK();
    }
}

static void wait(unsigned int n){
  for(unsigned int i = 0; i<n; i++) asm volatile("nop");
}