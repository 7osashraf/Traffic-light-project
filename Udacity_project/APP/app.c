/*
 * app.c
 *
 * Created: 10/11/2022 8:03:31 AM
 *  Author: ENG HOSAM
 */ 


#include "app..h"

uint8_t carState;

ST_externalInterrupt_t ixt_0 =
{
	.source = EXTERNAL_INTERRUPT_0,
	.edge = EXI_INT0_GENERATE_INTERRUPT_AT_RISING_EDGE,
	.external_Interrupt_0_Request = callBack
};

void callBack()
{
	pedestrianMode();
}


void AppStart()
{
	//initialized led in port A
	LED_inti(PORT_A,0);
	LED_inti(PORT_A,1);
	LED_inti(PORT_A,2);
	
	
	//initialized led in port B
	LED_inti(PORT_B,0);
	LED_inti(PORT_B,1);
	LED_inti(PORT_B,2);
	
	//INTRRUPT
	sei();
	External_Interrupt_Init(&ixt_0);
	External_Interrupt_Call_Back(&ixt_0);
	
	while(1)
	{
		normal_Mode();
	}
	
	
}
void normal_Mode()
{
	// put car state GREEN
	carState = CAR_GREEN;
	
	
	// TURN ON GREEN in NORMAL MODE
	LED_on(PORT_A,0);
	//TURN ON RED IN pedestrian Mode
	LED_on(PORT_B,2);
	//  WAIT 5S
	dely_5s();
	
	
	// put car state YELLOW
	carState = CAR_YELLOW;
	
	
	dely_5s_2LED(1,1,PORT_A,PORT_B);
	
	
	// TURN OFF GREEN in NORMAL MODE
	LED_off(PORT_A,0);
	// TURN OFF RED in pedestrian Mode
	LED_off(PORT_B,2);
	
	
	// put car state RED
	carState = CAR_RED;
	
	// TURN ON RED in NORMAL MODE
	LED_on(PORT_A,2);
	// TURN ON GREEN IN PEDESTRIAN MODE
	LED_on(PORT_B,0);
	
		
	// WAIT 5 SECOND
	dely_5s();
	
	
	// put car state YELLOW
	carState = CAR_YELLOW;
	
	// TOGGLE YELLOW
	dely_5s_2LED(1,1,PORT_A,PORT_B);
	
	
	// TURN OFF RED in NORMAL MODE
	LED_off(PORT_A,2);
	// TURN OFF GREEN IN PEDESTRIAN MODE
	LED_off(PORT_B,0);
	
	
	
}
void pedestrianMode()
{
	off_all_led();
	if(carState == 0 || carState == 1 )
	{
		// turn on pedestrian red led
		LED_on(PORT_B,2);
		// turn on car green led 
		LED_on(PORT_A,0);
		
		
		//toggle yellow led for 5s
		dely_5s_2LED(1,1,PORT_A,PORT_B);
		
		// turn off pedestrian red led
		LED_off(PORT_B,2);
		// turn off car green led
		LED_off(PORT_A,0);
		
		
		// cars' Red LED and pedestrian Green LEDs are on for five seconds
		LED_on(PORT_A,2);
		LED_on(PORT_B,0);
		dely_5s();
		
		
	}
	//if interrupt when car red is turn on
	else if (carState == 2)
	{
		// the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds
		LED_on(PORT_A,2);
		LED_on(PORT_B,0);
		dely_5s();
		
		
	}
	
	
	// turn off car red led 
	LED_off(PORT_A,2);
	
	//toggle yellow led for 5s
	dely_5s_2LED(1,1,PORT_A,PORT_B);
	
	// pedestrian's Green LED is still on
	LED_on(PORT_B,0);
	
	// delay 5s
	dely_5s();
	
	//  pedestrian Green LED will be off
	LED_off(PORT_B,0);
	
	//pedestrian Red LED and the cars' Green LED turn on
	LED_on(PORT_B,2);
	LED_on(PORT_A,0);
	
	
}

void off_all_led()
{
	LED_off(PORT_A,0);
	LED_off(PORT_A,1);
	LED_off(PORT_A,2);
	
	LED_off(PORT_B,0);
	LED_off(PORT_B,1);
	LED_off(PORT_B,2);
	
}