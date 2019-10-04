#include "led.h"

int a = 8;
int b = 0;
int c = 0;

int fibo(int);
void wait(unsigned int n);

int main()
{

  led_init();
  while(1) {
    led_on();
    wait(100000);
    led_off();
    wait(100000);
    led(LED_BLUE);
    wait(100000);
    led(LED_OFF);
    wait(100000);
    led(LED_YELLOW);
    wait(100000);
    led(LED_OFF);
    wait(100000);
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
