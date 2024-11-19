#include "T5.h"

void tache5(void)
{
    unsigned int a;
    while(1)
    {
        //P(SEM_RXTX);
        //while(RXTX_libre==0);
        //RXTX_libre=0;
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
        //RXTX_libre=1;
        //V(SEM_RXTX);
        for (a=0;a<65000;a++)
            ;
        for (a=0;a<65000;a++)
            ;
    }
}

void GestionBatterieVitesse(void){
    ////We assume this function is called via time controled fashion and is only called once a second 
    if (vitesse>3){batterie=batterie-3;}
    else if (vitesse=1){batterie=batterie-2;}
    else if (vitesse>=1){batterie=batterie-1;}
    
    
}
void GestionBatterieFourche(void){
    // We assume that this func is called because the forks are sollicité
    //We also assume this function is called in a time concious fashion and is only called once a second 
    //Alors on diminue la batterie d'un taux fix de 1
    batterie=batterie-1;
}