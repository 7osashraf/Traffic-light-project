/*
 * button.c
 *
 * Created: 10/11/2022 8:04:20 AM
 *  Author: ENG HOSAM
 */ 

#include "button.h"

EN_errorReturn_t BUTTON_inti(uint8_t buttonPort, uint8_t buttonPin)
{
	if (DIO_init(buttonPin,buttonPort,IN) == 0)
	{
		return ok;
	}
	else
	{
		return error;
	}
	
}


EN_errorReturn_t BUTTON_read(uint8_t buttonPort, uint8_t buttonPin,uint8_t *value)
{
	if (DIO_read(buttonPin,buttonPort,value) == 0)
	{
		return ok;
	}
	else
	{
		return error;
	}
}