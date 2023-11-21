#include "spi_common.h"

void SPISendReceiveBytes(uint8_t *sendData, uint8_t *getData, uint32_t length)
{
    uint32_t loop = 0;
    for(loop = 0; loop < length; loop++)
    {
        //Send SPI Byte
        while( SPI_I2S_GetFlagStatus( SPI1, SPI_I2S_FLAG_TXE ) == RESET ); // wait while flag is zero or TX buffer not empty
        SPI_I2S_SendData( SPI1, sendData[loop] );

        Delay_Us(SPI_DELAY);
        //Receive SPI Byte
        while(SPI_I2S_GetFlagStatus( SPI1, SPI_I2S_FLAG_RXNE ) == RESET ); // wait while flag is zero or RX buffer is empty
        getData[loop] = SPI_I2S_ReceiveData( SPI1 );
        //Delay_Us(SPI_DELAY);
    }
}

void SPISendBytes(uint8_t *sendData, uint32_t length)
{
    uint32_t loop = 0;
    for(loop = 0; loop < length; loop++)
    {
        //Send SPI Byte
        while( SPI_I2S_GetFlagStatus( SPI1, SPI_I2S_FLAG_TXE ) == RESET ); // wait while flag is zero or TX buffer not empty
        SPI_I2S_SendData( SPI1, sendData[loop] );
        Delay_Us(SPI_DELAY);
    }

}

void SPIReceiveBytes(uint8_t *getData, uint32_t length)
{
    uint32_t loop = 0;
    //uint8_t data[20] = {0};
    for(loop = 0; loop < length; loop++)
    {
        //Send SPI Byte
        while( SPI_I2S_GetFlagStatus( SPI1, SPI_I2S_FLAG_TXE ) == RESET ); // wait while flag is zero or TX buffer not empty
        SPI_I2S_SendData( SPI1, 0x00 );

        Delay_Us(SPI_DELAY);
        //Receive SPI Byte
        while(SPI_I2S_GetFlagStatus( SPI1, SPI_I2S_FLAG_RXNE ) == RESET ); // wait while flag is zero or RX buffer is empty
        getData[loop] = SPI_I2S_ReceiveData( SPI1 );
        //Delay_Us(SPI_DELAY);
    }

}
