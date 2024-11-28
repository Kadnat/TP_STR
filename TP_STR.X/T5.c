#include "T5.h"

void tache5(void)       //Gestion batterie
{
    unsigned ma_tache = TACHE5;             //Identifiant de la tâche
    unsigned int buffer_tick = 0;           //Compteur de tick utilisé pour indiquer quand on passe 100 ticks environ
    unsigned int length_tick = 100;         //Grandeur de comparaison, tous les 100 ticks environ on actualise la batterie
                                            //Cela représente 100 interruptions à 10ms soit 1 sec    
    unsigned char sample_vitesse[20];       //tab qui contient les samples de vitesse pour en faire la moyenne
    unsigned char sample_count = 0;         //compteur de sample
    unsigned char average_speed;            //vitesse moyenne actualisée toutes les secondes
    
    batterie = 100;                                  //Initialiastion du niveau de batterie à 100%
    unsigned int buffer_batterie = batterie * 100;   //image de la batterie en temps réel sur 10 000 afin d'éviter d'utiliser des floats
    while(1)
    {
        // Essaie d'acquérir le sémaphore
        while (semaphore_tryacquire(ma_tache) == 0)
        {
            // Si le sémaphore n'est pas disponible, 
            // on attend passivement
            // (l'ordonnanceur passera à une autre tâche)
        }
        
        // Une fois le sémaphore acquis, on peut passer à la routine batterie
        if(batterie!=0) //Si la batterie n'est pas vide
        {
            if((Tick_Count - buffer_tick) > 100)    //Si plus d'une seconde écoulée
            {
                //Calcul de la vitesse moyenne sur les derniers samples
                for(char i = 0; i<sample_count; i++)
                {
                    average_speed += sample_vitesse[i];
                }
                average_speed = average_speed / sample_count;
                
                //Actualisation du niveau de batterie selon l'équation b%=b-0,15x-0,1 où x = average_speed
                buffer_batterie = buffer_batterie - 15 * average_speed - 10;
                batterie = buffer_batterie / 100;
                                
                buffer_tick = Tick_Count;   //Actualisation buffer_tick
                sample_count = 0;           //Raz du nombre de sample                
                
            }
            else                                    //Sinon échantillonnage de la vitesse
            {
                sample_vitesse[sample_count] = vitesse;
                sample_count++;
            }
        }
        //Si la batterie est vide on éxecute pas la task 5
        semaphore_release();
    }
}