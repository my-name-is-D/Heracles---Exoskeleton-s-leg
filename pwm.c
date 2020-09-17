/*
 * File:   pwm.c
 * Author: Louis
 *
 * Created on 11 avril 2019, 17:10
 */


#define etat_pwm_1 CCP1CON1Lbits.CCPON
#define etat_pwm_2 CCP2CON1Lbits.CCPON
#define vitesse_pwm_1 CCP1RA
#define vitesse_pwm_2 CCP2RA
 

#include "pwm.h"

void init_PWM(void)
{
    
    // Set MCCP operating mode
    CCP1CON1Lbits.CCSEL = 0;            // Set MCCP operating mode (OC mode)
    CCP1CON1Lbits.MOD = 0b0101;         // Set mode (Buffered Dual-Compare/PWM mode)
    
    //Configure MCCP Timebase
    CCP1CON1Lbits.TMR32 = 0;            // Set timebase width (16-bit)
    CCP1CON1Lbits.TMRSYNC = 0;          // Set timebase synchronization (Synchronized)
    CCP1CON1Lbits.CLKSEL = 0b000;       // Set the clock source (Tcy)
    CCP1CON1Lbits.TMRPS = 0b00;         // Set the clock pre-scaler (1:1)
    CCP1CON1Hbits.TRIGEN = 0;           // Set Sync/Triggered mode (Synchronous)
    CCP1CON1Hbits.SYNC = 0b00000;       // Select Sync/Trigger source (Self-sync)
    
    //Configure MCCP output for PWM signal
    CCP1CON2Hbits.OCAEN = 1;            // Enable desired output signals (OC1A)
    CCP1CON3Hbits.OUTM = 0b000;         // Set advanced output modes (Standard output)
    CCP1CON3Hbits.POLACE = 0;           // Configure output polarity (Active High)
    CCP1TMRL = 0x0000;                  // Initialize timer prior to enable module.
    CCP1PRL = 0x00AA;                   // Configure timebase period
    CCP1RA = 0x00AA;                    // Set the rising edge compare value
    CCP1RB = 0x00AA;                    // Set the falling edge compare value 1023 values
    CCP1CON1Lbits.CCPON = 1;            // enable PWM1

}

void init_PWM2(void)
{
    
    // Set MCCP operating mode
    CCP2CON1Lbits.CCSEL = 0;            // Set MCCP operating mode (OC mode)
    CCP2CON1Lbits.MOD = 0b0101;         // Set mode (Buffered Dual-Compare/PWM mode)
    //Configure MCCP Timebase
    CCP2CON1Lbits.TMR32 = 0;            // Set timebase width (16-bit)
    CCP2CON1Lbits.TMRSYNC = 0;          // Set timebase synchronization (Synchronized)
    CCP2CON1Lbits.CLKSEL = 0b000;       // Set the clock source (Tcy)
    CCP2CON1Lbits.TMRPS = 0b00;         // Set the clock pre-scaler (1:1)
    CCP2CON1Hbits.TRIGEN = 0;           // Set Sync/Triggered mode (Synchronous)
    CCP2CON1Hbits.SYNC = 0b00000;       // Select Sync/Trigger source (Self-sync)
    //Configure MCCP output for PWM signal
    CCP2CON2Hbits.OCAEN = 1;            // Enable desired output signals (OC2A)
    CCP2CON3Hbits.OUTM = 0b000;         // Set advanced output modes (Standard output)
    CCP2CON3Hbits.POLACE = 0;           // Configure output polarity (Active High)
    CCP2TMRL = 0x0000;                  // Initialize timer prior to enable module.
    CCP2PRL = 0x00AA;                   // Configure timebase period //1023=3ff
    CCP2RA = 0x00AA;                    // Set the rising edge compare value
    CCP2RB = 0x00AA;                    // Set the falling edge compare value 1023 values
    CCP2CON1Lbits.CCPON = 1;            // enable PWM1
}

void PWM_activated(unsigned short direction, unsigned short vitesse)
{
   if(direction == 0)
    {
       
	   
       etat_pwm_1 = 1;                   // We activate PWM 1
       vitesse_pwm_1 = vitesse/6;        // We put "freq_pwm" for the fréquence of PWM 1 (divided per 6 is for have a frequency above 20kHz) 
       
       
       vitesse_pwm_2 = 0x0000;                             
       etat_pwm_2 = 1;                   // We put PWM 2 at 5V constant
        
    }
   
    else if(direction == 1)
    {
       
        vitesse_pwm_1 = 0x0000;
        etat_pwm_1 = 1;                   // We put PWM 1 at 5V constant  
       
        
        etat_pwm_2 = 1;                   // We activate PWM 2 
        vitesse_pwm_2 = vitesse/6;        // We put "freq_pwm" for the fréquence of PWM 1 (divided per 6 is for have a frequency above 20kHz) 
    }
   
    else
    {
        etat_pwm_1 = 0;                   // We shut dowm PWM 1
        etat_pwm_2 = 0;                   // We shut dowm PWM 2
    }
}