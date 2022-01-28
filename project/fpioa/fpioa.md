# fpioa
**现场可编程IO整列**：
支持 IO 的可编程功能选择
8 种驱动能力选择
内部上拉/下拉电阻选择
IO 输入的内部施密特触发器设置
IO 输出的斜率控制
内部输入逻辑的电平设置

K210：可将255个**内部功能**映射到48个**外部IO**

## API
```c
int fpioa_set_function(int number, //外部IO管脚号       给外部管脚号分配内部功能号
                    fpioa_function_t function); //内部功能号
int fpioa_set_io(int number, //外部IO管脚号             设置IO管脚属性
                    fpioa_io_config_t ∗ cfg); //管脚功能结构体

int fpioa_set_io_pull(int number, fpioa_pull_t pull)            //设置上下拉值
int fpioa_set_io_driving(int number, fpioa_driving_t driving)   //设置驱动力
int fpioa_set_tie_enable(fpioa_function_t functio, int enable)
int fpioa_set_tie_value(fpioa_function_t function, int value)

int fpioa_get_io_by_function(fpioa_function_t function)；   //根据功能号 获得 外部管脚号
int fpioa_get_io(int number, fpioa_io_config_t ∗ cfg)       //根据管脚号 获得 其功能号
int fpioa_get_io_pull(int number)       //获得上下拉值
int fpioa_get_io_driving(int number)    //获得驱动力设置
```

## 数据类型
```c

```