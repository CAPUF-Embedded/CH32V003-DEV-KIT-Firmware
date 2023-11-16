#include "AHT20.h"

int8_t AHT20FReset(void)
{
    uint8_t ret[4] = {0};
    while( I2C_GetFlagStatus( I2C1, I2C_FLAG_BUSY ) != RESET );
    I2C_GenerateSTART( I2C1, ENABLE );

    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_MODE_SELECT ) );
    I2C_Send7bitAddress( I2C1, (TH_SENSOR_ADDR << 1), I2C_Direction_Transmitter );

    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED ) );


    I2C_SendData( I2C1, (u8)(0xBA) );
    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

    I2C_GenerateSTOP( I2C1, ENABLE );

    Delay_Ms(100);

    I2CReadBytes(TH_SENSOR_ADDR, &ret, 1);
    return ret[0];
}

//Send two bytes wake up command to the sensor
uint8_t AHT20FInit(void)
{
    uint8_t ret[4] = {0};
    while( I2C_GetFlagStatus( I2C1, I2C_FLAG_BUSY ) != RESET );
    I2C_GenerateSTART( I2C1, ENABLE );

    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_MODE_SELECT ) );
    I2C_Send7bitAddress( I2C1, (TH_SENSOR_ADDR << 1), I2C_Direction_Transmitter );

    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED ) );


    I2C_SendData( I2C1, (u8)(0xBE) );
    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

    I2C_SendData( I2C1, (u8)(0x08) );
    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

    I2C_SendData( I2C1, (u8)(0x00) );
    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );
    I2C_GenerateSTOP( I2C1, ENABLE );

    Delay_Ms(100);

    I2CReadBytes(TH_SENSOR_ADDR, &ret, 1);
    return ret[0];
}

//Send two bytes wake up command to the sensor
uint8_t AHT20Measure(void)
{
    uint8_t ret[4] = {0};
    while( I2C_GetFlagStatus( I2C1, I2C_FLAG_BUSY ) != RESET );
    I2C_GenerateSTART( I2C1, ENABLE );

    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_MODE_SELECT ) );
    I2C_Send7bitAddress( I2C1, (TH_SENSOR_ADDR << 1), I2C_Direction_Transmitter );

    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED ) );


    I2C_SendData( I2C1, (u8)(0xAC) );
    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

    I2C_SendData( I2C1, (u8)(0x33) );
    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

    I2C_SendData( I2C1, (u8)(0x00) );
    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );
    I2C_GenerateSTOP( I2C1, ENABLE );

    Delay_Ms(100);

    I2CReadBytes(TH_SENSOR_ADDR, &ret, 1);
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
