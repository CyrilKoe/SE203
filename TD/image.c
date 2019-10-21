#include "image.h"



void image_init(rgb_color image[8][8]) {
    uint8_t * ptr;
    ptr = (uint8_t *) &_binary___Others_image_raw_start;

    for(int j = 0; j < 8; j++) {
        for(int i = 0; i < 8; i++) {
            image[i][j].r = *(ptr++);
            image[i][j].g = *(ptr++);
            image[i][j].b = *(ptr++);
        }
    }


}

void clear_image(rgb_color image[8][8]) {
    for(int j = 0; j < 8; j++) {
        for(int i = 0; i < 8; i++) {
            image[i][j].r = 0;
            image[i][j].g = 0;
            image[i][j].b = 0;
        }
    }
}

void draw_image(rgb_color image[8][8]) {
    rgb_color row[8];
    for(int j = 0; j<8; j++){
        for(int i = 0; i<8; i++)
            row[i] = image[i][j];
        mat_set_row(j,row);
        wait(10000);
    }
}