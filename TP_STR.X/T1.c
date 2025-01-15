#include "T1.h"

/**
 * Tâche 1: Gestion des entrées/sorties et des acquisitions analogiques
 * Cette tâche utilise un mutex partagé avec la tâche 6 pour éviter les conflits
 * lors de l'envoi UART des valeurs Hardware
 */
void tache1(void) {   
    // Initialisation des variables
    n = 0;
    buffer_vitesse_plus = 1;
    buffer_vitesse_moins = 1;
    buffer_batterie = batterie;
    mutexT1Flag = 0;

    // Configuration initiale du système
    di();                                  
    initialisation_afficheur();             
    clear_text();
    clear_graphics();
    init_rxtx();
    RXTX_libre = 1;
    TXREG1 = 'R';
    ei();

    // Extinction des LEDs
    LED_R = 0; LED_G = 0; LED_B = 0;
    
    while(1) {
        if(!mutexT1Flag) {
            if(mutex_acquire(TACHE1)) {
                // 1. Lecture des valeurs analogiques
                ANALOG_JOYSTICK_X = lecture_8bit_analogique(JOYSTICK_X);
                ANALOG_JOYSTICK_Y = lecture_8bit_analogique(JOYSTICK_Y);
                ANALOG_TEMP_HUILE = lecture_8bit_analogique(TEMPERATURE_HUILE);
                ANALOG_TEMP_EAU = lecture_8bit_analogique(TEMPERATURE_EAU);
                
                // 2. Gestion de la vitesse
                // Bouton vitesse+
                if((VITESSE_PLUS == 0) && (buffer_vitesse_plus == 1)) {
                    buffer_vitesse_plus = 0;
                    if(vitesse < 6) vitesse++;
                } else if((VITESSE_PLUS == 1) && (buffer_vitesse_plus == 0)) {
                    buffer_vitesse_plus = 1;
                }

                // Bouton vitesse-
                if((VITESSE_MOINS==0) && (buffer_vitesse_moins==1))      //Si appuie sur bp viteese moins
                {
                    buffer_vitesse_moins=0;
                    if(vitesse > 0)
                    {
                        vitesse--;
                    }
                }
                else if((VITESSE_MOINS==1) && (buffer_vitesse_moins==0))  
                {
                    buffer_vitesse_moins=1;
                }
                
                // 3. Gestion des alarmes et de la sécurité
                if(alarme_eau || alarme_huile || alarme_batterie || 
                   alarme_frein || alarme_conducteur || alarme_choc) {
                    vitesse = 0;
                }

                // 4. Gestion de la batterie
                if(BATTERIE_PLUS==0 && batterie == 0)     
                {
                    batterie = 100;
                    buffer_batterie = 10000;
                }

                // 5. Lecture du badge
                n=lecture_normale(badge);
                if (n>0)
                {
                    if(n<10)
                    {
                        n_octet_badge=n;
                    }
                    else
                    {
                        n_octet_badge=0;
                    }
                }
                else
                {
                    n_octet_badge=0;
                }

                mutex_release();
                mutexT1Flag = 1;
            }
        }
    }
}