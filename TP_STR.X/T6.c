#include "T6.h"

/**
 * Tâche 6: Communication UART et gestion des données
 * Cette tâche utilise un mutex partagé avec la tâche 1 pour la synchronisation
 * des données avant leur transmission via UART
 */
void tache6(void) {
    // Variables pour la transmission UART
    unsigned char analog_c = 0, drive_c = 0, speed_c = 0;
    unsigned char water_c = 0, oil_c = 0, battery_c = 0, key_c = 0;
    unsigned char frein = 0, choc = 0, siege = 0;
    unsigned char wheels = 0, forks = 0;
    mutexT6Flag = 0;
   
    while(1) {
        if(!mutexT6Flag) {
            if(mutex_acquire(TACHE6)) {
                // 1. Lecture des états des capteurs
                key_c = (n_octet_badge == 0) ? 0 : 1;
                frein = FREIN_A_MAIN;
                choc = CHOC;
                siege = SIEGE;
                
                // 2. Construction du mot d'état analogique
                analog_c = (((key_c & 0x1) << 3) | ((siege & 0x1) << 2) | 
                          ((frein & 0x1) << 1) | (choc & 0x1));
                
                // 3. Détermination de la direction
                drive_c = 0;
                if(MARCHE_AVANT == 0) drive_c = 1;
                else if(MARCHE_ARRIERE == 0) drive_c = 2;

                // 4. Lecture des autres paramètres
                speed_c = vitesse;   
                water_c = ANALOG_TEMP_EAU;
                oil_c = ANALOG_TEMP_HUILE;
                battery_c = batterie;

                if(water_c >= 0xfd) water_c = 0xfd;
                if(oil_c >= 0xfd) oil_c = 0xfd;

                // 5. Traitement du joystick
                // Position des roues
                if(ANALOG_JOYSTICK_X < 83) wheels = 2;
                else if(ANALOG_JOYSTICK_X > 173) wheels = 1;
                else wheels = 0;
                
                // Position des fourches
                if(ANALOG_JOYSTICK_Y < 83) forks = 1;
                else if(ANALOG_JOYSTICK_Y > 173) forks = 2;
                else forks = 0;

                // 6. Transmission UART des données
                while (PIR1bits.TX1IF==0); TXREG1=0xFE; while (TXSTA1bits.TRMT==0);
                while (PIR1bits.TX1IF==0); TXREG1=analog_c; while (TXSTA1bits.TRMT==0);
                while (PIR1bits.TX1IF==0); TXREG1=drive_c; while (TXSTA1bits.TRMT==0);
                while (PIR1bits.TX1IF==0); TXREG1=wheels; while (TXSTA1bits.TRMT==0);
                while (PIR1bits.TX1IF==0); TXREG1=forks; while (TXSTA1bits.TRMT==0);
                while (PIR1bits.TX1IF==0); TXREG1=speed_c; while (TXSTA1bits.TRMT==0);
                while (PIR1bits.TX1IF==0); TXREG1=water_c; while (TXSTA1bits.TRMT==0);
                while (PIR1bits.TX1IF==0); TXREG1=oil_c; while (TXSTA1bits.TRMT==0);
                while (PIR1bits.TX1IF==0); TXREG1=battery_c; while (TXSTA1bits.TRMT==0);
                while (PIR1bits.TX1IF==0); TXREG1=0xFF; while (TXSTA1bits.TRMT==0);

                mutex_release();
                mutexT6Flag = 1;
            }
        }
    }
}
