#include "led.h"
#include "uart.h"
#include "clocks/clocks.h"
#include <math.h>

int fibo(int);
void wait(unsigned int n);
void init_all();
int32_t do_sum(uint8_t *s, int32_t a);
int32_t pow_i(int32_t a, int32_t n);

int main()
{
  init_all();

  uint8_t g[80];

  int a = 0;

  while(1) {
    uart_gets(g, sizeof(g));
    uart_puts(g);
    a++;
    if(a%2)
      led_on();
    else
      led_off();
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

int32_t do_sum(uint8_t *s, int32_t a) {
  int32_t sum = 0;
  uint8_t k = 0;
  do{
    sum += (*s-'0')*pow_i(10,k);
    s++;
    k++;
  } while(*s >= '0' && *s <= '9');
  sum += a;
  return sum;
}

int32_t pow_i(int32_t a, int32_t n) {
  int32_t r = 1;
  while (n > 0) {
    r *= a;
    n--;
  }
  return r;
}

void wait(unsigned int n){
  for(unsigned int i = 0; i<n; i++) asm volatile("nop");
}
