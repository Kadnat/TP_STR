#include "T3.h"

void tache3(void)
{
    unsigned char cpt1 =0;
    
    while(1)
    {
        //while (PIR1bits.TX1IF==0);   TXREG1='C';while (TXSTA1bits.TRMT==0);

        
        if(alarme_huile == 1)
        {
            BUZZER = 1;
            delai_us_char(4000);
            BUZZER = 0;
            delai_us_char(4000);
        }
        else if(alarme_eau == 1)
        {
            BUZZER = 1;
            delai_us_char(1000);
            BUZZER = 0;
            delai_us_char(1000);
        }
        else if(alarme_choc == 1)
        {
            BUZZER = 1;
            delai_us_char(500);
            BUZZER = 0;
            delai_us_char(500);
        }
//        else if(batterie < 15)
//        {
//            BUZZER = 1;
//            delai_us_char(200);
//            BUZZER = 0;
//            delai_us_char(200);
//        }
//        else
//        {
//            BUZZER = 0;
//        }
        //while (PIR1bits.TX1IF==0);   TXREG1='I';while (TXSTA1bits.TRMT==0);


    }
}