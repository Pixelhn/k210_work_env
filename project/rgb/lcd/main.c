#include <stdio.h>
#include "fpioa.h"
#include "lcd.h"
#include "sysctl.h"
#include "st7789.h"
#include "board_config.h"
#include "image.h"
#include "unistd.h"

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
    lcd_set_direction(DIR_YX_RLDU);     /* left up 0,0 */
#else
    lcd_set_direction(DIR_YX_RLUD);     /* left up 0,0 */
#endif
    while(1)
    {
        lcd_draw_picture(0, 0, 320, 240, rgb_image);
        usleep(1000000);
        printf("show pic\n");
    }
    while (1);
}