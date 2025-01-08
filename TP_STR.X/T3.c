#include "T3.h"

void tache3(void) {
    counter_T3 = 0;
    passageT3 = 0;
    unsigned long kilometrage = 0;
    
    if (EEPROM_Read(0x00) == 0xFF && 
                    EEPROM_Read(0x01) == 0xFF && 
                    EEPROM_Read(0x02) == 0xFF && 
                    EEPROM_Read(0x03) == 0xFF) {
                    km = {0};
                    // Write initial 0 value
                    EEPROM_Write(0x00, 0);
                    EEPROM_Write(0x01, 0);
                    EEPROM_Write(0x02, 0);
                    EEPROM_Write(0x03, 0);
                } else {
                    km = {0};
                    km[0] = EEPROM_Read(0x00);
                    km[1] = EEPROM_Read(0x01);
                    km[2] = EEPROM_Read(0x02);
                    km[3] = EEPROM_Read(0x03);
                }
    
    while(1)
        {

            // Increment based on speed (0-6)
            kilometrage += vitesse;
            km[0] = kilometrage & 0xFF;
            km[1] = (kilometrage >> 8) & 0xFF;
            km[2] = (kilometrage >> 16) & 0xFF;
            km[3] = (kilometrage >> 24) & 0xFF;

            // Save to EEPROM periodically
            if(passageT3 == 0)
            {
                counter_T3++;
                if (counter_T3 >= 10) {
                    counter_T3 = 0;
                    EEPROM_Write(0x00, km[0]);
                    EEPROM_Write(0x01, km[1]);
                    EEPROM_Write(0x02, km[2]);
                    EEPROM_Write(0x03, km[3]);
                }
                passageT3 = 1;
            }

          
    }
}