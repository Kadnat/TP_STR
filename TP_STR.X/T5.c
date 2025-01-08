#include "T5.h"

void tache5(void)       //Gestion batterie & vitesse
{
    unsigned int buffer_tick = 0;           //Compteur de tick utilis? pour indiquer quand on passe 100 ticks environ
    unsigned int length_tick = 100;         //Grandeur de comparaison, tous les 100 ticks environ on actualise la batterie
                                            //Cela represente 100 interruptions ? 10ms soit 1 sec    
    unsigned char sample_vitesse[20];       //tab qui contient les samples de vitesse pour en faire la moyenne
    unsigned char sample_count = 10;         //compteur de sample
    unsigned char average_speed;            //vitesse moyenne actualis?e toutes les secondes
    //unsigned char cptT5 = 0;
    //unsigned char passageT5 = 0;
    
    batterie = 100;                                 //Initialiastion du niveau de batterie ? 100%
    vitesse = 0;                                    //Initialisation de vitesse a 0                              //Initialisation de vitesse n-1 a 0
      //image de la batterie en temps r?el sur 10 000 afin d'?viter d'utiliser des floats
    buffer_batterie = batterie * 100;
    passageT5 = 0;
    
    while(1)
    {   
        
        //while (PIR1bits.TX1IF==0);   TXREG1='E';while (TXSTA1bits.TRMT==0);

        if(batterie!=0) //Si la batterie n'est pas vide
        {
                
            if(passageT5 == 0)
            {
               if(cptT5 == sample_count)    //Si plus d'une seconde ecoulee
                {
                    //Calcul et actualisation de la vitesse moyenne sur les derniers samples
                    for(char i = 0; i<sample_count; i++)
                    {
                        average_speed += sample_vitesse[i];
                    }
                    average_speed = average_speed / sample_count;
                    //Actualisation du niveau de batterie selon l'equation b%=b-0,15x-0,1 o? x = average_speed
                    buffer_batterie = buffer_batterie - 15 * average_speed - 10;
                    
                    batterie = buffer_batterie / 100;
                    cptT5 = 0;           //Raz du nombre de sample  

                }
                else                                    //Sinon echantillonnage de la vitesse
                {
                    sample_vitesse[cptT5] = vitesse;
                    cptT5++;
                    
                }
               passageT5 = 1;
            }
            
        }
        
        else
        {
            for(char i = 0; i<sample_count; i++)
            {
                sample_vitesse[i]=0;
            }
            average_speed = 0;   
        }
        //Si la batterie est vide on execute pas la task 5
        //while (PIR1bits.TX1IF==0);   TXREG1='K';while (TXSTA1bits.TRMT==0);

    }
}