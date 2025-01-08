#include "T2.h"

void tache2(void)
{
    //gestion d'alarme
    alarme_batterie = 0;
    alarme_choc = 0;
    alarme_cle = 0;
    alarme_conducteur = 0;
    alarme_eau = 0;
    alarme_frein = 0;
    alarme_huile = 0;
    

    while(1)
    {
        //Gestion des alarmes

        alarme_frein = (~(FREIN_A_MAIN)) & 0x1;
        
        if(n_octet_badge == 0) alarme_cle = 1;
        else alarme_cle = 0;
        
        if(ANALOG_TEMP_EAU > 120) alarme_eau = 1;
        else alarme_eau = 0;
        
        if(ANALOG_TEMP_HUILE > 120) alarme_huile = 1;
        else alarme_huile = 0;     
        
        if(batterie < 15) alarme_batterie = 1;
        else alarme_batterie = 0;
        
        alarme_conducteur = (~(SIEGE)) & 0x1;
        
        if(((~(CHOC)) & 0x1) == 1)
        {
            alarme_choc = 1;
        }
        

        if(alarme_eau || alarme_huile || alarme_batterie)
        {
            LED_B = 1;
            BUZZER = 1;
            delai_us_char(4000);
            LED_B = 0;
            BUZZER = 0;
            delai_us_char(4000);
            
        }
        
        if(alarme_frein)
        {
            BUZZER = 1;
            delai_us_char(8000);
            BUZZER = 0;
            delai_us_char(8000);
            
        }
        
        if(alarme_cle || alarme_conducteur)
        {
            LED_B = 1;
            LED_G = 1;
            BUZZER = 1;
            delai_us_char(6000);
            LED_B = 0;
            LED_G = 0;
            BUZZER = 0;
            delai_us_char(6000);
            
            if(alarme_cle)
            {
                if(alarme_choc == 1) alarme_choc = 0;
                    
            }

        }
        
        if(alarme_choc)
        {
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
