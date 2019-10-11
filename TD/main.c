#include "led.h"
#include "uart.h"
#include "clocks/clocks.h"
#include "matrix.h"
#include <string.h>
#include <math.h>


void wait(unsigned int n);
void init_all();
void int_to_hexa_string(uint32_t i, uint8_t* str);
uint8_t int_to_hexa_char(uint8_t i);

uint8_t g[100];
uint8_t s[6];
uint32_t sum = 0;

int main()
{
  matrix_init();
  init_all();
  desactivate_rows();
  activate_row(3);
  activate_row(4);
  desactivate_rows();

  rgb_color pxl_column[8];
  for(int k = 0; k<8; k++) {
    pxl_column[k].r = 0;
    pxl_column[k].g = 0x0f;
    pxl_column[k].b = 0x0f;
  }

  mat_set_row(5, pxl_column);

  while(1) {
    for(int k = 0; k<8; k++) {
      desactivate_rows();
      activate_row(k);
      wait(1000000);
    }
  }

  return 0;
}

void init_all() {
  clocks_init();
  uart_init();
  led_init();
}

void int_to_hexa_string(uint32_t i, uint8_t* str) {
  uint8_t digits[4] = {0,0,0,0};
  uint32_t diviseur = 1;
  uint8_t digit = 0;
  str[0] = '0';
  str[1] = 'x';

  for(uint8_t k = 0; k<4; k++) {
    diviseur *= 16;
    digit = (i%diviseur)>>(4*k);
    i = i - (digit<<(4*k));
    digits[3-k] = digit;
  }

  for(uint8_t k = 0; k<4; k++) {
    digit = digits[k];
    str[k+2] = int_to_hexa_char(digit);
  }

}

uint8_t int_to_hexa_char(uint8_t i) {
  if(i > 0 && i < 10){
    return ('0'+i);

  } else if(i > 0 && i < 16){
    return ('a'+i-10);

  } else return 0;
}

void wait(unsigned int n){
  for(unsigned int i = 0; i<n; i++) asm volatile("nop");
}
