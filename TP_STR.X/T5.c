#include "T5.h"

void tache5(void)
{
    unsigned int a;
    unsigned char ma_tache = TACHE5; // Identifiant de la t�che

    while(1)
    {
        // Essaie d'acqu�rir le s�maphore
        while (semaphore_tryacquire(ma_tache) == 0)
        {
            // Si le s�maphore n'est pas disponible, 
            // on attend passivement
            // (l'ordonnanceur passera � une autre t�che)
        }

        // Une fois le s�maphore acquis, on peut �crire
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

        // Lib�re le s�maphore apr�s utilisation
        semaphore_release();

        // D�lai
        for (a=0;a<65000;a++)
            ;
        for (a=0;a<65000;a++)
            ;
    }
}