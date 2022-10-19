/*
 * interrupt.c
 *
 * Created: 10/11/2022 8:08:20 AM
 *  Author: ENG HOSAM
 */ 

#include "interrupt.h"

static EN_errorReturn_t EXT0_Set_Edge(const ST_externalInterrupt_t* interrupt)
{
	if(interrupt == NULL)
	{
		return error;
	}
	else
	{
		switch(interrupt->source)
		{
			case EXTERNAL_INTERRUPT_0 :
				{
					switch(interrupt->edge)
					{
						case EXI_INT0_GENERATE_INTERRUPT_AT_LOW_LEVEL :
							EXI_INT0_SET_EDGE(interrupt->edge);
							break;
							
						case EXI_INT0_GENERATE_INTERRUPT_AT_HIGH_LEVEL:
							EXI_INT0_SET_EDGE(interrupt->edge);
							break;
						
						case EXI_INT0_GENERATE_INTERRUPT_AT_FALLING_EDGE :
							EXI_INT0_SET_EDGE(interrupt->edge);
							break;
						
						case EXI_INT0_GENERATE_INTERRUPT_AT_RISING_EDGE :
							EXI_INT0_SET_EDGE(interrupt->edge);
							break;
					}
				}
				break;
		}
	}
}

static EN_errorReturn_t EXT0_Set_Source(const ST_externalInterrupt_t* interrupt)
{
	if(interrupt == NULL)
	{
		return error;
	}
	else
	{
		switch(interrupt->source)
		{
			case EXTERNAL_INTERRUPT_0:
				SET_BIT(GICR, 6);
				break;
				
		}
	}
}

static void(*external_interrupt_0_call_back) (void) = NULL;


EN_errorReturn_t External_Interrupt_Init(const ST_externalInterrupt_t* interrupt)
{
	if(interrupt == NULL)
	{
		return error;
	}
	else
	{
		EXT0_Set_Edge(interrupt);
		EXT0_Set_Source(interrupt);
	}
	return ok;
}


EN_errorReturn_t External_Interrupt_Call_Back(const ST_externalInterrupt_t* interrupt)
{
	if(interrupt == NULL)
	{
		return error;
	}
	else
	{
		switch(interrupt->source)
		{
			case EXTERNAL_INTERRUPT_0:
				external_interrupt_0_call_back = interrupt->external_Interrupt_0_Request;
				break;
		}
	}
}


ISR(INT0_vect)
{
	if(external_interrupt_0_call_back != NULL)
	{
		external_interrupt_0_call_back();
	}
}