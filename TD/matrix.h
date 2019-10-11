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


#endif //MATRIX_H