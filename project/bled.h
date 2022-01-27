#include<gpiohs.h>

#define R_IO 13 
#define G_IO 14
#define B_IO 12

#define RGBR FUNC_GPIOHS29 - 24 
#define RGBG FUNC_GPIOHS30 - 24
#define RGBB FUNC_GPIOHS31 - 24

int bled_init();
int bled(int n);