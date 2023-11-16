#include "ch32v00x_usart.h"
#include "string.h"

#define DEBUGPRINT

#define DEBUG_INFO      1
#define DEBUG_ALERT     2
#define DEBUG_ERROR     3

#define UART_BAUDRATE   115200
#define UART_TX_PIN     GPIO_Pin_5
#define UART_TX_PORT    GPIOD
#define UART_RX_PIN     GPIO_Pin_6
#define UART_RX_PORT    GPIOD

void UsartConfig(void);
void UARTDebugPrint(uint8_t type, uint8_t* buffer);
void UARTSendString(uint8_t* buffer);
void UARTSendBuffer(uint8_t* buffer, uint16_t length);


