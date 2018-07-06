/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F15325
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

#include "open-LIN-c/open_lin_types.h"
#include "open-LIN-c/open_lin_network_layer.h"
#include "open-LIN-c/open_lin_slave_data_layer.h"

l_u8 R_STAT_1_Data[8] = {0,0,0,0,0,0,0,0};
l_u8 R_CTR_1_Data[8] = {0,1,2,3,4,5,6,7};
l_u8 dataBuffer3[8] = {0,0,0,0,0,0,0,0};

typedef enum {
    R_CTR_1 = 0x02,
    R_STAT_1 = 0x03
}lin_cmd_t;

open_lin_frame_slot_t slot_array[] =
{
    {R_CTR_1,OPEN_LIN_FRAME_TYPE_RECEIVE,sizeof(R_CTR_1_Data),R_CTR_1_Data},
    {R_STAT_1,OPEN_LIN_FRAME_TYPE_TRANSMIT,sizeof(R_STAT_1_Data),R_STAT_1_Data},
    {OPEN_LIN_DIAG_REQUEST,OPEN_LIN_FRAME_TYPE_RECEIVE,sizeof(dataBuffer3),dataBuffer3}
};

const l_u8 lenght_of_slot_array = sizeof( slot_array ) / sizeof( open_lin_frame_slot_t );

void LIN_Slave_Initialize(void){

    open_lin_slave_init();
    open_lin_net_init(slot_array,lenght_of_slot_array);
}

uint8_t cnt = 0;

void open_lin_on_rx_frame(open_lin_frame_slot_t *slot)
{
     switch(slot->pid){
        case R_CTR_1:
            cnt ++;
            R_STAT_1_Data[0] = cnt;
            if ((slot->data_ptr[1]) == 1)
            {
                RELAY_OUT_SetLow();
            } else 
            {
                RELAY_OUT_SetHigh();
            }
            R_STAT_1_Data[1] = slot->data_ptr[0];            
            break;
        case R_STAT_1:
            break;
        default:
            break;
         
     }  
}


void main(void)
{
    SYSTEM_Initialize();
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();    
  
    LIN_Slave_Initialize();
    
    while (1)
    {
        if (EUSART1_is_rx_ready())
        {
            open_lin_slave_rx_header(EUSART1_Read());
        }
    }
    
}
/**
 End of File
*/