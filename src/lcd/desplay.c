/*
320 * 240 * 2
RGB 565
*/
#include <stdio.h>

#include"desplay.h"
#include"lcd.h"
#include "image.h"


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

            for(j = 0; j < x_pixel; j++) {
                *up_point = build_color(20, 54, 14);
                up_point++;
            
        }
        
    p_line++;
    }
    lcd_frame(rgb_image);
    frame_color(rgb_image, 1);
    lcd_frame(rgb_image);
    return;
}

void des_rainbow_flag()
{
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

uint16_t build_color(uint8_t r, uint8_t g, uint8_t b)
{
    pixel_color_s rgb;
    rgb.r = r;
    rgb.g = g;
    rgb.b = b;
    return encode_color(&rgb);
}

uint16_t encode_color(pixel_color_s *one_color)
{   
    one_color->r = one_color->r & 0x1f;
    one_color->g = one_color->g & 0x3f;
    one_color->b = one_color->b & 0x1f;
    one_color->rgb = one_color->r << 11 | one_color->g << 5 | one_color->b;
    return one_color->rgb;
}

uint16_t decode_color(pixel_color_s *one_color)
{
    one_color->r = (uint8_t)(one_color->rgb & RGB565_R);
    one_color->g = (one_color->rgb & RGB565_G);
    one_color->b = (one_color->rgb & RGB565_B);
    return one_color->rgb;
}

int frame_color(uint32_t *frame, int rgb)
{
    int i;
    uint32_t * frame_s = frame;
    for(i = 0; i < 240*160; i++)
    {
        *frame_s = *frame_s & 0x07E007E0;
        frame_s++;
        printf("%d\n", i);
        lcd_frame(frame);
    }
    return 0;
}