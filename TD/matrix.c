#include "matrix.h"


/*
SB=PC5 LAT=PC4 RST=PC3 SCK=PB1 SDA=PA4
C0=PB2 C1=PA15 C2=PA2 C3=PA7 C4=PA6 C5=PA5 C6=PB0 C7=PA3
*/

#define RST(x) = (GPIOC -> BSRR = GPIO_BSRR_BR3 >> (16*x)
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
#define pulse_SCK() = do{SCK(0); wait(3); SCK(1); wait(3); SCK(0); wait(3)}while()
#define pulse_LAT() = do{LAT(1); wait(3); LAT(0); wait(3); LAT(1); wait(3)}while()

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} rgb_color;

static void wait(unsigned int n);
void send_byte(uint8_t val, int bank);
void deactivate_rows();
void activate_row(int row);
void mat_set_row(int row, const rgb_color *val);

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

void deactivate_rows() {
    ROW0(0);ROW1(0);ROW2(0);ROW3(0);
    ROW4(0);ROW5(0);ROW6(0);ROW7(0);
}

void activate_row(int row) {
    switch(row){
        case 0: ROW0(1);
        case 1: ROW1(1);
        case 2: ROW2(1);
        case 3: ROW3(1);
        case 4: ROW4(1);
        case 5: ROW5(1);
        case 6: ROW6(1);
        case 7: ROW7(1);
    }
}

void send_byte(uint8_t val, int bank){
    SB(bank);
    for(int k = 7; k>=0; k--) {
        SDA((val >> k) & 1);
        wait(1);
        pulse_SCK();
    }
}

static void wait(unsigned int n){
  for(unsigned int i = 0; i<n; i++) asm volatile("nop");
}

void mat_set_row(int row, const rgb_color *val) {
    for(int k = 7; k > 0; k--) {
        send_byte(*(val+k)->b,1);
        send_byte(*(val+k)->g,1);
        send_byte(*(val+k)->r,1);
    }
    activate_row(row);
    pulse_LAT();
}