#include "T6.h"

void tache6(void)
{
   unsigned int a;
   unsigned char ma_tache = TACHE6; // Identifiant de la tâche
   unsigned char analog_c = 0, drive_c = 0, forks_c = 0, speed_c = 0, 
           water_c = 0, oil_c = 0, battery_c = 0, key_c = 0; 

    while(1)
    {
        // Essaie d'acquérir le sémaphore
        while (semaphore_tryacquire(ma_tache) == 0)
        {
            // Si le sémaphore n'est pas disponible, 
            // on attend passivement
            // (l'ordonnanceur passera à une autre tâche)
        }
        

        // Une fois le sémaphore acquis, on peut écrire
        if(n_octet_badge == 0) key_c = 0;
        else key_c = 1;
        
        analog_c = 0x0F & ( ((key_c | 0xFE) << 3 ) | ((SIEGE | 0xFE) << 2 ) | 
                ((FREIN_A_MAIN | 0xFE) << 1 ) | (CHOC | 0xFE) )
        
        
        
        while (PIR1bits.TX1IF==0);   TXREG1='t';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='a';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='c';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='h';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='e';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='5';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='_';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='e';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='n';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='_';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='c';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='o';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='u';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='r';while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1='s';while (TXSTA1bits.TRMT==0);

        // Libère le sémaphore après utilisation
        semaphore_release();

    }
}
