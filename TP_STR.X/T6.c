#include "T6.h"

void tache6(void)
{
    unsigned int a;
    unsigned char ma_tache = TACHE6; // Identifiant de la t�che
    unsigned char analog_c = 0, drive_c = 0, forks_c = 0, speed_c = 0, 
           water_c = 0, oil_c = 0, battery_c = 0, key_c = 0; 


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
        if(n_octet_badge == 0) key_c = 0;
        else key_c = 1;
        
        analog_c = 0x0F & ( ((key_c | 0xFE) << 3 ) | ((SIEGE | 0xFE) << 2 ) | 
                ((FREIN_A_MAIN | 0xFE) << 1 ) | (CHOC | 0xFE) );
        
        if(MARCHE_AVANT == 0)
        {
            drive_c = 1;
        }
        else 
        {
            if(MARCHE_ARRIERE == 0)
            {
                drive_c = 2;
            }
            else
            {
                drive_c = 0;
            }
        }

        //manque variables joystick droite gauche haut bas
    
        speed_c = vitesse;
        
        water_c = TEMPERATURE_EAU;
        oil_c = TEMPERATURE_HUILE;
        battery_c = batterie;
        

        
        while (PIR1bits.TX1IF==0);   TXREG1=analog_c;while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1=drive_c;while (TXSTA1bits.TRMT==0);
        //wheels
        //forks
        while (PIR1bits.TX1IF==0);   TXREG1=speed_c;while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1=water_c;while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1=oil_c;while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1=battery_c;while (TXSTA1bits.TRMT==0);

        // Lib�re le s�maphore apr�s utilisation
        semaphore_release();

    }
}
