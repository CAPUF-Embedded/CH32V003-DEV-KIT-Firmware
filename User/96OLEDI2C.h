//#include "ch32v00x_i2c.h"
#include "i2c_common.h"

#define OLEDI2C_ADDR    0x3C

void OLEDI2CCMD(uint8_t deviceAddr, uint8_t command);
void OLEDI2CInit(void);
void OLEDI2CSetPage(uint8_t pageNumber);
void OLEDI2CSetCol(uint8_t col);
void OLEDI2CPutChar(uint8_t line, uint8_t startingColumn, char characterToPrint, uint8_t dataLength);
void OLEDI2CPutStr(uint8_t line, uint8_t startingColumn, char* stringToPrint, uint8_t stringLength);
void OLEDI2CFillScreen(uint8_t data);
void OLEDI2CWriteMuiltiByte(uint8_t deviceAddr, uint8_t memoryAddr, uint8_t *buffer, uint16_t length);
void OLEDI2CPattern(void);
void OLEDI2CDrawImage(const uint8_t* image);

