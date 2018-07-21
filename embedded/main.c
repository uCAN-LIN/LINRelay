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
#include "open-LIN-c/open_lin_transport_layer.h"

#include "nvm.h"

typedef struct {
    l_u8 relay_open : 4;
    l_u8 relay_open_save : 4;
} t_relay_cmd; 

;
t_relay_cmd R_STAT_1_Data ={0,0};
t_relay_cmd R_CTR_1_Data = {0,0};

l_u8 diag_buffer[8] = {0,0,0,0,0,0,0,0};

extern open_lin_NAD_t open_lin_NAD;

typedef enum {
    R_STAT_1 = 0x00,
    R_CTR_1 = 0x01
}lin_cmd_t;

open_lin_frame_slot_t slot_array[] =
{
    {R_CTR_1,OPEN_LIN_FRAME_TYPE_RECEIVE,sizeof(R_CTR_1_Data),(l_u8 *)&R_CTR_1_Data},
    {R_STAT_1,OPEN_LIN_FRAME_TYPE_TRANSMIT,sizeof(R_STAT_1_Data),(l_u8 *)&R_STAT_1_Data},
    {OPEN_LIN_DIAG_REQUEST,OPEN_LIN_FRAME_TYPE_RECEIVE,sizeof(diag_buffer),diag_buffer},
    {OPEN_LIN_DIAG_RESPONSE,OPEN_LIN_FRAME_TYPE_TRANSMIT,sizeof(diag_buffer),diag_buffer}
};

open_lin_id_translation_item_t open_lin_id_translation_tab[] = 
{
    {R_CTR_1, R_CTR_1},
    {R_STAT_1,R_STAT_1},
    {OPEN_LIN_DIAG_REQUEST,OPEN_LIN_DIAG_REQUEST},
    {OPEN_LIN_DIAG_RESPONSE,OPEN_LIN_DIAG_RESPONSE},
};
      
const l_u8 lenght_of_slot_array = sizeof( slot_array ) / sizeof( open_lin_frame_slot_t );
const l_u8 lenght_of_translation_array = (sizeof(open_lin_id_translation_tab) / sizeof(open_lin_id_translation_tab[0]));

void update_lin_ids()
{
    l_u8 a;
    /* NAD updated, update frame translation_tab */
    for (a = 0; a < lenght_of_translation_array; a++)
    {
        open_lin_id_translation_item_t* item = &(open_lin_id_translation_tab[a]);        
        if ((item->id_in_lin_table != OPEN_LIN_DIAG_REQUEST) && (item->id_in_lin_table != OPEN_LIN_DIAG_RESPONSE))
        {
            item->input_id = slot_array[a].pid + open_lin_NAD;
          
        } else {
            /* for diag do nothing */
        }
    }    
}

void open_lin_sid_callback(open_lin_frame_slot_t* slot) {
    /* diagnostic request arrived, only one service is included so no checking done */
    /* save configuration */
    nvm_save_conf(open_lin_NAD);
    update_lin_ids();
}

void LIN_Slave_Initialize(void){

    open_lin_slave_init();
    open_lin_net_init(slot_array,lenght_of_slot_array);
}


void open_lin_on_rx_frame(open_lin_frame_slot_t *slot)
{
     switch(slot->pid){
        case R_CTR_1:
        {
            t_relay_cmd *p = (t_relay_cmd *)(slot->data_ptr);
            if (p->relay_open)
            {
                RELAY_OUT_SetLow();
            } else 
            {
                RELAY_OUT_SetHigh();
            }    
            R_STAT_1_Data.relay_open = R_CTR_1_Data.relay_open;
            R_STAT_1_Data.relay_open_save = R_CTR_1_Data.relay_open_save;
            break;
        }
        case R_STAT_1:
            
            break;
        default:
            break;       
     }  
     open_lin_transport_layer_handle(slot);
}

void main(void)
{
    SYSTEM_Initialize();
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();    
  
    LIN_Slave_Initialize();
   
    open_lin_NAD = nvm_read_nad();
    update_lin_ids();
    
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