#include "led.h"
#include "uart.h"
#include "clocks/clocks.h"
#include "matrix.h"
#include <string.h>
#include <math.h>


void wait(unsigned int n);
void init_all();

uint8_t g[100];
uint8_t s[6];
uint32_t sum = 0;
extern uint32_t _binary___Others_image_raw_start;
extern uint32_t _binary___Others_image_raw_end;
rgb_color pxl_column[8];


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

void wait(unsigned int n){
  for(unsigned int i = 0; i<n; i++) asm volatile("nop");
}