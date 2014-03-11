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

    /* Initialize peripherals */

    //CLKDIVbits.PLLEN = 1;  //set system clock to 32 MHz

    __builtin_write_OSCCONL(OSCCON & 0xBF); //unlock registers

    ANSA = 0x0000;  //all port A bits as digital
    ANSB = 0x8000;  //all port B bits except RB15/AN9 as digital

    TRISA = 0xFFFE; //bit 0 as output
    TRISB = 0xFFFF; //all inputs
    
    SR &= 0xFFF8;  //set CPU priority to 0
    INTCON1 |= 0X8000; //disable interrupt nesting

    __builtin_write_OSCCONL(OSCCON | 0x40); //lock IO pins

    T3CON = 0x8030; //Timer enabled, prescale 1:256, internal osc
    PR3 = 0x1600;  //T3 Period
    //IEC0bits.T3IE = 1;  //enable T3 interrupt
    //IFS0bits.T3IF = 0; //clear T3 interrupt flag
    //IPC2 |= 0x0007;  //set T3 interrupt priority

    AD1CHS = 0x0009; //select AN9/RB15 for conversion
    AD1CON2 = 0x0000; //use Vdd/Vss, no scan, interrupt every conversion, 16-bit word, always MUXA
    AD1CON1 = 0x8024; //ADC is on, uint format, T3 trigger, autostart after complete
    IEC0bits.AD1IE = 1; //enable AD1 interrupt
    IFS0bits.AD1IF = 0; //clear AD1 interrupt flag
    IPC3 |= 0x0070; //set AD1 interrupt priority
}

