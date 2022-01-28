#include <stdio.h>
#include <unistd.h>
#include "fpioa.h"
#include "gpiohs.h"
#include "sysctl.h"
#include "board_config.h"

uint32_t irq_flag = 1;

#define GPIO_LED 3
#define GPIO_KEY 2

uint32_t g_count;

int irq_gpiohs2(void* ctx)
{
    //irq_flag = gpiohs_get_pin(GPIO_KEY);

    printf("IRQ The PIN is %d\n", irq_flag);

    uint32_t *tmp = (uint32_t *)(ctx);
    printf("count is %d\n", (*tmp)++);

    if (irq_flag){
        gpiohs_set_pin(GPIO_LED, GPIO_PV_LOW);
        printf("low\n");}
    else{
        gpiohs_set_pin(GPIO_LED, GPIO_PV_HIGH);
        printf("high\n");}
    irq_flag = !irq_flag;
    return 0;
}

int main(void)
{
    plic_init();
    sysctl_enable_irq();

    fpioa_set_function(RIO, FUNC_GPIOHS3);
    gpiohs_set_drive_mode(GPIO_LED, GPIO_DM_OUTPUT);
    gpio_pin_value_t value = GPIO_PV_HIGH;
    gpiohs_set_pin(GPIO_LED, value);

    fpioa_set_function(KIO, FUNC_GPIOHS2);
    gpiohs_set_drive_mode(GPIO_KEY, GPIO_DM_INPUT_PULL_UP);
    gpiohs_set_pin_edge(GPIO_KEY, GPIO_PE_LOW);

    gpiohs_irq_register(GPIO_KEY, 1, irq_gpiohs2, &g_count);

    while (1);
}
