#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>
#include "matrix.h"

extern uint32_t _binary___Others_image_raw_start;
extern uint32_t _binary___Others_image_raw_end;

void image_init();
void draw_image();

#endif //IMAGE_H