#include "led.h"
#include "uart.h"
#include "clocks/clocks.h"

int a = 8;
int b = 0;
int c = 0;

int fibo(int);
void wait(unsigned int n);

int main()
{
  clocks_init();
  uart_init();
  led_init();
  led_off();
  unsigned char s[] = "It works\n" ;
  uart_puts(s);

  int a = 0;

  while(1) {
    uart_getchar();
    a++;
    if(a%2)
      led_on();
    else
      led_off();
  }
  
  return 0;
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
