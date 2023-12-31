/*
 *@Note
 * Header file for Main.c 

*/

#include "debug.h"
#include "AHT20.h"
#include "96OLEDI2C.h"
#include "SerialPort.h"
#include "i2c_common.h"
#include "SpiFlash.h"

/* SPI Mode Definition */
#define HOST_MODE   0
#define SLAVE_MODE   1

/* SPI Communication Mode Selection */
#define SPI_MODE   HOST_MODE

/* PWM Output Mode Definition */
#define PWM_MODE1 0
#define PWM_MODE2 1

/* PWM Output Mode Selection */
// #define PWM_MODE PWM_MODE1
#define PWM_MODE PWM_MODE2

#define LED_PIN         GPIO_Pin_0
#define LED_PORT        GPIOD

#define BUZ_PIN         GPIO_Pin_0
#define BUZ_PORT        GPIOC

#define LED_R           GPIO_Pin_2
#define LED_G           GPIO_Pin_4
#define LED_B           GPIO_Pin_3
#define LED_R_PORT      GPIOD
#define LED_G_PORT      GPIOC
#define LED_B_PORT      GPIOD

#define SW2_PIN         GPIO_Pin_1
#define SW2_PORT        GPIOA

#define SW3_PIN         GPIO_Pin_2
#define SW3_PORT        GPIOA

#define ANALOG1_PIN     GPIO_Pin_4
#define ANALOG1_PORT    GPIOD

void DigitSeperation(uint32_t number, uint8_t *buffer, uint8_t length);


