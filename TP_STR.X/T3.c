#include "T3.h"

void tache3(void) {
    //unsigned char init = 0;
    
    while(1)
        {
        /*
        char b;
        b=0;
        b++;
            if (init == 0) {
                // Check if EEPROM is fresh (all 0xFF)
                if (EEPROM_Read(0x00) == 0xFF && 
                    EEPROM_Read(0x01) == 0xFF && 
                    EEPROM_Read(0x02) == 0xFF && 
                    EEPROM_Read(0x03) == 0xFF) {
                    kilometrage = 0;
                    // Write initial 0 value
                    EEPROM_Write(0x00, 0);
                    EEPROM_Write(0x01, 0);
                    EEPROM_Write(0x02, 0);
                    EEPROM_Write(0x03, 0);
                } else {
                    kilometrage = 0;
                    kilometrage |= (unsigned long)EEPROM_Read(0x00) << 24;
                    kilometrage |= (unsigned long)EEPROM_Read(0x01) << 16;
                    kilometrage |= (unsigned long)EEPROM_Read(0x02) << 8;
                    kilometrage |= (unsigned long)EEPROM_Read(0x03);
                }
                init = 1;
            }

            // Increment based on speed (0-6)
            kilometrage += vitesse;

            // Save to EEPROM periodically
            static unsigned int save_counter = 0;
            save_counter++;
            if (save_counter >= 1000) {
                save_counter = 0;
                EEPROM_Write(0x00, (kilometrage >> 24) & 0xFF);
                EEPROM_Write(0x01, (kilometrage >> 16) & 0xFF);
                EEPROM_Write(0x02, (kilometrage >> 8) & 0xFF);
                EEPROM_Write(0x03, kilometrage & 0xFF);
            }
          */
    }
}