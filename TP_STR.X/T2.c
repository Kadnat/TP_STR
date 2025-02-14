#include "T2.h"

/**
 * Tâche 2: Gestion des alarmes et des alertes
 * Cette tâche surveille différents paramètres et déclenche les alarmes appropriées
 */
void tache2(void) {
    // Initialisation des alarmes
    alarme_batterie = 0;
    alarme_choc = 0;
    alarme_cle = 0;
    alarme_conducteur = 0;
    alarme_eau = 0;
    alarme_frein = 0;
    alarme_huile = 0;

    while(1) {
        // 1. Vérification des conditions d'alarme
        alarme_frein = (~(FREIN_A_MAIN)) & 0x1;
        alarme_cle = (n_octet_badge == 0) ? 1 : 0;
        alarme_eau = (ANALOG_TEMP_EAU > 120) ? 1 : 0;
        alarme_huile = (ANALOG_TEMP_HUILE > 120) ? 1 : 0;
        alarme_batterie = (batterie < 15) ? 1 : 0;
        alarme_conducteur = (~(SIEGE)) & 0x1;
        
        if(((~(CHOC)) & 0x1) == 1) {
            alarme_choc = 1;
        }

        // 2. Gestion des signaux d'alarme
        // Alarmes techniques (eau, huile, batterie)
        if(alarme_eau || alarme_huile || alarme_batterie) {
            LED_B = 1;
            BUZZER = 1;
            delai_us_char(4000);
            LED_B = 0;
            BUZZER = 0;
            delai_us_char(4000);
        }

        // Alarme frein
        if(alarme_frein) {
            BUZZER = 1;
            delai_us_char(8000);
            BUZZER = 0;
            delai_us_char(8000);
        }

        // Alarmes de sécurité (clé, conducteur)
        if(alarme_cle || alarme_conducteur) {
            LED_B = 1;
            LED_G = 1;
            BUZZER = 1;
            delai_us_char(6000);
            LED_B = 0;
            LED_G = 0;
            BUZZER = 0;
            delai_us_char(6000);
            
            if(alarme_cle) {
                if(alarme_choc == 1) alarme_choc = 0;
            }
        }

        // Alarme choc
        if(alarme_choc) {
            LED_B = 1;
            LED_G = 1;
            BUZZER = 1;
            delai_us_char(2000);
            LED_B = 0;
            LED_G = 0;
            BUZZER = 0;
            delai_us_char(2000);
        }
    }
}
