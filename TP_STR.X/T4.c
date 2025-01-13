#include "T4.h"

void tache4(void)
{

    
    while(1)
    {
        
        goto_lico(6,0);

        draw_dec8(batterie);
        
        goto_lico(8,0);
        
        draw_dec8(vitesse);
        
        
        goto_lico(10,0);
        
        draw_dec8(ANALOG_JOYSTICK_Y);
        
        goto_lico(12,0);
        draw_dec8(km[3]);  
        
        goto_lico(13,0);
        draw_dec8(km[2]); 
        
        goto_lico(14,0);
        draw_dec8(km[1]); 
        
        goto_lico(15,0);
        draw_dec8(km[0]);      
    }
    
}
