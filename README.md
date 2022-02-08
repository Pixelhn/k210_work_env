# k210_work_env
k210 work and study environment

## Hardware
[**Maix Bit**](https://wiki.sipeed.com/soft/maixpy/zh/develop_kit_board/maix_bit.html)
![](https://wiki.sipeed.com/soft/maixpy/assets/hardware/maix_bit/maix_bit.png)

### K210
**CPU**：双核RISC-V 64位 400MHz，每个核心拥有独立的FPU浮点加速单元

**KPU**：神经网络专用计算单元  
**APU**：音频处理专用计算单元  
**FFT**：快速傅里叶变换加速器  
**AES SHA256**：AES加解密，SHA散列计算加速单元  

**WDT**：看门狗  
**TIMER**：计时器  
**RTC**：实时时钟  
**DVP**：数字视频接口，摄像头接口模块  

**SRAM**：8MiB  
**DMAC**：直接内存访问  
**OTP**：一次性可编程存储器  
**FPIOA**：现场可编程IO阵列  
GPIO，GPIOHS，UART，I<sup>2</sup>C，SPI，I<sup>2</sup>S，PWM

### 屏幕
320 * 240 RGB LCD屏幕
16Bit色深
NT35310驱动

### 摄像头
#### OV5642
![](https://github.com/Pixelhn/k210_work_env/blob/main/img/OV5642.jpg)
> 无法驱动

#### OV5640-AF
未测试

#### OV2640
未测试

### SD卡槽  
SPI协议

##

## Software

**Toolchain**：官方[工具链](https://github.com/kendryte/kendryte-gnu-toolchain)

**SDK**：官方[standalone-V0.5.6](https://github.com/kendryte/kendryte-standalone-sdk/releases/tag/V0.5.6)

**烧写上传工具**：[Kflash](https://github.com/kendryte/kflash.py)

## Tasks
流程、架构、功能的安排、设计、实现
详见[Working_Tasks.md](https://github.com/Pixelhn/k210_work_env/blob/main/Working_Tasks.md)