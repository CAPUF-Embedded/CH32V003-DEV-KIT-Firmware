#include "ch32v00x_spi.h"

#define SPI_CS_PIN                  GPIO_Pin_3
#define SPI_CS_PORT                 GPIOC
#define SPI_FLASH_WRITE_ENABLE      0x06
#define SPI_FLASH_WRITE_DISABLE     0x04
#define SPI_FLASH_SECTOR_ERASE      0x20
#define SPI_FLASH_32K_BLOCK_ERASE   0x52
#define SPI_FLASH_64K_BLOCK_ERASE   0xD8
#define SPI_FLASH_CHIP_ERASE        0xC7
#define SPI_FLASH_READ_DATA         0x03
#define SPI_FLASH_WRITE_PAGE        0x02


void SPIFlashReadID(uint8_t *spiFlashID);
void SPIFlashSendCMD(uint8_t command);
void SPIFlashEraseSector(uint32_t sectorNumber);
void SpiFlashReadData(uint32_t startAddress, uint8_t *data, uint32_t length);
void SpiFlashWritePage(uint32_t startAddress, uint8_t *data, uint32_t length);

