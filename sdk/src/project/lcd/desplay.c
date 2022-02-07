/*
320 * 240 * 2
*/

#include"desplay.h"
#include"lcd.h"


uint16_t frame[240][320];
uint32_t csp[2*160*240];
uint16_t line[2][160];

uint16_t *p_point;
uint32_t *p_frame;

void des_picture()
{
    p_frame = (uint32_t *)&frame[0][0];
    p_point = (uint16_t *)&frame[0][0];
    int i;
    for (i = 0;i < 320*240;i++){
        if(i%3 == 0)
        *p_point = 0xFFE0;else *p_point = RED;
    p_point++;
    }
    lcd_draw_picture(0, 0, 320, 240, p_frame);
    return;
}

void des_rainbow_flag(){
    lcd_fill(0, 0, 53, 240, RED);
    lcd_fill(53, 0, 107, 240, ORANGE);
    lcd_fill(107, 0, 160, 240, YELLOW);
    lcd_fill(160, 0, 213, 240, GREEN);
    lcd_fill(213, 0, 267, 240, BLUE);
    lcd_fill(267, 0, 320, 240, PURPLE);
}

void fill_point(){
    int x, y;
    for(y = 0; y < 240; y++){
        for(x = 0; x < 320; x++)
           lcd_draw_point(x, y, BLACK);
    }
    return;
}