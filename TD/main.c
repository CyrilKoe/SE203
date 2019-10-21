#include "main.h"

void init_all();


int main()
{
  init_all();

  while(1) {
    draw_image(my_image);
  }
  

  return 0;
}

void init_all() {
  clocks_init();
  uart_init(38400);
  led_init();
  matrix_init();
  desactivate_rows();  
  image_init(my_image);
  irq_init();
  button_init();
}
