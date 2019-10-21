#ifndef IMAGE_H
#define IMAGE_H

#include <stdint.h>
#include "matrix.h"

extern uint32_t _binary___Others_image_raw_start;
extern uint32_t _binary___Others_image_raw_end;

void image_init(rgb_color image[8][8]);
void image_draw(rgb_color image[8][8]);
void image_clear(rgb_color image[8][8]);

#endif //IMAGE_H