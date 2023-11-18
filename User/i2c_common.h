#include "ch32v00x_i2c.h"

void I2CWriteBytes(uint8_t deviceAddress, uint8_t *dataBuffer, uint16_t length);
void I2CReadBytes(uint8_t deviceAddress, uint8_t *dataBuffer, uint16_t length);
