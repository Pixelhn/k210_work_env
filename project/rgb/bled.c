#include<fpioa.h>
#include<gpiohs.h>
#include"bled.h"

int bled_init(){
    fpioa_set_function(R_IO, FUNC_GPIOHS29);
    fpioa_set_function(G_IO, FUNC_GPIOHS30);
    fpioa_set_function(B_IO, FUNC_GPIOHS31);

    gpiohs_set_drive_mode(RGBR, GPIO_DM_OUTPUT);
    gpiohs_set_drive_mode(RGBG, GPIO_DM_OUTPUT);
    gpiohs_set_drive_mode(RGBB, GPIO_DM_OUTPUT);
}