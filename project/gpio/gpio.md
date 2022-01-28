# gpio
**General Purpose Input/Output** 通用输入输出
K210 有8个通用输入输出

```c
int gpio_init(void);//初始化
int gpio_set_drive_mode(uint8_t pin,
                        gpio_drive_mode_t mode);
typedef enum _gpio_drive_mode
{
GPIO_DM_INPUT,              //输入
GPIO_DM_INPUT_PULL_DOWN,    //输入下拉    
GPIO_DM_INPUT_PULL_UP,      //输入上拉
GPIO_DM_OUTPUT,             //输出
} gpio_drive_mode_t;

void  gpio_set_pin(uint8_t pin, 
                gpio_pin_value_t value);
gpio_pin_value_t gpio_get_pin(uint8_t pin);
```
