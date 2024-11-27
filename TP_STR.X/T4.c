#include "T4.h"

void tache4(void)
{
    while(1)
    {
        if(SIEGE == 1 && n_octet_badge != 0)
    {
        ENGINE = 1;
    }
    else
    {
        ENGINE = 0;
    }
 
    //Handbrake
    if(FREIN_A_MAIN == 0)
    {
        HANDBRAKE = 0;
    }
    else
    {
        HANDBRAKE = 1;
    }

    //Drive
    if(ENGINE == 1 && HANDBRAKE == 0 && MARCHE_AVANT == 0)
    {
        DRIVE = 1; //Marche avant
    }
    else if(ENGINE == 1 && HANDBRAKE == 0 && MARCHE_ARRIERE == 0)
    {
        DRIVE = 2; //Marche arrière
    }
    else
    {
        DRIVE = 0; //Neutre
    }

    if(ENGINE == 1)
    {
        //Wheels
        if(lecture_8bit_analogique(JOYSTICK_X) <= 83)
        {
            WHEELDIRECTION = 2; //Left
        }
        else if(lecture_8bit_analogique(JOYSTICK_X) >= 173)
        {
            WHEELDIRECTION = 1; //RIGHT
        }
        else
        {
            WHEELDIRECTION = 0; //STRAIGHT
        }  

        //Forklift
        if(lecture_8bit_analogique(JOYSTICK_Y) <= 83)
        {
            FORKLIFT = 1; //DOWN
        }
        else if(lecture_8bit_analogique(JOYSTICK_Y) >= 173)
        {
            FORKLIFT = 2; //UP
        }
        else
        {
            FORKLIFT = 0; //STRAIGHT
        }

        //Alarm
        if(CHOC == 0)
        {
            ENGINE = 0;
        }

        //Water alarm
        if(lecture_8bit_analogique(TEMPERATURE_EAU) > 100)
        {
            ENGINE = 0;
        }
        else if(lecture_8bit_analogique(TEMPERATURE_EAU) < 5)
        {
            ENGINE = 0;
        }
    
        //Oil alarm
        if(lecture_8bit_analogique(TEMPERATURE_HUILE) > 110)
        {
            ENGINE = 0;
        }
        else if(lecture_8bit_analogique(TEMPERATURE_HUILE) < 5)
        {
            ENGINE = 0;
        }

        //Battery alarm
        if(batterie <= 0)
        {
            ENGINE = 0;
        }
    }
 
        if(MARCHE_ARRIERE == 0)
        {
            BUZZER = 1;  // Activer le buzzer
        }  
        else
        {
            BUZZER = 0;  // S'assurer que le buzzer est éteint
        }
    }
}
