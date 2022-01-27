#include<sysctl.h>
#include<stdio.h>
#include<gpiohs.h>
#include<fpioa.h>
#include<unistd.h>

#define R_IO 13 
#define G_IO 14
#define B_IO 12

#define RGBR (FUNC_GPIOHS29 - 24)
#define RGBG (FUNC_GPIOHS30 - 24)
#define RGBB (FUNC_GPIOHS31 - 24)

int main(void)
{   
    usleep(100000);
    printf("int:%ld,long:%ld\n", sizeof(int), sizeof(long));
    fpioa_set_function(R_IO, FUNC_GPIOHS29);
    fpioa_set_function(G_IO, FUNC_GPIOHS30);
    fpioa_set_function(B_IO, FUNC_GPIOHS31);

    gpiohs_set_drive_mode(29, GPIO_DM_OUTPUT);
    gpiohs_set_drive_mode(30, GPIO_DM_OUTPUT);
    gpiohs_set_drive_mode(31, GPIO_DM_OUTPUT);

    gpio_pin_value_t value = GPIO_PV_HIGH;

    while (1)
    {
        value = GPIO_PV_HIGH;
        gpiohs_set_pin(29, value);
        sleep(1);
        gpiohs_set_pin(30, value);
        sleep(1);
        gpiohs_set_pin(31, value);
        sleep(1);

        value = GPIO_PV_LOW;
        gpiohs_set_pin(29, value);
        sleep(1);
        gpiohs_set_pin(30, value);
        sleep(1);
        gpiohs_set_pin(31, value);
        sleep(1);
    }
    return 0;
}
