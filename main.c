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

/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

int16_t main(void)
{

    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize IO ports and peripherals */
    InitApp();

    while(1)
    {
        //Idle();
    }
}

//void __attribute__((interrupt,auto_psv)) _T3Interrupt(void)
void __attribute__((interrupt,auto_psv)) _ADC1Interrupt(void)
{
    //IFS0bits.T3IF = 0;  //clear flag
    IFS0bits.AD1IF = 0;  //clear flag
    if ((PORTA & 0x0002) == 0)
    {
        PORTA = 0x0000;
    }
    else
    {
        PORTA = 0x0001 & (~PORTA);
    }
    PR3 = (ADC1BUF0*9) + 20; //set new period to value from potentiometer
}