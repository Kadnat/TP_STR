#include "T6.h"

void tache6(void)
{
   unsigned char ma_tache = TACHE6; // Identifiant de la tâche
   unsigned char analog_c = 0, drive_c = 0, speed_c = 0, 
           water_c = 0, oil_c = 0, battery_c = 0, key_c = 0, frein=0,
           choc = 0, siege = 0; 
   unsigned char wheels = 0, forks = 0;
   
   
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
        if(n_octet_badge == 0) key_c = 0;
        else key_c = 1;
        
        frein = FREIN_A_MAIN;
        choc = CHOC;
        siege = SIEGE;
        
        
        analog_c |= ( ((key_c & 0x1) << 3 ) | ((siege & 0x1) << 2 ) | 
                ((frein & 0x1) << 1 ) | (choc & 0x1) );
        
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

    
        speed_c = vitesse;   
        water_c = TEMPERATURE_EAU;
        oil_c = TEMPERATURE_HUILE;
        battery_c = batterie;
        
        
        if(lecture_8bit_analogique(JOYSTICK_X) < 83) wheels = 2;
        else
        {
            if(lecture_8bit_analogique(JOYSTICK_X) > 173) wheels = 1;
            
            else wheels = 0;
        }
        
        if(lecture_8bit_analogique(JOYSTICK_Y) < 83) forks = 1;
        else
        {
            if(lecture_8bit_analogique(JOYSTICK_Y) > 173) forks = 2;
            
            else forks = 0;
        }
            
        

        while (PIR1bits.TX1IF==0);   TXREG1=0xFE;while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1=analog_c;while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1=drive_c;while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1=wheels;while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1=forks;while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1=speed_c;while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1=water_c;while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1=oil_c;while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1=battery_c;while (TXSTA1bits.TRMT==0);
        while (PIR1bits.TX1IF==0);   TXREG1=0xFF;while (TXSTA1bits.TRMT==0);

        // Libère le sémaphore après utilisation
        semaphore_release();

    }
}
