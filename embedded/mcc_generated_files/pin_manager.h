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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F15325
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
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

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA5 procedures
#define RA5_SetHigh()               do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()                do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()                do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()              PORTAbits.RA5
#define RA5_SetDigitalInput()       do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()      do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetPullup()             do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_ResetPullup()           do { WPUAbits.WPUA5 = 0; } while(0)
#define RA5_SetAnalogMode()         do { ANSELAbits.ANSA5 = 1; } while(0)
#define RA5_SetDigitalMode()        do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RELAY_OUT aliases
#define RELAY_OUT_TRIS                 TRISCbits.TRISC3
#define RELAY_OUT_LAT                  LATCbits.LATC3
#define RELAY_OUT_PORT                 PORTCbits.RC3
#define RELAY_OUT_WPU                  WPUCbits.WPUC3
#define RELAY_OUT_OD                   ODCONCbits.ODCC3
#define RELAY_OUT_ANS                  ANSELCbits.ANSC3
#define RELAY_OUT_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RELAY_OUT_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RELAY_OUT_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RELAY_OUT_GetValue()           PORTCbits.RC3
#define RELAY_OUT_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RELAY_OUT_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RELAY_OUT_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define RELAY_OUT_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define RELAY_OUT_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define RELAY_OUT_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define RELAY_OUT_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define RELAY_OUT_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()               do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()                do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()                do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()       do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()      do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set LIN_EN aliases
#define LIN_EN_TRIS                 TRISCbits.TRISC5
#define LIN_EN_LAT                  LATCbits.LATC5
#define LIN_EN_PORT                 PORTCbits.RC5
#define LIN_EN_WPU                  WPUCbits.WPUC5
#define LIN_EN_OD                   ODCONCbits.ODCC5
#define LIN_EN_ANS                  ANSELCbits.ANSC5
#define LIN_EN_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LIN_EN_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LIN_EN_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LIN_EN_GetValue()           PORTCbits.RC5
#define LIN_EN_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LIN_EN_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LIN_EN_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define LIN_EN_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define LIN_EN_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define LIN_EN_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define LIN_EN_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define LIN_EN_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

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