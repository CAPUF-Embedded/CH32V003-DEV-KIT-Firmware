#include "i2c_common.h"


void I2CWriteBytes(uint8_t deviceAddress, uint8_t *dataBuffer, uint16_t length)
{

    uint8_t tmp = 0;
    while( I2C_GetFlagStatus( I2C1, I2C_FLAG_BUSY ) != RESET );
    I2C_GenerateSTART( I2C1, ENABLE );

    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_MODE_SELECT ) );
    I2C_Send7bitAddress( I2C1, (deviceAddress << 1), I2C_Direction_Transmitter );

    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED ) );

    for(tmp = 0; tmp < length; tmp++)
    {
        I2C_SendData( I2C1, (u8)(dataBuffer[tmp]) );
        while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );
    }
    I2C_GenerateSTOP( I2C1, ENABLE );


}
void I2CReadBytes(uint8_t deviceAddress, uint8_t *dataBuffer, uint16_t length)
{
    I2C_GenerateSTART( I2C1, ENABLE );
    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_MODE_SELECT ) );

    I2C_Send7bitAddress( I2C1, deviceAddress<<1, I2C_Direction_Receiver );

    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED ) );
    I2C_AcknowledgeConfig( I2C1, ENABLE );
    //length--;
    while(length)
    {
        if(length ==1) I2C_AcknowledgeConfig( I2C1, DISABLE );
        if( I2C_GetFlagStatus( I2C1, I2C_FLAG_RXNE ) !=  RESET )
        {
            dataBuffer[0] = I2C_ReceiveData( I2C1 );
            dataBuffer++;
            length--;
        }
    }
    I2C_GenerateSTOP( I2C1, ENABLE );
}

