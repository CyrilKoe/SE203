#include "led.h"
#include "uart.h"
#include "clocks/clocks.h"
#include <string.h>
#include <math.h>

int fibo(int);
void wait(unsigned int n);
void init_all();
void int_to_hexa_string(uint32_t i, uint8_t* str);
uint8_t int_to_hexa_char(uint8_t i);

uint8_t g[100];
uint8_t s[6];
uint32_t sum = 0;

int main()
{
  init_all();

  uart_putchar('\n');
  uart_putchar('\r');

  led_off();

  for(uint8_t i = 0; i<100; i++) {
    uart_gets(&g[i], 1);
  }

  for(uint8_t i = 0; i<100; i++) {
    sum+=g[i];
  }

  int_to_hexa_string(sum, s);

  uart_puts((uint8_t*) "Résultat de la somme : \n\r");
  uart_puts(s);

  led_on();

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

  for(uint8_t k = 0; k<4; k++) {
    diviseur *= 16;
    digit = (i%diviseur)>>(4*k);
    i = i - (digit<<(4*k));
    digits[3-k] = digit;
  }

  str[0] = '0';
  str[1] = 'x';
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

int fibo(int n){
  if(n>=2)
    return fibo(n-1) + fibo(n-2);
  else
    return 1;
}

void wait(unsigned int n){
  for(unsigned int i = 0; i<n; i++) asm volatile("nop");
}
