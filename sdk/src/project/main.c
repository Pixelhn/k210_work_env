#include <stdio.h>
#include "fpioa.h"
#include "sysctl.h"
#include "sleep.h"

#include "lcd.h"
#include "bcf.h"

uint32_t g_lcd_gram[LCD_X_MAX * LCD_Y_MAX / 2] __attribute__((aligned(128)));

int main(void)
{
    sleep(1);
    printf("lcd test\n");
    system_lcd_init();


    char chars[64];
    lcd_clear(RED);
    lcd_draw_picture(0, 0, 240, 240, g_lcd_gram);
    lcd_draw_string(25, 25, "Pixelhn", RED);
    lcd_draw_string(25, 50, "Kendryte K210", BLUE);
    while (1){
        scanf("%s", chars);
        lcd_draw_string(0, 0, chars, WHITE);
        chars[0] = '\0';
    }
}
