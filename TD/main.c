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
extern uint32_t _binary___Others_image_raw_start;
extern uint32_t _binary___Others_image_raw_end;


rgb_color my_matrix[8][8];

//0 -> rien, 1 -> 0 et 7, 2 -> 1, 3 -> 2, 6 -> 5


int main()
{
  init_all();
  desactivate_rows();  

  for(int k = 0; k<8; k++) {
    pxl_column[k].b = 1<<k;
  }

  while(1) {

    for(int k = 0; k<8; k++) {
      desactivate_rows();
      for(int i = 0; i<8; i++)
        pxl_column[i].r = 1<<k;
      mat_set_row(k, pxl_column);
      wait(10000);
    }

  }
  

  return 0;
}

void init_all() {
  clocks_init();
  uart_init();
  led_init();
  matrix_init();
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