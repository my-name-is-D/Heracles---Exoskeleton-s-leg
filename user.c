/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__PIC24E__)
    	#include <p24Exxxx.h>
    #elif defined (__PIC24F__)||defined (__PIC24FK__)
	#include <p24Fxxxx.h>
    #elif defined(__PIC24H__)
	#include <p24Hxxxx.h>
    #endif
#endif

#include <stdint.h>          /* For uint32_t definition */
#include <stdbool.h>         /* For true/false definition */

#include "user.h"            /* variables/params used by user.c */

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

/* TODO Initialize User Ports/Peripherals/Project here */

void InitApp(void)
{
    /* Setup analog functionality and port direction */
    
    TRISBbits.TRISB12 = 1;      // Set RB12 as Input
    ANSBbits.ANSB12 = 0;         // Set A0 as digital IO
    INTCON2bits.INT2EP = 0;     // Rising edge
    IFS1bits.INT2IF = 0;        // Clear INT0 Interupt
    IEC1bits.INT2IE = 1;        // enable INT0 Interupt
    IPC7bits.INT2IP2 = 1;       // Priority
    IPC7bits.INT2IP1 = 1;
    IPC7bits.INT2IP0 = 0;
    
    TRISBbits.TRISB14 = 1;      // Set RB14 as Input
    ANSBbits.ANSB14 = 0;         // Set A0 as digital IO
    INTCON2bits.INT1EP = 0;     // Rising edge
    IFS1bits.INT1IF = 0;        // Clear INT0 Interupt
    IEC1bits.INT1IE = 1;        // enable INT0 Interupt
    IPC5bits.INT1IP2 = 1;       // Priority
    IPC5bits.INT1IP1 = 1;
    IPC5bits.INT1IP0 = 1;
    
    
    
    ANSAbits.ANSA0 = 0;         // Set A0 as digital IO
    TRISAbits.TRISA0 = 0;       // Set A0 as output
    TRISBbits.TRISB7 = 0;       // Set B7 as output
    TRISBbits.TRISB11 = 0;      // Set B11 as output
   
    //ADC
    //EMG
    TRISAbits.TRISA4 = 1;       // Set RA4 as input --> pin 12 an16
    ANSAbits.ANSA4 = 1;         // Set RA4as  analog IO
    
    //accelerometer
    TRISBbits.TRISB6 = 1;       // Set RB6 as input --> pin 15 an18
    ANSBbits.ANSB6 = 1;         // Set RB6 as  analog IO
    TRISBbits.TRISB8 = 1;       // Set RB8 as input --> pin 17 an20
    ANSBbits.ANSB8 = 1;         // Set RB8 as  analog IO
    TRISBbits.TRISB9 = 1;       // Set RA4 as input -->pin 18 an21
    ANSBbits.ANSB9 = 1;         // Set RA4as  analog IO
    
   
    
    /* Initialize peripherals */
}

