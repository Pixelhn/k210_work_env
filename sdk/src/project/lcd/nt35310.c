#include "gpiohs.h"
#include "spi.h"
#include "unistd.h"

#include "nt35310.h"
#include "dev.h"

static void  init_dcx(void)
{
    gpiohs_set_drive_mode(DC_GPIO, GPIO_DM_OUTPUT);
    gpiohs_set_pin(DC_GPIO, GPIO_PV_HIGH);
}

static void set_dcx_control(void)
{
    gpiohs_set_pin(DC_GPIO, GPIO_PV_LOW);
}

static void set_dcx_data(void)
{
    gpiohs_set_pin(DC_GPIO, GPIO_PV_HIGH);
}

#if BOARD_LICHEEDAN
static void init_rst(void)
{
    gpiohs_set_drive_mode(RST_GPIO, GPIO_DM_OUTPUT);
    gpiohs_set_pin(RST_GPIO, GPIO_PV_LOW);
    usleep(100000);
    gpiohs_set_pin(RST_GPIO, GPIO_PV_HIGH);
    usleep(100000);
}
#endif

void tft_hard_init(void)
{
    init_dcx();
    spi_init(SPI_CHANNEL, SPI_WORK_MODE_0, SPI_FF_OCTAL, 8, 0);
#if BOARD_LICHEEDAN
    init_rst();
    spi_set_clk_rate(SPI_CHANNEL, 19000000);
#else
    spi_set_clk_rate(SPI_CHANNEL, 25000000);
#endif
}

void tft_write_command(uint8_t cmd)
{
    set_dcx_control();
    spi_init(SPI_CHANNEL, SPI_WORK_MODE_0, SPI_FF_OCTAL, 8, 0);
    spi_init_non_standard(SPI_CHANNEL, 8/*instrction length*/, 0/*address length*/, 0/*wait cycles*/,
                          SPI_AITM_AS_FRAME_FORMAT/*spi address trans mode*/);
    spi_send_data_normal_dma(DMAC_CHANNEL0, SPI_CHANNEL, SPI_SLAVE_SELECT, (uint8_t *)(&cmd), 1,SPI_TRANS_CHAR);
}

void tft_write_byte(uint8_t *data_buf, uint32_t length)
{
    set_dcx_data();
    spi_init(SPI_CHANNEL, SPI_WORK_MODE_0, SPI_FF_OCTAL, 8, 0);
    spi_init_non_standard(SPI_CHANNEL, 8/*instrction length*/, 0/*address length*/, 0/*wait cycles*/,
                          SPI_AITM_AS_FRAME_FORMAT/*spi address trans mode*/);
    spi_send_data_normal_dma(DMAC_CHANNEL0, SPI_CHANNEL, SPI_SLAVE_SELECT, data_buf, length, SPI_TRANS_CHAR);
}

void tft_write_half(uint16_t *data_buf, uint32_t length)
{
    set_dcx_data();
    spi_init(SPI_CHANNEL, SPI_WORK_MODE_0, SPI_FF_OCTAL, 16, 0);
    spi_init_non_standard(SPI_CHANNEL, 16/*instrction length*/, 0/*address length*/, 0/*wait cycles*/,
                          SPI_AITM_AS_FRAME_FORMAT/*spi address trans mode*/);
    spi_send_data_normal_dma(DMAC_CHANNEL0, SPI_CHANNEL, SPI_SLAVE_SELECT,data_buf, length, SPI_TRANS_SHORT);
}

void tft_write_word(uint32_t *data_buf, uint32_t length, uint32_t flag)
{
    set_dcx_data();
    spi_init(SPI_CHANNEL, SPI_WORK_MODE_0, SPI_FF_OCTAL, 32, 0);

    spi_init_non_standard(SPI_CHANNEL, 0/*instrction length*/, 32/*address length*/, 0/*wait cycles*/,
                          SPI_AITM_AS_FRAME_FORMAT/*spi address trans mode*/);
    spi_send_data_normal_dma(DMAC_CHANNEL0, SPI_CHANNEL, SPI_SLAVE_SELECT,data_buf, length, SPI_TRANS_INT);
}

void tft_fill_data(uint32_t *data_buf, uint32_t length)
{
    set_dcx_data();
    spi_init(SPI_CHANNEL, SPI_WORK_MODE_0, SPI_FF_OCTAL, 32, 0);
    spi_init_non_standard(SPI_CHANNEL, 0/*instrction length*/, 32/*address length*/, 0/*wait cycles*/,
                          SPI_AITM_AS_FRAME_FORMAT/*spi address trans mode*/);
    spi_fill_data_dma(DMAC_CHANNEL0, SPI_CHANNEL, SPI_SLAVE_SELECT,data_buf, length);
}

