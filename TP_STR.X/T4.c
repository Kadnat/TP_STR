#include "T4.h"

void tache4(void)
{
    /*unsigned char p4 = 0;
    unsigned char p3 = 0;
    unsigned char p2 = 0;
    unsigned char p1 = 0;*/
    
    //INITIALISATION GUI A ECRIRE UNE SEUL FOIS
    
    //cadres centraux
    goto_lico(8, 1);
    for(unsigned char i = 1 ; i <= 38 ; i++)
    {
        draw_char('*');
    } 
    goto_lico(2, 1);
    for(unsigned char i = 1 ; i <= 38 ; i++)
    {
        draw_char('*');
    }
    goto_lico(2, 13);draw_char(' ');goto_lico(2, 26);draw_char(' ');
    goto_lico(9, 13);draw_char(' ');goto_lico(9, 26);draw_char(' ');

    for(unsigned char i = 8 ; i >= 3 ; i--)
    {
        goto_lico(i, 1); draw_char('*');goto_lico(i, 12); draw_char('*');
        goto_lico(i, 14); draw_char('*');goto_lico(i, 25); draw_char('*');
        goto_lico(i, 27); draw_char('*');goto_lico(i, 38); draw_char('*');
    }
    
    //Cadran central : alarmes
    goto_lico(3, 16); draw_char('A'); draw_char('L'); draw_char('A'); draw_char('R'); draw_char('M'); draw_char('E'); draw_char('S');
    
    //Cadran gauche : état moteur
    goto_lico(3, 4); draw_char('M'); draw_char('O'); draw_char('T'); draw_char('E');  draw_char('U'); draw_char('R');
    goto_lico(5, 2); draw_char('M'); draw_char('A'); draw_char('R'); draw_char('C');  draw_char('H'); draw_char('E');
    goto_lico(7, 2); draw_char('K'); draw_char('M'); draw_char('a'); draw_char('g');  draw_char('e');
    
    //Cadran droite : Pilote
    goto_lico(3, 30);  draw_char('P'); draw_char('I');  draw_char('L'); draw_char('O'); draw_char('T'); draw_char('E');
    goto_lico(5, 28); draw_char('S'); draw_char('I');  draw_char('E'); draw_char('G'); draw_char('E');
    goto_lico(7, 29); draw_char('C'); draw_char('L');  draw_char('E');
    
    //TITRE APPLI
    goto_lico(0,0); draw_char('F'); draw_char('O'); draw_char('R'); draw_char('K'); draw_char('L'); draw_char('I'); draw_char('F'); draw_char('T'); draw_char(' ');
    goto_lico(0,9); draw_char('S'); draw_char('I'); draw_char('M'); draw_char('U'); draw_char('L'); draw_char('A'); draw_char('T'); draw_char('O'); draw_char('R');
    
    
    //dessins cadrans inférieurs : t_eau, vitesse, t_huile
    for(unsigned char i = 2 ; i < 37 ; i++)
        {
            if( (i < 11) || 
                ((i > 14) && (i < 24)) ||
                ((i > 27) && (i < 37))    
              )
            {
                goto_lico(12, i);draw_char('*');
            }
        }
    for(unsigned char i = 15; i >= 13 ; i--)
    {
        goto_lico(i, 1); draw_char('*');goto_lico(i, 11); draw_char('*');
        goto_lico(i, 14); draw_char('*');goto_lico(i, 24); draw_char('*');
        goto_lico(i, 27); draw_char('*');goto_lico(i, 37); draw_char('*');
    }
    
    //titres:
    goto_lico(11, 2); draw_char('T');goto_lico(11, 3); draw_char('e');goto_lico(11, 4); draw_char('m');goto_lico(11, 5); draw_char('p');
    goto_lico(11, 7); draw_char('E');goto_lico(11, 8); draw_char('a');goto_lico(11, 9); draw_char('u');
    
    goto_lico(11, 28); draw_char('T');goto_lico(11, 29); draw_char('e');goto_lico(11, 30); draw_char('m');goto_lico(11, 31); draw_char('p');
    goto_lico(11, 33); draw_char('H');goto_lico(11, 34); draw_char('u');goto_lico(11, 35); draw_char('i');goto_lico(11, 36); draw_char('l');goto_lico(11, 37); draw_char('e');
    
    goto_lico(11, 16); draw_char('V');goto_lico(11, 17); draw_char('i');goto_lico(11, 18); draw_char('t');
    goto_lico(11, 19); draw_char('e');goto_lico(11, 20); draw_char('s');goto_lico(11, 21); draw_char('s');goto_lico(11, 22); draw_char('e'); 
    
    //unités
    goto_lico(14, 19);draw_char('k');goto_lico(14, 20);draw_char('m');goto_lico(14, 21);draw_char('/');goto_lico(14, 22);draw_char('h');
    goto_lico(14, 8);draw_char('C');goto_lico(14, 34);draw_char('C');
    //batterie
    goto_lico(0, 36); draw_char('%');
    
    while(1)
    {
        //updates simples (valeur immédiate)
        goto_lico(14, 16); draw_dec8(vitesse);              //update vitesse
        goto_lico(14, 4);  draw_dec8(ANALOG_TEMP_EAU);      //update temp eau
        goto_lico(14, 30); draw_dec8(ANALOG_TEMP_HUILE);    //update temp huile
        goto_lico(0, 33);  draw_dec8(batterie);             //update batterie
        goto_lico(7, 8);   draw_dec8(km[3]); goto_lico(7, 9);draw_dec8(km[2]);
        
        //updates conditionnelles
        if(alarme_batterie)
        {
            goto_lico(5, 15);draw_char('B');goto_lico(5, 16);draw_char('A');goto_lico(5, 17);draw_char('T');goto_lico(5, 19);draw_char('F');goto_lico(5, 20);draw_char('A');
            goto_lico(5, 21);draw_char('I');goto_lico(5, 22);draw_char('B');goto_lico(5, 23);draw_char('L');goto_lico(5, 24);draw_char('E');
        }
        else
        {
            for(unsigned char i = 15; i <= 24 ; i++ )
            {
                goto_lico(5, i); draw_char(' ');
            }
        }
        
        if(alarme_eau)
        {
            goto_lico(6, 15);draw_char('T');goto_lico(6, 17);draw_char('E');goto_lico(6, 18);draw_char('A');goto_lico(6, 19);draw_char('U');
            goto_lico(6, 21);draw_char('E');goto_lico(6, 22);draw_char('R');goto_lico(6, 23);draw_char('R');
        }
        else
        {
            goto_lico(6, 15);draw_char('T');goto_lico(6, 17);draw_char('E');goto_lico(6, 18);draw_char('A');goto_lico(6, 19);draw_char('U');
            goto_lico(6, 21);draw_char('O');goto_lico(6, 22);draw_char('K');
        
        }
        
        if(alarme_huile)
        {
            goto_lico(7, 15);draw_char('T');goto_lico(7, 17);draw_char('O');goto_lico(7, 18);draw_char('I');goto_lico(7, 19);draw_char('L');
            goto_lico(7, 21);draw_char('E');goto_lico(7, 22);draw_char('R');goto_lico(7, 23);draw_char('R');
        }
        else
        {
            goto_lico(7, 15);draw_char('T');goto_lico(7, 17);draw_char('O');goto_lico(7, 18);draw_char('I');goto_lico(7, 19);draw_char('L');
            goto_lico(7, 21);draw_char('O');draw_char('K'); draw_char(' ');
        
        }
        
        if(alarme_choc)
        {
            goto_lico(8, 15);draw_char('C');goto_lico(8, 16);draw_char('H');goto_lico(8, 17);draw_char('O');goto_lico(8, 18);draw_char('C');goto_lico(8, 19);draw_char('>');
            goto_lico(8, 20);draw_char('A');goto_lico(8, 21);draw_char('R');goto_lico(8, 22);draw_char('R');goto_lico(8, 23);draw_char('E');goto_lico(8, 24);draw_char('T');
        }
        else
        {
           for(unsigned char i = 15; i <= 24 ; i++ )
            {
                goto_lico(8, i); draw_char(' ');
            } 
        }
        
        if(alarme_frein){goto_lico(5, 9);draw_char('(');goto_lico(5, 10);draw_char('P');goto_lico(5, 10);draw_char(')');}
        else if(MARCHE_AVANT){goto_lico(5, 9);draw_char('A');goto_lico(5, 10);draw_char('v');goto_lico(5, 10);draw_char(' ');}
        else if(MARCHE_ARRIERE){goto_lico(5, 9);draw_char('A');goto_lico(5, 10);draw_char('r');goto_lico(5, 10);draw_char(' ');}
        else{goto_lico(5, 9);draw_char(' ');goto_lico(5, 10);draw_char('N');goto_lico(5, 10);draw_char(' ');}
    
        /*update calcul
        p4 = kilometrage / 10000;                                           goto_lico(7, 8); draw_char(p4+48);
        p3 = (kilometrage - (10000*p4)) / 1000;                             goto_lico(7, 9); draw_char(p3+48);
        p2 = (kilometrage - (10000 * p4) - (1000 * p3)) / 100;              goto_lico(7, 10); draw_char(p2+48);
        p1 = (kilometrage - (10000 * p4) - (1000 * p3) - (100 * p2)) / 100; goto_lico(7, 11); draw_char(p1+48);
    */  }
   
}
