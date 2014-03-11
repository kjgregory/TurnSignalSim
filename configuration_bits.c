/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
// FBS
    #pragma config BWRP = OFF               // Boot Segment Write Protect (Disabled)
    #pragma config BSS = OFF                // Boot segment Protect (No boot program flash segment)

    // FGS
    #pragma config GWRP = OFF               // General Segment Write Protect (General segment may be written)
    #pragma config GSS0 = OFF               // General Segment Code Protect (No Protection)

    // FOSCSEL
    #pragma config FNOSC = FRC              // Oscillator Select (Fast RC Oscillator with Postscaler and PLL Module (FRCDIV+PLL))
    #pragma config SOSCSRC = DIG            // SOSC Source Type (Analog Mode for use with crystal)
    #pragma config LPRCSEL = HP             // LPRC Oscillator Power and Accuracy (High Power, High Accuracy Mode)
    #pragma config IESO = ON                // Internal External Switch Over bit (Internal External Switchover mode enabled (Two-speed Start-up enabled))

    // FOSC
    #pragma config POSCMOD = NONE           // Primary Oscillator Configuration bits (Primary oscillator disabled)
    #pragma config OSCIOFNC = OFF           // CLKO Enable Configuration bit (CLKO output disabled)
    #pragma config POSCFREQ = HS            // Primary Oscillator Frequency Range Configuration bits (Primary oscillator/external clock input frequency greater than 8MHz)
    #pragma config SOSCSEL = SOSCHP         // SOSC Power Selection Configuration bits (Secondary Oscillator configured for high-power operation)
    #pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Both Clock Switching and Fail-safe Clock Monitor are disabled)

    // FWDT
    #pragma config WDTPS = PS32768          // Watchdog Timer Postscale Select bits (1:32768)
    #pragma config FWPSA = PR128            // WDT Prescaler bit (WDT prescaler ratio of 1:128)
    #pragma config FWDTEN = OFF              // Watchdog Timer Enable bits (WDT enabled in hardware)
    #pragma config WINDIS = OFF             // Windowed Watchdog Timer Disable bit (Standard WDT selected(windowed WDT disabled))

    // FPOR
    #pragma config BOREN = BOR3             // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware, SBOREN bit disabled)
    #pragma config LVRCFG = OFF             //  (Low Voltage regulator is not available)
    #pragma config PWRTEN = ON              // Power-up Timer Enable bit (PWRT enabled)
    #pragma config I2C1SEL = PRI            // Alternate I2C1 Pin Mapping bit (Use Default SCL1/SDA1 Pins For I2C1)
    #pragma config BORV = V18               // Brown-out Reset Voltage bits (Brown-out Reset set to lowest voltage (1.8V))
    #pragma config MCLRE = ON               // MCLR Pin Enable bit (RA5 input pin enabled,MCLR disabled)

    // FICD
    #pragma config ICS = PGx1               // ICD Pin Placement Select bits (EMUC/EMUD share PGC1/PGD1)

    // FDS
    #pragma config DSWDTPS = DSWDTPSF       // Deep Sleep Watchdog Timer Postscale Select bits (1:2,147,483,648 (25.7 Days))
    #pragma config DSWDTOSC = LPRC          // DSWDT Reference Clock Select bit (DSWDT uses Low Power RC Oscillator (LPRC))
    #pragma config DSBOREN = ON             // Deep Sleep Zero-Power BOR Enable bit (Deep Sleep BOR enabled in Deep Sleep)
    #pragma config DSWDTEN = ON             // Deep Sleep Watchdog Timer Enable bit (DSWDT enabled)

#elif defined(__C30__)
    #if defined(__PIC24E__)
    	#include <p24Exxxx.h>
    #elif defined (__PIC24F__)||defined (__PIC24FK__)
	#include <p24Fxxxx.h>
    #elif defined(__PIC24H__)
	#include <p24Hxxxx.h>
    #endif
#endif

/******************************************************************************/
/* Configuration Bits                                                         */
/*                                                                            */
/* This is not all available configuration bits for all PIC24 devices.        */
/* Refer to the PIC24 device specific .h file in the compiler                 */
/* support\PIC24x\h (x=F,H,E) directory for complete options specific to the  */
/* selected device.  For additional information about what the hardware       */
/* configurations mean in terms of device operation, refer to the device      */
/* datasheet 'Special Features' chapter.                                      */
/*                                                                            */
/* A feature of MPLAB X is the 'Generate Source Code to Output' utility in    */
/* the Configuration Bits window.  Under Window > PIC Memory Views >          */
/* Configuration Bits, a user controllable configuration bits window is       */
/* available to Generate Configuration Bits source code which the user can    */
/* paste into this project.                                                   */
/******************************************************************************/

/* TODO Fill in your configuration bits from the config bits generator here.  */
