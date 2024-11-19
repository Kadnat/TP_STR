#include "T5.h"

void tache5(void)
{
    unsigned int a;
    unsigned char ma_tache = TACHE5; // Identifiant de la tâche

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

        // Délai
        for (a=0;a<65000;a++)
            ;
        for (a=0;a<65000;a++)
            ;
    }
}