#include "T1.h"

void tache1(void)
{   

    
    //acquisition et enregistrement dans des variables globales des entr?es analog et du tactile.
    
    unsigned char ma_tache = TACHE1;  
    unsigned char n; //nombre d'octet de la cl� d'identification
    unsigned char buffer_vitesse_plus = 1;   //sert ? modifier la valeur de vitesse sur appuie unique et non continu
    unsigned char buffer_vitesse_moins = 1;  //sert ? modifier la valeur de vitesse sur appuie unique et non continu
    unsigned char buffer_batterie_plus = 1;  //sert ? modifier la valeur de batterie sur appuie unique et non continu
    unsigned char buffer_batterie_moins = 1; //sert ? modifier la valeur de batterie sur appuie unique et non continu
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
        while (semaphore_tryacquire(ma_tache) == 0)
        {
        
            // Si le s?maphore n'est pas disponible, 
            // on attend passivement
            // (l'ordonnanceur passera ? une autre t?che)
        }
    
        //Une fois le s?maphore acquis on peut passer ? la routine d'acquisisiton
    
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
        //////////////////////////////////
        //Acquisition et actualisation sur boutons poussoirs batterie
            //BOUTON BATTERIE+
        if((BATTERIE_PLUS==0) && (buffer_batterie_plus==1))      //Si appuie sur bp viteese plus
        {
            buffer_batterie_plus=0;
            if(batterie < 100)
            {
                batterie++;
            }
        }
        else if((BATTERIE_PLUS==1) && (buffer_batterie_plus==0))  //Si bp relach? alors raz buffer sur bouton
        {
            buffer_batterie_plus=1;
        }
            //BOUTON BATTERIE-
        if((BATTERIE_MOINS==0) && (buffer_batterie_moins==1))      //Si appuie sur bp viteese moins
        {
            buffer_batterie_moins=0;
            if(batterie > 0)
            {
                batterie--;
            }
        }
        else if((BATTERIE_MOINS==1) && (buffer_batterie_moins==0))  //Si bp relach? alors raz buffer sur bouton
        {
            buffer_batterie_moins=1;
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


        semaphore_release(ma_tache);
        semtask1FLAG = 1;
        
        T0IF = 1;

    }
}