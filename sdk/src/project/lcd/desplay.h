typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;

#define x_pixel 320
#define y_pixel 240

#define RGB565_R  0xF800
#define RGB565_G  0x07E0
#define RGB565_B  0x001F



typedef struct
{
    uint16_t rgb;
    uint8_t  r;
    uint8_t  g;
    uint8_t  b;
}pixel_color_s;


uint16_t build_color(uint8_t r, uint8_t g, uint8_t b);
uint16_t encode_color(pixel_color_s *one_color);
uint16_t decode_color(pixel_color_s *one_color);
int frame_color(uint32_t *frame, int rgb);


void des_rainbow_flag();
void fill_point();


void des_picture();