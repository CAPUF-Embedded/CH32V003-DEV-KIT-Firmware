#include "AHT20.h"

int8_t AHT20FReset(void)
{
    uint8_t ret[4] = {0};
    uint8_t buffer[4] = {0};

    buffer[0] = 0xBA;
    I2CWriteBytes(TH_SENSOR_ADDR, buffer, 2);

    Delay_Ms(100);

    I2CReadBytes(TH_SENSOR_ADDR, ret, 1);
    return ret[0];
}

//Send two bytes wake up command to the sensor
uint8_t AHT20FInit(void)
{
    uint8_t ret[4] = {0};
    uint8_t buffer[4] = {0};
    buffer[0] = 0xBE;
    buffer[1] = 0x08;
    buffer[2] = 0x00;
    I2CWriteBytes(TH_SENSOR_ADDR, buffer, 3);

    Delay_Ms(100);

    I2CReadBytes(TH_SENSOR_ADDR, ret, 1);
    return ret[0];
}

//Send two bytes wake up command to the sensor
uint8_t AHT20Measure(void)
{
    uint8_t ret[4] = {0};
    uint8_t buffer[4] = {0};

    buffer[0] = 0xAC;
    buffer[1] = 0x33;
    buffer[2] = 0x00;
    I2CWriteBytes(TH_SENSOR_ADDR, buffer, 3);

    Delay_Ms(100);

    I2CReadBytes(TH_SENSOR_ADDR, ret, 1);
    return ret[0];
}


void AHT20ReadTH(uint32_t *temperature, uint32_t *humidity)
{
    uint8_t retrn = 0;
    uint8_t rBytes[10] = {0};
    uint32_t temp = 0;

    I2CReadBytes(TH_SENSOR_ADDR, rBytes, 1);
    if((rBytes[0] & 0x08)==0)
    {
        retrn = AHT20FReset();
        retrn = AHT20FInit();
    }

    retrn = AHT20Measure();
    if((retrn & 0x01)== 0)
    {
        //read bytes
        I2CReadBytes(TH_SENSOR_ADDR, rBytes, 7);

    }

    // Calculate Humidity reading from the data received from the sensor
    temp = 0;
    temp = rBytes[1];
    temp <<= 8;
    temp |= rBytes[2];
    temp <<= 4;
    temp = temp | (rBytes[3] >> 4);

    *humidity = (((temp<<3) * 125)>>20);

    // Calculate Temperature reading from the data received from the sensor
    temp = 0;
    temp = rBytes[3] & 0x0F;
    temp <<= 8;
    temp |= rBytes[4];
    temp <<= 8;
    temp |= rBytes[5];
    *temperature = (((temp<<4) * 125) >> 20) - 500;

}
