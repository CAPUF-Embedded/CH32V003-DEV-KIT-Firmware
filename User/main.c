/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2022/08/08
 * Description        : Main program body.
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/
/*
 *@Note
 *This is a demo code developed for hardware demonstration of CAPUF Embedded's CH32V003 DEV KIT
 *It has code for the following
 *1. UART - PC terminal will get  the debug prints while code is running, if user sends a string(5 bytes) from PC, DEV KIT will respond back
 *2. RGB LED is controlled via PWM (Timer 1 and Timer 2) - before while one code demonstrate RED, GREEN BLUE Light
 *3. User LED is there, code is used to blinking the LED in the main code
 *4. User SW are there SW2, SW3, currently, they receive the interrupt and does nothing.
 *5. 10K Potentiometer is there for ADC ( Reading is shown on the OLED Display)
 *6. OLED is connected over I2C
 *7. Temperature / Humidity Sensor AHT20/AHT20-F is also connected over I2C ( Readings are shown on the OLED Display)
 *8. 8Mbit /1MB NOR Flash is connected on the SPI Interface. User can write and Read/Write(up to 10 characters) data via PC Command $RD#, $WD:ABCD#
 *
*/

#include "main.h"

/* Global define */

/* Global typedef */

/* Global Variable */

uint8_t RxBuffer1[256] = {0};
uint8_t RxCnt1 = 0;
uint8_t Rxfinish1 = 0;

uint8_t SW2Flag = 0;
uint8_t SW3Flag = 0;

uint32_t T = 0;
uint32_t H = 0;

uint8_t digitSep[4] = {0};

uint32_t adcReading = 0;
uint8_t adcFlag = 0;

uint16_t GetMCUFlashSize( void )
{
    return( *( uint16_t * )0x1FFFF7E0 );
}

uint32_t GetMCUUID1( void )
{
    return( *( uint32_t * )0x1FFFF7C4 );
}
uint32_t GetMCUUID2( void )
{
    return( *( uint32_t * )0x1FFFF7EC );
}

uint32_t GetMCUUID3( void )
{
    return( *( uint32_t * )0x1FFFF7F0 );
}

void RGB_PWMConfig(u16 arr, u16 psc, u16 ccp)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    TIM_OCInitTypeDef TIM_OCInitStructure = {0};
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOC | RCC_APB2Periph_TIM1, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    TIM_TimeBaseInitStructure.TIM_Period = arr;
    TIM_TimeBaseInitStructure.TIM_Prescaler = psc;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);

#if (PWM_MODE == PWM_MODE1)
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;

#elif (PWM_MODE == PWM_MODE2)
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;

#endif

    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = ccp;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC1Init(TIM1, &TIM_OCInitStructure);
    TIM_OC4Init(TIM1, &TIM_OCInitStructure);
    TIM_OC2Init(TIM2, &TIM_OCInitStructure);

    TIM_CtrlPWMOutputs(TIM1, ENABLE);
    TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Disable);
    TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Disable);
    TIM_ARRPreloadConfig(TIM1, ENABLE);
    TIM_Cmd(TIM1, ENABLE);

    TIM_CtrlPWMOutputs(TIM2, ENABLE);
    TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Disable);
    TIM_ARRPreloadConfig(TIM2, ENABLE);
    TIM_Cmd(TIM2, ENABLE);
}

void SetRGB(uint32_t RGB)
{
    TIM_SetCompare2(TIM2, (RGB & 0x000000ff) * 1000 / 0xff);
    RGB >>= 8;
    TIM_SetCompare4(TIM1, (RGB & 0x000000ff) * 1000 / 0xff);
    RGB >>= 8;
    TIM_SetCompare1(TIM1, (RGB & 0x000000ff) * 1000 / 0xff);
}

void BlinkLED(void)
{
    GPIO_SetBits(LED_PORT, LED_PIN);
    Delay_Ms(50);
    GPIO_ResetBits(LED_PORT, LED_PIN);
    Delay_Ms(50);


    GPIO_SetBits(LED_PORT, LED_PIN);
    Delay_Ms(50);
    GPIO_ResetBits(LED_PORT, LED_PIN);
    Delay_Ms(50);


    GPIO_SetBits(LED_PORT, LED_PIN);
    Delay_Ms(500);
}

void Beep(void)
{
    GPIO_SetBits(BUZ_PORT, BUZ_PIN);
    Delay_Ms(250);
    GPIO_ResetBits(BUZ_PORT, BUZ_PIN);
    Delay_Ms(250);


    GPIO_SetBits(BUZ_PORT, BUZ_PIN);
    Delay_Ms(50);
    GPIO_ResetBits(BUZ_PORT, BUZ_PIN);
    Delay_Ms(50);

    GPIO_SetBits(BUZ_PORT, BUZ_PIN);
    Delay_Ms(50);
    GPIO_ResetBits(BUZ_PORT, BUZ_PIN);
    Delay_Ms(50);
}
/*********************************************************************

* @fn      ADC_Function_Init

*

* @brief   Initializes ADC collection.

*

* @return  none

*/

void ADCConfig(void)
{
    ADC_InitTypeDef ADC_InitStructure = {0};
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    NVIC_InitTypeDef NVIC_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);

    GPIO_InitStructure.GPIO_Pin = ANALOG1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init(ANALOG1_PORT, &GPIO_InitStructure);

    ADC_DeInit(ADC1);
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigInjecConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = 1;
    ADC_Init(ADC1, &ADC_InitStructure);

    ADC_InjectedSequencerLengthConfig(ADC1, 1);
    ADC_InjectedChannelConfig(ADC1, ADC_Channel_7, 1, ADC_SampleTime_241Cycles);
    ADC_ExternalTrigInjectedConvCmd(ADC1, DISABLE);

    NVIC_InitStructure.NVIC_IRQChannel = ADC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    ADC_Calibration_Vol(ADC1, ADC_CALVOL_50PERCENT);
    ADC_ITConfig(ADC1, ADC_IT_JEOC, ENABLE);
    ADC_Cmd(ADC1, ENABLE);

    ADC_ResetCalibration(ADC1);

    while (ADC_GetResetCalibrationStatus(ADC1))
        ;

    ADC_StartCalibration(ADC1);
    while (ADC_GetCalibrationStatus(ADC1))
        ;

}
/*********************************************************************
 * @fn      GPIO_Toggle_INIT
 *
 * @brief   Initializes GPIOD.0
 *
 * @return  none
 */
void GPIOConfig(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitStructure.GPIO_Pin = LED_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = BUZ_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(BUZ_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LED_R;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_R_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LED_G;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_G_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LED_B;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_B_PORT, &GPIO_InitStructure);

}


void KeysConfig(void)
{
       GPIO_InitTypeDef GPIO_InitStructure = {0};
       EXTI_InitTypeDef EXTI_InitStructure = {0};
       NVIC_InitTypeDef NVIC_InitStructure = {0};

       RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA, ENABLE);


       //Configuration for GPIO Input on A1
       GPIO_InitStructure.GPIO_Pin = SW2_PIN;
       GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
       GPIO_Init(SW2_PORT, &GPIO_InitStructure);

        //Configuration for GPIO Input on A2
        GPIO_InitStructure.GPIO_Pin = SW3_PIN;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
        GPIO_Init(SW3_PORT, &GPIO_InitStructure);

       /* GPIOA ----> EXTI_Line1 */
       GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource1);
       EXTI_InitStructure.EXTI_Line = EXTI_Line1;
       EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
       EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
       EXTI_InitStructure.EXTI_LineCmd = ENABLE;
       EXTI_Init(&EXTI_InitStructure);

       /* GPIOA ----> EXTI_Line2 */
      GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource2);
      EXTI_InitStructure.EXTI_Line = EXTI_Line2;
      EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
      EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
      EXTI_InitStructure.EXTI_LineCmd = ENABLE;
      EXTI_Init(&EXTI_InitStructure);

       NVIC_InitStructure.NVIC_IRQChannel = EXTI7_0_IRQn;
       NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
       NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
       NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
       NVIC_Init(&NVIC_InitStructure);
}


void IIC_Init(u32 bound, u16 address)
{
    GPIO_InitTypeDef GPIO_InitStructure={0};
    I2C_InitTypeDef I2C_InitTSturcture={0};

    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE );
    RCC_APB1PeriphClockCmd( RCC_APB1Periph_I2C1, ENABLE );

    GPIO_InitStructure.GPIO_Pin = I2C_SCL_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init( I2C_SCL_PORT, &GPIO_InitStructure );

    GPIO_InitStructure.GPIO_Pin = I2C_SDA_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init( I2C_SDA_PORT, &GPIO_InitStructure );

    I2C_InitTSturcture.I2C_ClockSpeed = bound;
    I2C_InitTSturcture.I2C_Mode = I2C_Mode_I2C;
    I2C_InitTSturcture.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitTSturcture.I2C_OwnAddress1 = address;
    I2C_InitTSturcture.I2C_Ack = I2C_Ack_Enable;
    I2C_InitTSturcture.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_Init( I2C1, &I2C_InitTSturcture );

    I2C_Cmd( I2C1, ENABLE );

    I2C_AcknowledgeConfig( I2C1, ENABLE );
}


void DigitSeperation(uint32_t number, uint8_t *buffer, uint8_t length)
{
    while(length)
    {
        buffer[length-1] = (number%10)+'0';
        number /= 10;
        length--;
    }
}

void EXTI7_0_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

/*********************************************************************
 * @fn      EXTI0_IRQHandler
 *
 * @brief   This function handles EXTI0 Handler.
 *
 * @return  none
 */
void EXTI7_0_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line1)!=RESET)
    {
        SW2Flag = 1;
        EXTI_ClearITPendingBit(EXTI_Line1);     /* Clear Flag */
    }
    if(EXTI_GetITStatus(EXTI_Line2)!=RESET)
    {
        SW3Flag = 1;
        EXTI_ClearITPendingBit(EXTI_Line2);     /* Clear Flag */
    }
}

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    /*
uint16_t flashSize = 0;
uint32_t uid1 = 0;
uint32_t uid2 = 0;
uint32_t uid3 = 0;
*/


    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    SystemCoreClockUpdate();
    Delay_Init();
    

    //flashSize = GetMCUFlashSize();
    //uid1 = GetMCUUID1();
    //uid2 = GetMCUUID2();
    //uid3 = GetMCUUID3();
    GPIOConfig();
    KeysConfig();

    UsartConfig();

    IIC_Init(I2C_BAUD, I2C_SELF_ADDR);

    OLEDI2CInit();
    ADCConfig();

    Beep();
    UARTDebugPrint(0, "\r\n\r\n");
    UARTDebugPrint(DEBUG_INFO, "CH32V003 DEV KIT 1.0\r\n");
    UARTDebugPrint(DEBUG_INFO, "DEVELOPED BY: CAPUF EMBEDDED\r\n");
    UARTDebugPrint(DEBUG_INFO, "UART: 115200-1-n\r\n");
    UARTDebugPrint(DEBUG_INFO, "POWER UP BEEP\r\n");
    Delay_Ms(500);

    // Draw Patterns on OLED Display at Power Up
    OLEDI2CPattern();
    UARTDebugPrint(DEBUG_INFO, "OLED CONFIG DONE\r\n");
    Delay_Ms(10);

    ADC_SoftwareStartInjectedConvCmd(ADC1, ENABLE);
    UARTDebugPrint(DEBUG_INFO, "ADC CONFIG DONE\r\n");

    RGB_PWMConfig(1000 - 1, 48 - 1, 0);
    SetRGB(0x00FFFFFF);//RGB LED OFF
    UARTDebugPrint(DEBUG_INFO, "RGB LED CONFIG DONE\r\n");

    UARTDebugPrint(DEBUG_INFO, "SYSTEM CONFIG COMPLETE\r\n");

    OLEDI2CPutStr(2, 0, "  CH32V003 DEV KIT", 18);
    OLEDI2CPutStr(3, 0, "    DEVELOPED BY", 16);
    OLEDI2CPutStr(4, 0, "   CAPUF EMBEDDED", 17);
    OLEDI2CPutStr(5, 0, "    WWW.CAPUF.IN", 16);
    Delay_Ms(2000);

    //RGB LED TEST
    UARTDebugPrint(DEBUG_INFO, "RGB LED TEST COLOR\r\n");
    SetRGB(0x0000FFFF); // RED
    Delay_Ms(500);
    SetRGB(0x00FF00FF); // GREEN
    Delay_Ms(500);
    SetRGB(0x00FFFF00); // BLUE
    Delay_Ms(500);
    SetRGB(0x00FFFFFF);//RGB LED OFF

    OLEDI2CFillScreen(0x00); // Clear OLED Display
    UARTDebugPrint(DEBUG_INFO, "ENTERING SUPERLOOP\r\n");

    while(1)
    {

        OLEDI2CPutStr(0, 0, "CH32V003 DEV KIT", 16);
        UARTDebugPrint(DEBUG_INFO, "MEASURE T&H\r\n");

        AHT20ReadTH(&T, &H);

        DigitSeperation(H, digitSep, 3);

        //Send Humidity reading on debug message
        UARTDebugPrint(DEBUG_INFO, "HUMIDITY: ");
        UARTSendBuffer(digitSep, 2);
        UARTDebugPrint(0, ".");
        UARTSendBuffer(digitSep+2, 1);
        UARTDebugPrint(0, " %RH\r\n");

        //Display Humidity Reading on the Display
        OLEDI2CPutStr(2, 0, "HUMIDITY: ", 10);
        OLEDI2CPutStr(2, 60, digitSep, 2);
        OLEDI2CPutStr(2, 72, ".", 1);
        OLEDI2CPutStr(2, 78, digitSep+2, 1);
        OLEDI2CPutStr(2, 84, " %RH   ", 7);

        DigitSeperation(T, digitSep, 3);

        //Send Temperature reading on debug message
        UARTDebugPrint(DEBUG_INFO, "TEMPERATURE: ");
        UARTSendBuffer(digitSep, 2);
        UARTDebugPrint(0, ".");
        UARTSendBuffer(digitSep+2, 1);
        UARTDebugPrint(0, " Deg C\r\n");

        //Display Humidity Reading on the Display
        OLEDI2CPutStr(4, 0, "TEMPERATURE: ", 13);
        OLEDI2CPutStr(4, 78, digitSep, 2);
        OLEDI2CPutStr(4, 90, ".", 1);
        OLEDI2CPutStr(4, 96, digitSep+2, 1);
        OLEDI2CPutStr(4, 102, "C", 1);

        //If ADC conversion is completed
        if(adcFlag ==1)
        {
          adcReading = ADC_GetInjectedConversionValue(ADC1, ADC_InjectedChannel_1);
          adcReading = (adcReading * 325)/100; // Converting to real voltage w.r.t. VCC 3.3V
          adcFlag = 0;
          ADC_SoftwareStartInjectedConvCmd(ADC1, ENABLE);
        }

        DigitSeperation(adcReading, digitSep, 4);
        OLEDI2CPutStr(6, 0, "POT VOLTAGE: ", 13);
        OLEDI2CPutStr(6, 78, digitSep, 4);
        OLEDI2CPutStr(6, 102, "mV", 2);

        UARTDebugPrint(DEBUG_INFO, "POT VOLTAGE: ");
        UARTSendBuffer(digitSep, 4);
        UARTDebugPrint(0, "mV\r\n");
        Delay_Ms(100);

        UARTDebugPrint(DEBUG_INFO, "LED BLINK\r\n");
        BlinkLED();


        if(Rxfinish1)
        {
            UARTDebugPrint(DEBUG_INFO, "UART DATA RECEIVED :)\r\n");
            Rxfinish1 = 0;
        }


    }
}




void ADC1_IRQHandler() __attribute__((interrupt("WCH-Interrupt-fast")));

/**

 * The function ADC1_IRQHandler handles the interrupt for ADC1 and prints the value of the injected

 * conversion.

 */

void ADC1_IRQHandler()
{

    if (ADC_GetITStatus(ADC1, ADC_IT_JEOC) == SET)
    {
        adcFlag = 1;
        adcReading = ADC_GetInjectedConversionValue(ADC1, ADC_InjectedChannel_1);
        ADC_ClearITPendingBit(ADC1, ADC_IT_JEOC);
    }

}

void USART1_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

/*********************************************************************
 * @fn      USART1_IRQHandler
 *
 * @brief   This function handles USART3 global interrupt request.
 *
 * @return  none
 */

void USART1_IRQHandler(void)
{
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
    {
        RxBuffer1[RxCnt1++] = USART_ReceiveData(USART1);

        if(RxCnt1 >= 5)
        {
            //USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);
            RxCnt1 = 0;
            Rxfinish1 = 1;
        }
    }
}

