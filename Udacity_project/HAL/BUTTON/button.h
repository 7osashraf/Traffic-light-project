/*
 * button.h
 *
 * Created: 10/11/2022 8:04:40 AM
 *  Author: ENG HOSAM
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


#include "../../utilites/bit_maths.h"
#include "../../utilites/returnError.h"
#include "../../utilites/types.h"
#include "../../utilites/MemoryMap.h"
#include "../../MCAL/DIO/dio.h"

//Button  State macros
#define LOW 0
#define  HIGH 1


//initialize
EN_errorReturn_t BUTTON_inti(uint8_t buttonPort, uint8_t buttonPin);

//read
EN_errorReturn_t BUTTON_read(uint8_t buttonPort, uint8_t buttonPin,uint8_t *value);




#endif /* BUTTON_H_ */