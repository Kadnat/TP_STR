#include "T1.h"

//Les taches 1 et 6 utilisent un sémaphore afin d'éviter que la t1 update les variables HW
//alors que l'envoie UART n'est pas finie (puisque l'uart envoie les valeurs de ces dernières)
void tache1(void)
{   
    //acquisition et enregistrement dans des variables globales des entr?es analog et du tactile.

       //sert a modifier la valeur de vitesse sur appuie unique et non continu
      //sert a modifier la valeur de vitesse sur appuie unique et non continu
     //sert a modifier la valeur de batterie sur appuie unique et non continu
     //sert a modifier la valeur de batterie sur appuie unique et non continu
    n =0;
    buffer_vitesse_plus =1;
    buffer_vitesse_moins =1;
    buffer_batterie = batterie;

    di();                                   //disable interrupt
    initialisation_afficheur();             
    clear_text();
    clear_graphics();
    init_rxtx();
    RXTX_libre=1;
    TXREG1='R';
    ei();

    LED_R=0;LED_G=0;LED_B=0;
    semtask1FLAG = 0;
    
    while(1)
    {
        while(semtask1FLAG);
        
        //while (PIR1bits.TX1IF==0);   TXREG1='A';while (TXSTA1bits.TRMT==0);
        
        // Essaie d'acqu?rir le s?maphore
        while (semaphore_tryacquire(TACHE1) == 0)
        {
        
            // Si le semaphore n'est pas disponible, 
            // on attend passivement
            // (l'ordonnanceur passera a une autre tache)
        }
    
        //Une fois le semaphore acquis on peut passer a la routine d'acquisisiton
        //gui_update_batterie(100);
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
        else if((VITESSE_MOINS==1) && (buffer_vitesse_moins==0))  //Si bp relach? alors raz buffer sur bouton
        {
            buffer_vitesse_moins=1;
        }
        
        if(alarme_eau || alarme_huile || alarme_batterie || alarme_frein || alarme_conducteur || alarme_choc)
        {
            vitesse = 0;
        }
        //////////////////////////////////
        //Acquisition et actualisation sur boutons poussoirs batterie
            //BOUTON BATTERIE+
        if(BATTERIE_PLUS==0 && batterie == 0)      //Si appuie sur bp viteese plus
        {
            batterie = 100;
            buffer_batterie = 10000;
        }

        //LECTURE CLE?  => Voir ce que ?a implique en HW et en traitement SW pour voir si c'est plus pertinent de le mettre ici
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
        //TACTILE GERE DANS TACHE 3 AVEC AFFICHAGE
        //while (PIR1bits.TX1IF==0);   TXREG1='G';while (TXSTA1bits.TRMT==0);


        semaphore_release(TACHE1);
        semtask1FLAG = 1;
        
        T0IF = 1;

    }
}