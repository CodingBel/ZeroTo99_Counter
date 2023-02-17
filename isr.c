#include <p18f4520.h>
#include "prototyper.h"

volatile unsigned char overflow = 0;
#pragma code My_Hiprio_Int = 0x08   // Address for High Priority Interrupts

void My_Hiprio_Int (void)
{
	_asm 
		GOTO Chk_Isr
	_endasm 
}
#pragma code 

#pragma interrupt Chk_Isr    		// Used For Defining High Priority Interrupts
void Chk_Isr (void)
{
	if (INTCONbits.TMR0IF == 1)		// A Timer0 Overflow Interrupt Has Occured
	{
		INTCONbits.TMR0IF = 0;		// Reset Timer0 Overflow Interrupt Flag
		overflow = 1;				// Raise Virtual Flag
		
		TMR0H = 0xC2;				// Reload Timer0 for a 1 sec delay @ 4MHZ And a Prescaler Value of 1:64
		TMR0L = 0xF7;				
	}

}






