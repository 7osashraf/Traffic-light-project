/*
 * dio.h
 *
 * Created: 10/11/2022 8:07:00 AM
 *  Author: ENG HOSAM
 */ 


#ifndef DIO_H_
#define DIO_H_


#include "../../utilites/bit_maths.h"
#include "../../utilites/returnError.h"
#include "../../utilites/types.h"
#include "../../utilites/MemoryMap.h"

//CPU freq
#define F_CPU 8000000UL


//all internal driver typedefs

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


//all drivers macros

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//Direction defines
#define IN 0
#define OUT 1

//Values defines
#define LOW 0
#define HIGH 1

//all drivers function prototype

EN_errorReturn_t DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);//initialize dio direction

EN_errorReturn_t DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);// write data to dio

EN_errorReturn_t DIO_toggle(uint8_t pinNumber, uint8_t portNumber);// toggle dio

EN_errorReturn_t DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);//read dio




#endif /* DIO_H_ */