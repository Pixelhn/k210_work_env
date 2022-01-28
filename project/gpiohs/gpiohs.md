# gpiohs
**通用高速输入输出**
一共有48个高速GPIO
> 与普通GPIO相似，但管脚反转能力更强

• 可配置上下拉驱动模式
• 支持上升沿、下降沿和双沿触发

## API
```c
void gpiohs_set_drive_mode(uint8_t pin, gpio_drive_mode_t mode)
        //设置高速gpio驱动模式
void gpiohs_set_pin(uint8_t pin, gpio_pin_value_t value)
        //设置高速gpio管脚值
void gpiohs_set_pin_edge(uint8_t pin, gpio_pin_edge_t edge)
        //设置高速gpio中断触发描述
void gpiohs_irq_register(uint8_t pin, uint32_t priority,            
                        plic_irq_callback_t callback,
                        void ∗ctx)
        //设置高速gpio中断回调函数
void gpiohs_irq_unregister ( uint8_t pin )
        //注销高速gpio中断

gpio_pin_value_t gpiohs_get_pin(uint8_t pin)
        //获得gpio管脚值
```

##  数据结构
```c
typedef enum _gpio_drive_mode   //gpio驱动模式
{
GPIO_DM_INPUT ,
GPIO_DM_INPUT_PULL_DOWN ,
GPIO_DM_INPUT_PULL_UP ,
GPIO_DM_OUTPUT ,
} gpio_drive_mode_t ;

typedef enum _gpio_pin_value    //gpio值
{
GPIO_PV_LOW,
GPIO_PV_HIGH
} gpio_pin_value_t;

typedef enum _gpio_pin_edge     //高速gpio边沿触发模式
{
GPIO_PE_NONE ,      //不触发
GPIO_PE_FALLING ,   //下沿触发
GPIO_PE_RISING ,    //上沿触发
GPIO_PE_BOTH ,      //双触发
GPIO_PE_LOW ,       //地电平触发
GPIO_PE_HIGH = 8 ,  //高电平触发
} gpio_pin_edge_t ;
```