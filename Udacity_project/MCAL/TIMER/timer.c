/*
 * timer.c
 *
 * Created: 10/11/2022 8:07:41 AM
 *  Author: ENG HOSAM
 */ 

#include "timer.h"
uint32_t overFlowCounter = 0;

EN_errorReturn_t timer_inti(uint8_t timerNumber , uint8_t timerMode)
{
	
	switch(timerNumber)
	{
		case T0:
			if(timerMode == normalMode)
				{
					TCCR0 = normalMode;
				}
			else if(timerMode == pwmMode)
				{
				TCCR0 = pwmMode;
				}
			else if(timerMode == ctcMode)
				{
				TCCR0 = ctcMode;
				}
			else if(timerMode == fPwmMode)
				{
				TCCR0 = fPwmMode;
				}
			else
				{
					return error;
				}
			break;
		
		default:
		//Error
		return error;
	}
		return ok;	
}

EN_errorReturn_t startTimer(uint32_t timerNumber , uint32_t preScaler)
{
	switch(timerNumber)
	{
		case T0:
		if (preScaler == 0)
		{
			SET_BIT(TCCR0,0);
		}
		else if (preScaler == 8)
		{
			SET_BIT(TCCR0,1);
		}
		else if (preScaler == 64)
		{
			SET_BIT(TCCR0,0);
			SET_BIT(TCCR0,1);
		}
		else if (preScaler == 256)
		{
			SET_BIT(TCCR0,2);
		}
		else if (preScaler == 1024)
		{
			SET_BIT(TCCR0,0);
		}
		else
		{
			return error;
		}
		return ok;
		default:
		return error;
	}
}

EN_errorReturn_t stopTimer(uint32_t timerNumber)
{
	switch(timerNumber)
	{
		case T0:
		TCCR0 &= 0xF8;
		return ok;
		default:
		return error;
	}
}

EN_errorReturn_t setInitialValue(uint8_t timerNumber , uint32_t initialValue)
{
	switch(timerNumber)
	{
		case T0:
		TCNT0 = initialValue;
		return ok;
		default:
		return error;
	}
}

EN_errorReturn_t time_0_Delay(uint32_t millis , uint32_t timerNumber , uint32_t preScaler , uint32_t clockFrequency)
{
	float tickTime  = preScaler / clockFrequency;
	uint32_t numberOfOverFlow = (millis / (256 * tickTime));
	switch(timerNumber)
	{
		case T0:
		if(startTimer(timerNumber,preScaler) == ok)
		{
			while(overFlowCounter < numberOfOverFlow )
			{
				//wait until the overflow flag to be set
				while((TIFR & (1<<0) == 0));
				//CLEAR THE OVERFLOW FALG
				TIFR |= (1<<0);
				overFlowCounter++;
			}
			overFlowCounter = 0;
			if (stopTimer(timerNumber) == ok)
			{
				return ok;
			}
			else
			{
				return error;
			}
		}
		else
		{
			return error;
		}
		
		default:
		return error;
	}
	
}

void dely_5s()
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
		TCNT0 = 56;
	}
	
}