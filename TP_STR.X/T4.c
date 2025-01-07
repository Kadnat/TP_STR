#include "T4.h"

void tache4(void)
{
    unsigned char passage = 0;
    
    
    while(1)
    {
        
       // if(passage)
        
        goto_lico(6,0);
        //draw_char("B");

        draw_dec8(batterie);
        
        goto_lico(8,0);
        
        draw_dec8(vitesse);
        
        
        goto_lico(10,0);
        
        draw_dec8(ANALOG_JOYSTICK_Y);
        
        // Affichage du kilométrage sur 4 lignes
        goto_lico(12,0);
        draw_dec8((kilometrage >> 24) & 0xFF);  // Octet de poids fort
        
        goto_lico(13,0);
        draw_dec8((kilometrage >> 16) & 0xFF);  // 2ème octet
        
        goto_lico(14,0);
        draw_dec8((kilometrage >> 8) & 0xFF);   // 3ème octet
        
        goto_lico(15,0);
        draw_dec8(kilometrage & 0xFF);      
    }
    
}
