/*
 *@Note
 * Header file for AHT20.c

*/

//#include "ch32v00x_i2c.h"
#include "i2c_common.h"


#define TH_SENSOR_ADDR  0x38

//Reset the Sensor
int8_t AHT20FReset(void);
//Initialize the Sensor
uint8_t AHT20FInit(void);
//Start the Measurement
uint8_t AHT20Measure(void);
//Read Temperature and Humidity
void AHT20ReadTH(uint32_t *temperature, uint32_t *humidity);
