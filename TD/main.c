#include "led.h"
#include "uart.h"
#include "clocks/clocks.h"
#include <string.h>
#include <math.h>

int fibo(int);
void wait(unsigned int n);
void init_all();


int main()
{
  init_all();

  uint8_t g[30][10];

  int a = 0;

  for(uint8_t i = 0; i<30; i++) {
    uart_gets(g[i], sizeof(g[i]));
    a++;
    if(a%2)
      led_on();
    else
      led_off();
  }

  for(uint8_t i = 0; i<30; i++) {
    uart_puts(g[i]);
  }

  return 0;
}

void init_all() {
  clocks_init();
  uart_init();
  led_init();
}

int fibo(int n){
  if(n>=2)
    return fibo(n-1) + fibo(n-2);
  else
    return 1;
}

void wait(unsigned int n){
  for(unsigned int i = 0; i<n; i++) asm volatile("nop");
}
