#include <p18f4520.h>
#include "prototyper.h"

void Port_Init (void)
{
	TRISDbits.TRISD3 = 0;		// Make Digit 1's Enabling Pin an O/P pin 
	TRISDbits.TRISD4 = 0;		// Make Digit 2's Enabling Pin an O/P pin
	
	Digit1_Enable = 0;			// Disable Digit 2's Transistor 
	Digit2_Enable = 0; 			// Disable Digit 1's Transistor 
	
	TRISDbits.TRISD2 = 0;		// Pin Used to Check Power on Ckt
	LATDbits.LATD2   = 1;		// Disable Power Checking Pin 
	
	TRISC = 0x00;				// All Of Port C Are Outputs For Z 7Segment	
	LATC  = 0x00;				// Initialize PortC 
}

void TMR0_Config (void)
{
	INTCONbits.TMR0IF = 0;		// Reset Timer0 Interrupt Flag 
  
	T0CONbits.TMR0ON  = 0; 		// Disable Timer0 Until Configurataion 
	T0CONbits.T08BIT  = 0; 		// Configure Timer0 As a 16-bit 
	T0CONbits.T0CS	  = 0; 		// Configure Timer0 As a 16-bit Timer
	T0CONbits.PSA	  = 0; 		// Timer0 Prescaler is Assigned 
	
	T0CONbits.T0PS2	  = 1; 		// Select A Prescaler Value of 1:64
	T0CONbits.T0PS1	  = 0; 		// 
	T0CONbits.T0PS0	  = 1; 		// 
	
	TMR0H = 0xC2;				// 1 sec delay @ 4MHZ And a Prescaler Value of 1:64
	TMR0L = 0xF7;				//
	
	T0CONbits.TMR0ON = 1;		// Enable Timer0
}

void Interrupt_Init (void)
{
	INTCONbits.PEIE = 1;		// Enable Peripheral Interrupts 
	INTCONbits.GIE = 1;			// Enable Interrupts Globally 
	INTCONbits.TMR0IE = 1;		// Enable Timer0 Interrupt 	
}


