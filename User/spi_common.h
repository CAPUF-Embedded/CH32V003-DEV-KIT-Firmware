#include "ch32v00x_spi.h"

#define SPI_CS_PIN                  GPIO_Pin_3
#define SPI_CS_PORT                 GPIOC

void SPISendReceiveBytes(uint8_t *sendData, uint8_t *getData, uint32_t length);
void SPISendBytes(uint8_t *sendData, uint32_t length);
void SPIReceiveBytes(uint8_t *getData, uint32_t length);
