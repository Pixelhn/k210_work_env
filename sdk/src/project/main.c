#include <stdio.h>
#include "fpioa.h"
#include "lcd.h"
#include "sysctl.h"
#include "nt35310.h"
#include "board_config.h"
#include "sleep.h"

uint32_t g_lcd_gram[LCD_X_MAX * LCD_Y_MAX / 2] __attribute__((aligned(128)));

static void io_set_power(void)
{
#if BOARD_LICHEEDAN
    sysctl_set_power_mode(SYSCTL_POWER_BANK6, SYSCTL_POWER_V18);
    sysctl_set_power_mode(SYSCTL_POWER_BANK7, SYSCTL_POWER_V18);
#else
    sysctl_set_power_mode(SYSCTL_POWER_BANK1, SYSCTL_POWER_V18);
#endif
}

static void io_mux_init(void)
{
#if BOARD_LICHEEDAN
    fpioa_set_function(38, FUNC_GPIOHS0 + DCX_GPIONUM);
    fpioa_set_function(36, FUNC_SPI0_SS3);
    fpioa_set_function(39, FUNC_SPI0_SCLK);
    fpioa_set_function(37, FUNC_GPIOHS0 + RST_GPIONUM);
    sysctl_set_spi0_dvp_data(1);
#else
    fpioa_set_function(8, FUNC_GPIOHS0 + DCX_GPIONUM);
    fpioa_set_function(6, FUNC_SPI0_SS3);
    fpioa_set_function(7, FUNC_SPI0_SCLK);
    sysctl_set_spi0_dvp_data(1);
#endif
}

int main(void)
{
    printf("lcd test\n");
    io_mux_init();
    io_set_power();
    lcd_init();
#if BOARD_LICHEEDAN
    lcd_set_direction(DIR_XY_LRDU);
#endif
    lcd_clear(RED);
    lcd_draw_picture(0, 0, 240, 160, g_lcd_gram);
    lcd_draw_string(16, 40, "Pixelhn", RED);
    lcd_draw_string(16, 80, "Kendryte K210", BLUE);
    while (1){
        lcd_draw_string(16, 40, "Pixelhn", RED);
        msleep(100);
        lcd_draw_string(16, 40, "Pixelhn", ORANGE);
        msleep(100);
        lcd_draw_string(16, 40, "Pixelhn", YELLOW);
        msleep(100);
        lcd_draw_string(16, 40, "Pixelhn", GREEN);
        msleep(100);
        lcd_draw_string(16, 40, "Pixelhn", BLUE);
        msleep(100);
        lcd_draw_string(16, 40, "Pixelhn", PURPLE);
        msleep(100);
    }
}
