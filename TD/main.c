#include "led.h"

int a = 8;
int b = 0;
int c = 0;

int fibo(int);


int main()
{

  led_init();
  while(1) {
    led_on();
    for(int i = 0; i<100000; i++) asm volatile("nop");
    led_off();
    for(int i = 0; i<100000; i++) asm volatile("nop");
  }

  return 0;
}

int fibo(int n){
  if(n>=2)
    return fibo(n-1) + fibo(n-2);
  else
    return 1;
}
