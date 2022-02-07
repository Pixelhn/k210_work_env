#include"desplay.h"
#include"lcd.h"

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