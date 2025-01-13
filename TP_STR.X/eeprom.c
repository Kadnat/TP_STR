/*
 * File:   eeprom.c
 * Author: nathanaelblavo
 *
 * Created on January 7, 2025, 1:18 PM
 */


#include "main.h"

void EEPROM_Write(unsigned char addr, unsigned char data) 
{
    // Select EEPROM memory
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    
    // Write address and data
    EEADR = addr;
    EEDATA = data;
    
    // Write sequence
    EECON1bits.WREN = 1;
    INTCONbits.GIE = 0;
    
    // Required sequence
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;
    
    INTCONbits.GIE = 1;
    EECON1bits.WREN = 0;
    
    // Wait for write to complete
    while(EECON1bits.WR);
}

unsigned char EEPROM_Read(unsigned char addr)
{
    // Select EEPROM memory
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    
    // Set address
    EEADR = addr;
    
    // Start read
    EECON1bits.RD = 1;
    
    // Return data
    return EEDATA;
}