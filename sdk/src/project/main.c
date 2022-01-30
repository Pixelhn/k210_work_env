#include <stdio.h>
#include "fpioa.h"
#include "sysctl.h"
#include "sleep.h"

#include "nt35310.h"
#include "lcd.h"
#include "bcf.h"

uint32_t g_lcd_gram[LCD_X_MAX * LCD_Y_MAX / 2] __attribute__((aligned(128)));

int main(void)
{
    sleep(1);
    printf("lcd test\n");
    system_lcd_init();



#if BOARD_LICHEEDAN
    lcd_set_direction(DIR_YX_RLDU);
#endif

    lcd_clear(RED);
    lcd_draw_picture(0, 0, 240, 240, g_lcd_gram);
    lcd_draw_string(25, 25, "Pixelhn", RED);
    lcd_draw_string(25, 50, "Kendryte K210", BLUE);
    while (1){
        lcd_draw_string(16, 40, "Pixelhn", RED);
        //lcd_clear(RED);
        msleep(500);
        lcd_draw_string(16, 40, "Pixelhn", ORANGE);
        //lcd_clear(ORANGE);
        msleep(500);
        lcd_draw_string(16, 40, "Pixelhn", YELLOW);
        //lcd_clear(YELLOW);
        msleep(500);
        lcd_draw_string(16, 40, "Pixelhn", GREEN);
        //lcd_clear(GREEN);
        msleep(500);
        lcd_draw_string(16, 40, "Pixelhn", BLUE);
        //lcd_clear(BLUE);
        msleep(500);
        lcd_draw_string(16, 40, "Pixelhn", PURPLE);
        //lcd_clear(PURPLE);
        msleep(500);
    }
}
