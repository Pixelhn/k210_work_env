#include <stdio.h>
#include <unistd.h>
#include "fpioa.h"
#include "gpio.h"
#include "board_config.h"
#include "sleep.h"

int main(void)
{
    fpioa_set_function(12, FUNC_GPIO3);
    fpioa_set_function(KIO, FUNC_GPIO1);

    gpio_init();
    gpio_set_drive_mode(3, GPIO_DM_OUTPUT);
    gpio_set_drive_mode(1, GPIO_DM_INPUT_PULL_UP);
    gpio_pin_value_t value = GPIO_PV_HIGH;
    gpio_set_pin(3, value);
    while (1)
    {
        msleep(100);
        gpio_set_pin(3, value = !value);
            printf("%d\n", gpio_get_pin(1));
    }
    return 0;
}
