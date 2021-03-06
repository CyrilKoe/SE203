#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>
#include "./CMSIS/Device/ST/STM32L4xx/Include/stm32l475xx.h"
#include "./CMSIS/Device/ST/STM32L4xx/Include/stm32l4xx.h"

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} rgb_color;

void matrix_init();
void mat_set_row(int row, const rgb_color *val);
void desactivate_rows();
void activate_row(int row);

void inline wait(unsigned int n){
  for(unsigned int i = 0; i<n; i++) asm volatile("nop");
}


#endif //MATRIX_H