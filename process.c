#include <p18f4520.h>
#include <delays.h>
#include "prototyper.h"

/* 
*  The Delay For Switching The Transistors should be 
*  anywhere between 1ms and 15ms.  
*/ 

void DisplayDigit (int Incoming)
{
	int msd = 0;
	int lsd = 0;
	
	msd = Incoming / 10;			// Extract The First Number
	lsd = Incoming % 10;			// Extract The Second Number
	
	LATC = Display (msd); 			// Send The First Digit To PortC
	Digit1_Enable = 1; 				// Enable Digit1's Transitor 
	Delay1KTCYx(1);					// Wait For 1ms
	Digit1_Enable = 0; 				// Disable Digit1's Transitor 
		
	LATC = Display (lsd); 			// Send The Second Digit To PortC
	Digit2_Enable = 1; 				// Enable Digit2's Transitor
	Delay1KTCYx(1);					// Wait For 1ms
	Digit2_Enable = 0; 				// Disable Digit2's Transitor 
} 

unsigned char Display (int no)
{
	unsigned char pattern;
	unsigned char Segments [] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,
								0x7D,0x07,0x7F,0x6F};            // Numbers From 0-9 For Common Cathode 
	pattern = Segments [no];		
	return (pattern); 
}


