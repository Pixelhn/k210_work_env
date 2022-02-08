/*
320 * 240 * 2
*/

#include"desplay.h"
#include"lcd.h"


uint16_t frame[y_pixel][x_pixel];
typedef struct
{
    uint16_t *p_point;
    uint16_t (*p_line)[x_pixel];
    uint32_t *p_frame;
}p_display;

p_display c_display;

uint16_t *p_point;
uint16_t (*p_line)[x_pixel];
uint32_t *p_frame;

void des_picture()
{
    p_frame = (uint32_t *)&frame[0][0];
    p_point = &frame[0][0];
    p_line  = &frame[0];
    
    int i, j;
    for (i = 0; i < y_pixel; i++){
        uint16_t *up_point = (uint16_t *)p_line;
        if(i%7 == 0){
            for(j = 0; j < x_pixel; j++) {
                *up_point = RED;
                up_point++;
            }
        }
        
    p_line++;
    }
    lcd_frame(p_frame);
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