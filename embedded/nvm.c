#include "nvm.h"
#include "mcc_generated_files/memory.h"

uint8_t nvm_read_nad(void)
{
    uint16_t dataeeAddr = 0x1f80;
    return DATAEE_ReadByte(dataeeAddr);
    
//    uint16_t    flashAddr = 0x1f80;
//    return FLASH_ReadWord(flashAddr);
}

void nvm_save_conf(uint8_t nad)
{
    uint16_t dataeeAddr = 0x1f80;
    DATAEE_WriteByte(dataeeAddr, nad); 

//    uint16_t    writeData = nad + (((uint16_t)nad) * 0x0100);
//    uint16_t    flashAddr = 0x1f80;
//    uint16_t    Buf[ERASE_FLASH_BLOCKSIZE];
//    FLASH_WriteWord(flashAddr, Buf, writeData);    
}

