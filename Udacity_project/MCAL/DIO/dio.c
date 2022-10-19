/*
 * dio.c
 *
 * Created: 10/11/2022 8:07:12 AM
 *  Author: ENG HOSAM
 */ 

#include "dio.h"

EN_errorReturn_t DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	switch(portNumber)
	{
		case PORT_A:
		if(direction == IN)
		{
			CLR_BIT(DDRA,pinNumber);
			//DDRA &= ~(1<<pinNumber);
		}
		else if(direction == OUT)
		{
			SET_BIT(DDRA,pinNumber);
			//DDRA |= (1<<pinNumber);
		}
		else
		{
			//error handing
		}
		break;
		
		case PORT_B:
		if(direction == IN)
		{
			CLR_BIT(DDRB,pinNumber);
			//DDRB &= ~(1<<pinNumber);
		}
		else if(direction == OUT)
		{
			SET_BIT(DDRB,pinNumber);
			//DDRB |= (1<<pinNumber);
		}
		else
		{
			//error handing
		}
		break;
		
		case PORT_C:
		if(direction == IN)
		{
			CLR_BIT(DDRC,pinNumber);
			//DDRC &= ~(1<<pinNumber);
		}
		else if(direction == OUT)
		{
			SET_BIT(DDRC,pinNumber);
			//DDRC |= (1<<pinNumber);
		}
		else
		{
			//error handing
		}
		break;
		
		case PORT_D:
		if(direction == IN)
		{
			CLR_BIT(DDRD,pinNumber);
			//DDRD &= ~(1<<pinNumber);
		}
		else if(direction == OUT)
		{
			SET_BIT(DDRD,pinNumber);
			//DDRD |= (1<<pinNumber);
		}
		else
		{
			//error handing
		}
		break;
	}
}

EN_errorReturn_t DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{
	switch(portNumber)
	{
		case PORT_A:
			if(value == LOW)
			{
				CLR_BIT(PORTA,pinNumber);
				//PORTA &= ~(1<<pinNumber);  // write 0
			}
			else if(value == HIGH)
			{
				SET_BIT(PORTA,pinNumber);
				//PORTA |= (1<<pinNumber); // write 1
			}
			else
			{
				//error handing
				return error;
			}
			return ok;
		
		case PORT_B:
			if(value == LOW )
			{
				CLR_BIT(PORTB,pinNumber);
				//PORTB &= ~(1<<pinNumber); // write 0
			}
			else if(value == HIGH)
			{
				SET_BIT(PORTB,pinNumber);
				//PORTB |= (1<<pinNumber); // write 1
			}
			else
			{
				//error handing
				return error;
			}
			return ok;
		
		case PORT_C:
			if(value == LOW )
			{
				CLR_BIT(PORTC,pinNumber);
				//PORTC &= ~(1<<pinNumber); // write 0
			}
			else if(value == HIGH)
			{
				SET_BIT(PORTC,pinNumber);
				//PORTC |= (1<<pinNumber); // write 1
			}
			else
			{
				//error handing
				return error;
			}
			return ok;
		
		case PORT_D:
		if(value == LOW )
		{
			CLR_BIT(PORTD,pinNumber);
			//PORTD &= ~(1<<pinNumber); // write 0
		}
		else if(value == HIGH)
		{
			SET_BIT(PORTD,pinNumber);
			//PORTD |= (1<<pinNumber); // write 1
		}
		else
		{
			//error handing
			return error;
		}
		return ok;
	}
}

EN_errorReturn_t DIO_toggle(uint8_t pinNumber, uint8_t portNumber)
{
	switch(portNumber)
	{
		case PORT_A:
		TOG_BIT(PORTA,pinNumber);
		//PORTA^=(1<<pinNumber);
		return ok;
		case PORT_B:
		TOG_BIT(PORTB,pinNumber);
		//PORTB^=(1<<pinNumber);
		return ok;
		case PORT_C:
		TOG_BIT(PORTC,pinNumber);
		//PORTC^=(1<<pinNumber);
		return ok;
		case PORT_D:
		TOG_BIT(PORTD,pinNumber);
		//PORTD^=(1<<pinNumber);
		return ok;
		default:
		return error;
		
	}
}

EN_errorReturn_t DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value)
{
	
	switch(portNumber)
	{
		case PORT_A:
		*value = GET_BIT(PORTA,pinNumber);
		return ok;
		
		case PORT_B:
		*value = GET_BIT(PORTB,pinNumber);
		return ok;
		
		case PORT_C:
		*value = GET_BIT(PORTC,pinNumber);
		return ok;
		
		case PORT_D:
		*value = GET_BIT(PORTD,pinNumber);
		return ok;
		
		default:
		//ERROR
		return error;
	}
}