#include "ch32v00x_i2c.h"

#define I2C_BAUD        400000
#define I2C_SELF_ADDR   0x44

#define I2C_SCL_PIN     GPIO_Pin_2
#define I2C_SDA_PIN     GPIO_Pin_1
#define I2C_SCL_PORT    GPIOC
#define I2C_SDA_PORT    GPIOC

void I2CWriteBytes(uint8_t deviceAddress, uint8_t *dataBuffer, uint16_t length);
void I2CReadBytes(uint8_t deviceAddress, uint8_t *dataBuffer, uint16_t length);
