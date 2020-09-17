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

#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */
#include "adc.h"
#include "interrupts.h"
#include "pwm.h"
#include "accelerometer.h"
#include <libpic30.h>


/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

unsigned short pos = 0;  // On initialise la variable de la position : (0 = position de base/ 1 = entre les 2 / 2 = position max)

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/



int main(void)
{
    
    unsigned short ADC_VALUE=0, Y_acc=0, ADC_reduced=0; 
    unsigned short freq_reverse=500;  
    InitApp();          // PORTS Initialisation
    init_PWM();         // PWM Initialisation
    init_PWM2();        // PWM2 Initialisation
    init_ADC();         // ADC Initialisation
   
    
    while(1)
    {
        ADC_VALUE =  Average_Value_ADC(); 
       // Y_acc =  ADC_read_accY(); 
       // ADC_reduced = acc_use(Y_acc, ADC_VALUE);
       
        compute_movement(ADC_VALUE, freq_reverse);        //on calcul la fréquence de la pwm et le sens du moteur
    }
    return 0;    
}