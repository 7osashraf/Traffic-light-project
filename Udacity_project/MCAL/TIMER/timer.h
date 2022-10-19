/*
 * timer.h
 *
 * Created: 10/11/2022 8:07:27 AM
 *  Author: ENG HOSAM
 */ 


#ifndef TIMER_H_
#define TIMER_H_


#include "../../utilites/bit_maths.h"
#include "../../utilites/returnError.h"
#include "../../utilites/types.h"
#include "../../utilites/MemoryMap.h"
#include "../DIO/dio.h"


/*     Mode Define       */

#define normalMode  0x00
#define pwmMode 0x40
#define ctcMode 0x08
#define fPwmMode 0x48


/*       Timer Define        */

#define T0 0





EN_errorReturn_t timer_inti(uint8_t timerNumber,uint8_t timerMode);
EN_errorReturn_t startTimer(uint32_t timerNumber , uint32_t preScaler);
EN_errorReturn_t stopTimer(uint32_t timerNumber);
EN_errorReturn_t setInitialValue(uint8_t timerNumber , uint32_t initialValue);
EN_errorReturn_t time_0_Delay(uint32_t millis , uint32_t timerNumber , uint32_t preScaler , uint32_t clockFrequency);



#endif /* TIMER_H_ */