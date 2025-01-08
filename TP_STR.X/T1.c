#include "T1.h"

//Les taches 1 et 6 utilisent un s�maphore afin d'�viter que la t1 update les variables HW
//alors que l'envoie UART n'est pas finie (puisque l'uart envoie les valeurs de ces derni�res)
void tache1(void)
{   

    n =0;
    buffer_vitesse_plus =1;
    buffer_vitesse_moins =1;
    buffer_batterie = batterie;

    di();                                  
    initialisation_afficheur();             
    clear_text();
    clear_graphics();
    init_rxtx();
    RXTX_libre=1;
    TXREG1='R';
    ei();

    LED_R=0;LED_G=0;LED_B=0;
    mutexT1Flag = 0;
    
    while(1)
    {
        if(!mutexT1Flag)
        {
            if(mutex_acquire(TACHE1))
            {
                //Acquisition et actualisation des valeurs analogiques jusqu'au tour suivant
                ANALOG_JOYSTICK_X = lecture_8bit_analogique(JOYSTICK_X);
                ANALOG_JOYSTICK_Y = lecture_8bit_analogique(JOYSTICK_Y);
                ANALOG_TEMP_HUILE = lecture_8bit_analogique(TEMPERATURE_HUILE);
                ANALOG_TEMP_EAU   = lecture_8bit_analogique(TEMPERATURE_EAU);
                
                
                

            
                //Acquisition et actualisation sur boutons poussoirs vitesse
                    //BOUTON VITESSE+
                if((VITESSE_PLUS==0) && (buffer_vitesse_plus==1))      //Si appuie sur bp viteese plus
                {
                    buffer_vitesse_plus=0;
                    if(vitesse < 6)
                    {
                        vitesse++;
                    }
                    else if(vitesse >= 6)
                    {
                        vitesse = 6;
                    }
                }
                else if((VITESSE_PLUS==1) && (buffer_vitesse_plus==0))  //Si bp relach? alors raz buffer sur bouton
                {
                    buffer_vitesse_plus=1;
                }
                    //BOUTON VITESSE-
                if((VITESSE_MOINS==0) && (buffer_vitesse_moins==1))      //Si appuie sur bp viteese moins
                {
                    buffer_vitesse_moins=0;
                    if(vitesse > 0)
                    {
                        vitesse--;
                    }
                }
                else if((VITESSE_MOINS==1) && (buffer_vitesse_moins==0))  
                {
                    buffer_vitesse_moins=1;
                }
                
                if(alarme_eau || alarme_huile || alarme_batterie || alarme_frein || alarme_conducteur || alarme_choc)
                {
                    vitesse = 0;
                }


                if(BATTERIE_PLUS==0 && batterie == 0)     
                {
                    batterie = 100;
                    buffer_batterie = 10000;
                }

                
                n=lecture_normale(badge);
                if (n>0)
                {
                    if(n<10)
                    {
                        n_octet_badge=n;
                    }
                    else
                    {
                        n_octet_badge=0;
                    }
                }
                else
                {
                    n_octet_badge=0;
                }


                mutex_release(TACHE1);
                mutexT1Flag = 1;

            }
        }



    }
}