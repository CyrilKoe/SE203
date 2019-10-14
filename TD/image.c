#include "image.h"



rgb_color my_image[8][8];

void image_init() {
    uint8_t * ptr;
    ptr = (uint8_t *) _binary___Others_image_raw_start;

    for(int j = 0; j < 8; j++) {
        for(int i = 0; i < 8; i++) {
            my_image[i][j].r = *(ptr++);
            my_image[i][j].g = *(ptr++);
            my_image[i][j].b = *(ptr++);
        }
    }


}

void draw_image() {
    rgb_color row[8];
    for(int j = 0; j<8; j++){
        desactivate_rows();
        for(int i = 0; i<8; i++)
            row[i] = my_image[i][j];
        mat_set_row(j,row);
        wait(10000);
    }
}