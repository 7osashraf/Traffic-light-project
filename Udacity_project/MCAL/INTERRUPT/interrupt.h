/*
 * interrupt.h
 *
 * Created: 10/11/2022 8:08:03 AM
 *  Author: ENG HOSAM
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_


#include "../../utilites/bit_maths.h"
#include "../../utilites/returnError.h"
#include "../../utilites/types.h"
#include "../../utilites/MemoryMap.h"
#include "../DIO/dio.h"

#define EXI_INT0_GENERATE_INTERRUPT_AT_LOW_LEVEL      0x00
#define EXI_INT0_GENERATE_INTERRUPT_AT_HIGH_LEVEL      0x01
#define EXI_INT0_GENERATE_INTERRUPT_AT_FALLING_EDGE      0x02
#define EXI_INT0_GENERATE_INTERRUPT_AT_RISING_EDGE      0x03

#define EXI_INT1_GENERATE_INTERRUPT_AT_LOW_LEVEL      0x00
#define EXI_INT1_GENERATE_INTERRUPT_AT_HIGH_LEVEL      0x01
#define EXI_INT1_GENERATE_INTERRUPT_AT_FALLING_EDGE      0x02
#define EXI_INT1_GENERATE_INTERRUPT_AT_RISING_EDGE      0x03

#define EXI_INT2_GENERATE_INTERRUPT_AT_RISING_EDGE      0x01
#define EXI_INT2_GENERATE_INTERRUPT_AT_FALLING_EDGE      0x00


#define EXI_INT0_SET_EDGE(EDGE)                (MCUCR  |= EDGE)
#define EXI_INT1_SET_EDGE(EDGE)                (MCUCR  |= (EDGE<<2))
#define EXI_INT2_SET_EDGE(EDGE)                (MCUCSR |= (EDGE<<6))


typedef enum EN_sourceSelect_t
{
	EXTERNAL_INTERRUPT_0 = 0,
	EXTERNAL_INTERRUPT_1,
	EXTERNAL_INTERRUPT_2
}EN_sourceSelect_t;


typedef struct ST_externalInterrupt_t
{
	EN_sourceSelect_t source;
	uint8_t edge;
	void(*external_Interrupt_0_Request) (void);
	void(*external_Interrupt_1_Request) (void);
	void(*external_Interrupt_2_Request) (void);
}ST_externalInterrupt_t;


EN_errorReturn_t External_Interrupt_Init(const ST_externalInterrupt_t* interrupt);
EN_errorReturn_t External_Interrupt_Call_Back(const ST_externalInterrupt_t* interrupt);


#endif /* INTERRUPT_H_ */