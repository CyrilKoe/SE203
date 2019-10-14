#include "led.h"
#include "uart.h"
#include "clocks/clocks.h"
#include "matrix.h"
#include "image.h"
#include <string.h>
#include <math.h>


void init_all();

rgb_color pxl_column[8];


int main()
{
  init_all();
  desactivate_rows();  

  for(int k = 0; k<8; k++) {
    pxl_column[k].b = 1<<k;
  }

  while(1) {
    draw_image();
  }
  

  return 0;
}

void init_all() {
  clocks_init();
  uart_init();
  led_init();
  matrix_init();
  image_init();
}
