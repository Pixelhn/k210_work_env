#include <stdio.h>
#include "fpioa.h"
#include "sysctl.h"
#include "sleep.h"

#include "dev.h"
#include "lcd.h"
#include "desplay.h"
uint32_t g_lcd_gram[LCD_X_MAX * LCD_Y_MAX / 2] __attribute__((aligned(128)));

int main(void)
{
    sleep(1);
    printf("lcd test\n");
    printf("%ld\n", sizeof(short));
    system_lcd_init();

    uint16_t i = 0;
    char chars[64];
    //for(; i <= 65534;i++){
        //lcd_clear(i);
        //printf("%d\n", i);
        //msleep(10);}
    lcd_clear(RED);
    lcd_draw_picture(0, 0, 240, 240, g_lcd_gram);
    lcd_draw_string(25, 50, "Kendryte K210", BLUE);
    //lcd_draw_rectangle(50, 50, 100, 100, 10, YELLOW);
    int y = 0;
    des_rainbow_flag();
    lcd_draw_char2(30, 30, 'P', BLUE, 4);
    lcd_draw_string2(25, 50, "Pixelhn", BLACK, 9);
    des_rainbow_flag();

    while (1){
        lcd_clear(WHITE);
        des_picture();
        scanf("%s", chars);
        lcd_draw_string(0, y, chars, WHITE);
        chars[0] = '\0';
        y += 16;
    }
}
