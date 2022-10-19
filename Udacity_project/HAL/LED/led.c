/*
 * led.c
 *
 * Created: 10/11/2022 8:05:43 AM
 *  Author: ENG HOSAM
 */ 

#include "led.h"

EN_errorReturn_t LED_inti(uint8_t ledPort, uint8_t ledPin)
{
	if(DIO_init(ledPin,ledPort,OUT) == 0)
	{
		return ok;
	}
	else
	{
		return error;
	}
}


EN_errorReturn_t LED_on(uint8_t ledPort, uint8_t ledPin)
{
	
	if(DIO_write(ledPin,ledPort, HIGH) == 0)
	{
		return ok;
	}
	else
	{
		return error;
	}
}


EN_errorReturn_t LED_off(uint8_t ledPort, uint8_t ledPin)
{
	if(DIO_write(ledPin,ledPort, LOW) == 0)
	{
		return ok;
	}
	else
	{
		return error;
	}
}
EN_errorReturn_t LED_toggle(uint8_t ledPort, uint8_t ledPin)
{
	
	if(DIO_toggle(ledPin,ledPort) == 0)
	{
		return ok;
	}
	else
	{
		return error;
	}
}

void dely_5s_2LED(uint8_t pinNumber_1,uint8_t pinNumber_2,uint8_t portNumber_1,uint8_t portNumber_2)
{
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	
	//SET PRESCALLER
	startTimer(T0,8);
	
	//initial value
	TCNT0 = 56;
	
	for (uint16_t i=0;  i <25000; i++)
	{
		while(TCNT0);
		if((i % 2500) == 0) 
		{
			LED_toggle(portNumber_1,pinNumber_1);
			LED_toggle(portNumber_2,pinNumber_2);	
		}
		TCNT0 = 56;
	}
	
}