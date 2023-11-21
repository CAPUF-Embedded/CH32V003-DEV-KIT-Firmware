#include "SerialPort.h"


/*********************************************************************
 * @fn      USARTx_CFG
 *
 * @brief   Initializes the USART2 & USART3 peripheral.
 *
 * @return  none
 */
void UsartConfig(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    USART_InitTypeDef USART_InitStructure = {0};
    NVIC_InitTypeDef  NVIC_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_USART1, ENABLE);
    //GPIO_PinRemapConfig(GPIO_PartialRemap2_USART1, ENABLE);

    /* USART1 TX-->D.5   RX-->D.6 */
    GPIO_InitStructure.GPIO_Pin = UART_TX_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(UART_TX_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = UART_RX_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(UART_RX_PORT, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = UART_BAUDRATE;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

    USART_Init(USART1, &USART_InitStructure);
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);;

    USART_Cmd(USART1, ENABLE);
}

void UARTDebugPrint(uint8_t type, uint8_t* buffer)
{
#ifdef DEBUGPRINT
    if(type == DEBUG_INFO)
    {
        UARTSendString("[INFO]:");
    }
    else if (type == DEBUG_ERROR)
    {
        UARTSendString("[ERROR]:");
    }
    else if (type == DEBUG_ALERT)
    {
        UARTSendString("[ALERT]:");
    }
    UARTSendString(buffer);
#endif

}

void UARTSendString(uint8_t* buffer)
{
    uint16_t tmp = 0;
    uint16_t len = 0;

    len = strlen(buffer);

    for(tmp =0; tmp < len; tmp++)
    {
        while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET); /* waiting for sending finish */
        USART_SendData(USART1, buffer[tmp]);
    }

}

void UARTSendBuffer(uint8_t* buffer, uint16_t length)
{
    uint16_t tmp = 0;


    for(tmp =0; tmp < length; tmp++)
    {
        while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET) /* waiting for sending finish */
        {
        }
        USART_SendData(USART1, buffer[tmp]);
    }

}
