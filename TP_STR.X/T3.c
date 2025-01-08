#include "T3.h"

/**
 * Tâche 3: Gestion du kilométrage
 * Cette tâche s'occupe du comptage kilométrique et de sa sauvegarde en EEPROM
 */
void tache3(void) {
    // Initialisation des variables
    counter_T3 = 0;
    passageT3 = 0;
    unsigned long kilometrage = 0;
    
    // Initialisation de l'EEPROM si nécessaire
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

            // Calcul du kilométrage basé sur la vitesse
            kilometrage += vitesse;
            
            // Mise à jour des octets du kilométrage
            km[0] = kilometrage & 0xFF;
            km[1] = (kilometrage >> 8) & 0xFF;
            km[2] = (kilometrage >> 16) & 0xFF;
            km[3] = (kilometrage >> 24) & 0xFF;

            // Sauvegarde périodique dans l'EEPROM
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