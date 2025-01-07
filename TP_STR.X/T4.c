#include "T4.h"

void tache4(void)
{
    //gestion affichage
    while(1)
    {
        gui_update_batterie(batterie);
        gui_update_temperature(ANALOG_TEMP_EAU, ANALOG_TEMP_HUILE);
        gui_update_vitesse(vitesse, vitesse_1);
    }
    
}
