/* 
 * File:   ucan.h
 * Author: ay7vi2
 *
 * Created on 25 lipca 2018, 21:26
 */

#ifndef UCAN_H
#define	UCAN_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum {
    UCAN_RELAY = 0x00,
    UCAN_MOTOR_DRIVER = 0x01,
    UCAN_HALL_SENSOR = 0x02,
} t_ucan_device_type;  
    
typedef struct {
    l_u8 relay_open : 4;
    l_u8 relay_open_save : 4;
} t_ucan_relay_cmd; 

typedef struct {
    t_ucan_device_type uCANDeviceType;
} t_ucan_device_stat;



#ifdef	__cplusplus
}
#endif

#endif	/* UCAN_H */

