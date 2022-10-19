/*
 * led.h
 *
 * Created: 10/11/2022 8:06:03 AM
 *  Author: ENG HOSAM
 */ 


#ifndef LED_H_
#define LED_H_


#include "../../utilites/bit_maths.h"
#include "../../utilites/returnError.h"
#include "../../utilites/types.h"
#include "../../utilites/MemoryMap.h"
#include "../../MCAL/TIMER/timer.h"
#include "../../MCAL/DIO/dio.h"

EN_errorReturn_t LED_inti(uint8_t ledPort, uint8_t ledPin);
EN_errorReturn_t LED_on(uint8_t ledPort, uint8_t ledPin);
EN_errorReturn_t LED_off(uint8_t ledPort, uint8_t ledPin);
EN_errorReturn_t LED_toggle(uint8_t ledPort, uint8_t ledPin);
void dely_5s_2LED(uint8_t pinNumber_1,uint8_t pinNumber_2,uint8_t portNumber_1,uint8_t portNumber_2);



#endif /* LED_H_ */