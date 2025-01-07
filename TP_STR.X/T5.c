#include "T5.h"

void tache5(void)       //Gestion batterie & vitesse
{
    unsigned int buffer_tick = 0;           //Compteur de tick utilis? pour indiquer quand on passe 100 ticks environ
    unsigned int length_tick = 100;         //Grandeur de comparaison, tous les 100 ticks environ on actualise la batterie
                                            //Cela represente 100 interruptions ? 10ms soit 1 sec    
    unsigned char sample_vitesse[20];       //tab qui contient les samples de vitesse pour en faire la moyenne
    unsigned char sample_count = 0;         //compteur de sample
    unsigned char average_speed;            //vitesse moyenne actualis?e toutes les secondes
    
    batterie = 100;                                 //Initialiastion du niveau de batterie ? 100%
    vitesse = 0;                                    //Initialisation de vitesse a 0
    vitesse_1 = 0;                                  //Initialisation de vitesse n-1 a 0
    unsigned int buffer_batterie = batterie * 100;  //image de la batterie en temps r?el sur 10 000 afin d'?viter d'utiliser des floats
    while(1)
    {   
        //while (PIR1bits.TX1IF==0);   TXREG1='E';while (TXSTA1bits.TRMT==0);

        if(batterie!=0) //Si la batterie n'est pas vide
        {
            if((Tick_Count - buffer_tick) > 100)    //Si plus d'une seconde ecoulee
            {
                //Calcul et actualisation de la vitesse moyenne sur les derniers samples
                for(char i = 0; i<sample_count; i++)
                {
                    average_speed += sample_vitesse[i];
                }
                average_speed = average_speed / sample_count;
                vitesse_1 = vitesse;
                vitesse = average_speed;
                //Actualisation du niveau de batterie selon l'equation b%=b-0,15x-0,1 o? x = average_speed
                buffer_batterie = buffer_batterie - 15 * average_speed - 10;
                batterie = buffer_batterie / 100;
                                
                buffer_tick = Tick_Count;   //Actualisation buffer_tick
                sample_count = 0;           //Raz du nombre de sample                
                
            }
            else                                    //Sinon echantillonnage de la vitesse
            {
                sample_vitesse[sample_count] = vitesse;
                sample_count++;
            }
        }
        //Si la batterie est vide on execute pas la task 5
        //while (PIR1bits.TX1IF==0);   TXREG1='K';while (TXSTA1bits.TRMT==0);


    }
}