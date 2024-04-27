/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18LF26K40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LEDG1 aliases
#define LEDG1_TRIS                 TRISAbits.TRISA0
#define LEDG1_LAT                  LATAbits.LATA0
#define LEDG1_PORT                 PORTAbits.RA0
#define LEDG1_WPU                  WPUAbits.WPUA0
#define LEDG1_OD                   ODCONAbits.ODCA0
#define LEDG1_ANS                  ANSELAbits.ANSELA0
#define LEDG1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LEDG1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LEDG1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LEDG1_GetValue()           PORTAbits.RA0
#define LEDG1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LEDG1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LEDG1_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define LEDG1_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define LEDG1_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define LEDG1_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define LEDG1_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define LEDG1_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set LEDB1 aliases
#define LEDB1_TRIS                 TRISAbits.TRISA2
#define LEDB1_LAT                  LATAbits.LATA2
#define LEDB1_PORT                 PORTAbits.RA2
#define LEDB1_WPU                  WPUAbits.WPUA2
#define LEDB1_OD                   ODCONAbits.ODCA2
#define LEDB1_ANS                  ANSELAbits.ANSELA2
#define LEDB1_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LEDB1_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LEDB1_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LEDB1_GetValue()           PORTAbits.RA2
#define LEDB1_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LEDB1_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LEDB1_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LEDB1_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LEDB1_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LEDB1_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LEDB1_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define LEDB1_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set LEDR1 aliases
#define LEDR1_TRIS                 TRISAbits.TRISA3
#define LEDR1_LAT                  LATAbits.LATA3
#define LEDR1_PORT                 PORTAbits.RA3
#define LEDR1_WPU                  WPUAbits.WPUA3
#define LEDR1_OD                   ODCONAbits.ODCA3
#define LEDR1_ANS                  ANSELAbits.ANSELA3
#define LEDR1_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LEDR1_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LEDR1_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LEDR1_GetValue()           PORTAbits.RA3
#define LEDR1_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LEDR1_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LEDR1_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define LEDR1_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define LEDR1_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define LEDR1_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define LEDR1_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define LEDR1_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set CSN aliases
#define CSN_TRIS                 TRISAbits.TRISA5
#define CSN_LAT                  LATAbits.LATA5
#define CSN_PORT                 PORTAbits.RA5
#define CSN_WPU                  WPUAbits.WPUA5
#define CSN_OD                   ODCONAbits.ODCA5
#define CSN_ANS                  ANSELAbits.ANSELA5
#define CSN_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define CSN_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define CSN_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define CSN_GetValue()           PORTAbits.RA5
#define CSN_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define CSN_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define CSN_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define CSN_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define CSN_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define CSN_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define CSN_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define CSN_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSELB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSELB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/