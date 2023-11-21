#include "SpiFlash.h"

uint8_t SPIFlashCheckBusy(void)
{
    uint8_t txBuf[1] = {0};
    uint8_t rxBuf[1] = {0};
    uint8_t status = 0;

    GPIO_ResetBits(SPI_CS_PORT, SPI_CS_PIN); // CS LOW
    txBuf[0] = SPI_FLASH_STATUS_REG1;
    SPISendBytes((uint8_t*)txBuf, 1);// send read command for status register 1 (0x05)
    SPIReceiveBytes((uint8_t*)rxBuf, 1);
    GPIO_SetBits(SPI_CS_PORT, SPI_CS_PIN); // CS HIGH

    status = 0x01 & rxBuf[0];
    return status;

}
void SPIFlashReadID(uint8_t *spiFlashID)
{

    uint8_t txBuf[4] = {0};

    txBuf[0] = 0x9F;
    txBuf[1] = 0x00;
    txBuf[2] = 0x00;
    txBuf[3] = 0x00;

    GPIO_ResetBits(SPI_CS_PORT, SPI_CS_PIN); // CS LOW

    SPISendReceiveBytes(txBuf, spiFlashID, 4);

    GPIO_SetBits(SPI_CS_PORT, SPI_CS_PIN); // CS HIGH
}

void SPIFlashSendCMD(uint8_t command)
{
    uint8_t tmp = 0;

    GPIO_ResetBits(SPI_CS_PORT, SPI_CS_PIN); // CS LOW

    //Send SPI Byte
    while( SPI_I2S_GetFlagStatus( SPI1, SPI_I2S_FLAG_TXE ) == RESET ); // wait while flag is zero
    SPI_I2S_SendData( SPI1, command );

    Delay_Us(100);
    //Receive SPI Byte
    while(SPI_I2S_GetFlagStatus( SPI1, SPI_I2S_FLAG_RXNE ) == RESET ); // wait while flag is non zero
    tmp = SPI_I2S_ReceiveData( SPI1 );

    GPIO_SetBits(SPI_CS_PORT, SPI_CS_PIN); // CS HIGH

}

void SPIFlashEraseSector(uint32_t sectorNumber)
{
    uint8_t txBuf[4] = {0};
    //uint8_t tmp = 1;

    txBuf[0] = SPI_FLASH_SECTOR_ERASE;
    txBuf[1] = sectorNumber >> 16;
    txBuf[2] = sectorNumber >> 8;
    txBuf[3] = sectorNumber;

    SPIFlashSendCMD(SPI_FLASH_WRITE_ENABLE);

    GPIO_ResetBits(SPI_CS_PORT, SPI_CS_PIN); // CS LOW
    SPISendBytes(txBuf, 4);
    GPIO_SetBits(SPI_CS_PORT, SPI_CS_PIN); // CS HIGH

    SPIFlashSendCMD(SPI_FLASH_WRITE_DISABLE);

    Delay_Ms(50);

    /*
    while(tmp)
    {
        tmp = SPIFlashCheckBusy();
        Delay_Ms(1);
    }
    */

}

void SpiFlashReadData(uint32_t startAddress, uint8_t *data, uint32_t length)
{
    uint8_t txBuf[4] = {0};

    txBuf[0] = SPI_FLASH_READ_DATA;
    txBuf[1] = startAddress >> 16;
    txBuf[2] = startAddress >> 8;
    txBuf[3] = startAddress;

    GPIO_ResetBits(SPI_CS_PORT, SPI_CS_PIN); // CS LOW

    SPISendBytes(txBuf, 4);

    SPIReceiveBytes(data, length);

    GPIO_SetBits(SPI_CS_PORT, SPI_CS_PIN); // CS HIGH
}

void SpiFlashWritePage(uint32_t startAddress, uint8_t *data, uint32_t length)
{
    uint8_t txBuf[4] = {0};
    //uint8_t tmp = 1;

    txBuf[0] = SPI_FLASH_WRITE_PAGE;
    txBuf[1] = startAddress >> 16;
    txBuf[2] = startAddress >> 8;
    txBuf[3] = startAddress;

    SPIFlashSendCMD(SPI_FLASH_WRITE_ENABLE);

    GPIO_ResetBits(SPI_CS_PORT, SPI_CS_PIN); // CS LOW

    SPISendBytes(txBuf, 4);

    SPISendBytes(data, length);

    GPIO_SetBits(SPI_CS_PORT, SPI_CS_PIN); // CS HIGH

    SPIFlashSendCMD(SPI_FLASH_WRITE_DISABLE);

    Delay_Ms(10);
    /*
    while(tmp)
    {
        tmp = SPIFlashCheckBusy();
        Delay_Ms(1);
    }
    */

}
