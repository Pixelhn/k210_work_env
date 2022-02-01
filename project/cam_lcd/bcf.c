#include "fpioa.h"
#include "sysctl.h"

#include "bcf.h"
#include "lcd.h"

#include "dvp.h"
#include "ov5640.h"
#include "ov2640.h"

int system_lcd_init(void){
    fpioa_set_function(LCD_DC, FUNC_GPIOHS0 + DC_GPIO);
    fpioa_set_function(36, FUNC_SPI0_SS3);
    fpioa_set_function(39, FUNC_SPI0_SCLK);
    fpioa_set_function(37, FUNC_GPIOHS0 + RST_GPIO);
    sysctl_set_spi0_dvp_data(1);
    lcd_init();
    lcd_set_direction(DIR_YX_RLDU);
    return 0;
}

int system_cam_init(cam_info cam){
    fpioa_set_function(42, FUNC_CMOS_RST);
    fpioa_set_function(44, FUNC_CMOS_PWDN);
    fpioa_set_function(46, FUNC_CMOS_XCLK);
    fpioa_set_function(43, FUNC_CMOS_VSYNC);
    fpioa_set_function(45, FUNC_CMOS_HREF);
    fpioa_set_function(47, FUNC_CMOS_PCLK);
    fpioa_set_function(41, FUNC_SCCB_SCLK);
    fpioa_set_function(40, FUNC_SCCB_SDA);

    dvp_init(16);
    dvp_set_xclk_rate(50000000);
    dvp_enable_burst();
    dvp_set_output_enable(0, 1);
    dvp_set_output_enable(1, 1);
    dvp_set_image_format(DVP_CFG_RGB_FORMAT);
    dvp_set_image_size(320, 240);
    ov5640_init();
    return 0;
}