#include <p18f4520.h>

#define Digit1_Enable LATDbits.LATD3
#define Digit2_Enable LATDbits.LATD4

void DisplayDigit (int);
unsigned char Display (int);
void Port_Init (void);

void TMR0_Config (void);
void Interrupt_Init (void);
void Chk_Isr (void);

