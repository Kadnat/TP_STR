#include "T3.h"

void tache3(void)
{
    unsigned char cpt1 =0;
    
    while(1)
    {
        //while (PIR1bits.TX1IF==0);   TXREG1='C';while (TXSTA1bits.TRMT==0);

        
        if(BuzzerOn == 1)
        {
            BUZZER = 1;
            delai_us_char(4000);
            BUZZER = 0;
            delai_us_char(4000);
        }
        
        
        

        //while (PIR1bits.TX1IF==0);   TXREG1='I';while (TXSTA1bits.TRMT==0);


    }
}