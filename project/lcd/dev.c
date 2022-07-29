#include "fpioa.h"
#include "sysctl.h"

#include "dev.h"
#include "lcd.h"

int system_lcd_init(void)
{
    fpioa_set_function(LCD_DC, FUNC_GPIOHS0 + DC_GPIO);
    fpioa_set_function(LCD_CS, FUNC_SPI0_SS3);
    fpioa_set_function(LCD_WR, FUNC_SPI0_SCLK);
    fpioa_set_function(LCD_RST, FUNC_GPIOHS0 + RST_GPIO);
    
    sysctl_set_spi0_dvp_data(1);
    lcd_init();
    lcd_set_direction(DIR_YX_RLDU);
    return 0;
}