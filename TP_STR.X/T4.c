#include "T4.h"

void tache4(void)
{
    unsigned char i;

    goto_lico(13,34);draw_char('R');draw_char(' ');draw_char('V');draw_char(' ');draw_char('B');
    goto_lico(14,34);draw_char('0');draw_char(' ');draw_char('0');draw_char(' ');draw_char('0');
    goto_lico(15,34);draw_char('1');draw_char(' ');draw_char('1');draw_char(' ');draw_char('1');
    while(1)
    {
        goto_lico(0,0);
        draw_string("Marche:");
        if (MARCHE_AVANT==0)
            draw_string("AV");
        else
            if (MARCHE_ARRIERE==0)
                draw_string("AR");
            else
                draw_string("N ");
        goto_lico(1,0);
        draw_string("Siege:");
        if (SIEGE==0)
        {draw_char('1');}
        else
        {draw_char('0');}
        goto_lico(2,0);
        draw_string("Temp. Eau:");
        draw_hex8(lecture_8bit_analogique(TEMPERATURE_EAU));
        goto_lico(3,0);
        draw_string("Temp. Huile:");
        draw_hex8(lecture_8bit_analogique(TEMPERATURE_HUILE));
        goto_lico(4,0);
        draw_string("Choc:");
        if (CHOC==0)
            draw_char('1');
        else
            draw_char('0');
        goto_lico(5,0);
        draw_string("Vitesse:");
        if (VITESSE_PLUS==0)
            vitesse++;
        if (VITESSE_MOINS==0)
            vitesse--;
        draw_hex8(vitesse);
        goto_lico(6,0);
        draw_string("Batterie:");
        if (BATTERIE_PLUS==0)
            batterie++;
        if (BATTERIE_MOINS==0)
            batterie--;
        draw_hex8(batterie);
        goto_lico(7,0);
        if (FREIN_A_MAIN==0)
            draw_string("((!))");
        else
            draw_string("     ");


        goto_lico(9,0);
        draw_string("X-Joystick:");
        draw_hex8(lecture_8bit_analogique(JOYSTICK_X));
        goto_lico(10,0);
        draw_string("Y-Joystick:");
        draw_hex8(lecture_8bit_analogique(JOYSTICK_Y));

    }
}