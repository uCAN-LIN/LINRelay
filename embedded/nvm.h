/* 
 * File:   nvm.h
 * Author: ay7vi2
 *
 * Created on July 20, 2018, 10:19 AM
 */

#ifndef NVM_H
#define	NVM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"
    
uint8_t nvm_read_nad(void);
void nvm_save_conf(uint8_t nad);

#ifdef	__cplusplus
}
#endif

#endif	/* NVM_H */

