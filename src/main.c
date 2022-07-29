#include <bsp.h>
#include <sysctl.h>

#include <fpioa.h>
#include <gpio.h>


// Hard
#define hR 13
#define hG 12
#define hB 14


//Sorf
#define baseGPIO(s) (s +  FUNC_GPIO0)
#define sR (1)
#define sG (2)
#define sB (3)

int core1_function(void *ctx)
{
    uint64_t core = current_coreid();
    printf("Core %ld Hello world\n", core);
    while(1);
}

int main(void)
{
    sysctl_pll_set_freq(SYSCTL_PLL0, 800000000);
    uint64_t core = current_coreid();
    int data;
    printf("Core %ld Hello world\n", core);
    register_core1(core1_function, NULL);

    /* Clear stdin buffer before scanf */
    sys_stdin_flush();

    scanf("%d", &data);
    printf("\nData is %d\n", data);

    fpioa_set_function(hR, baseGPIO(sR));
    fpioa_set_function(hG, baseGPIO(sG));
    fpioa_set_function(hB, baseGPIO(sB));

    gpio_init();

    gpio_set_drive_mode(sR, GPIO_DM_OUTPUT);
    gpio_set_drive_mode(sG, GPIO_DM_OUTPUT);
    gpio_set_drive_mode(sB, GPIO_DM_OUTPUT);
    while(1)
    {
        gpio_set_pin(sR, GPIO_PV_HIGH);
        gpio_set_pin(sG, GPIO_PV_HIGH);
        gpio_set_pin(sB, GPIO_PV_HIGH);
        sleep(1);
        gpio_set_pin(sR, GPIO_PV_LOW);
        gpio_set_pin(sG, GPIO_PV_LOW);
        gpio_set_pin(sB, GPIO_PV_LOW);
        sleep(1);        
    }
    return 0;
}
