/*
 * File:   gui.c
 * Author: andre
 *
 * Created on 28 novembre 2024, 16:19
 */


#include "gui.h"

void gui_init()     //dessine les éléments osd qui ne seront pas redessiné après
{
    unsigned char x = 0;
    unsigned char y = 0;
    unsigned char i = 0;
    unsigned char j = 0;
    unsigned char k = 0;
    unsigned char l = 0;
    
    //Contour
    for(x = 0; x < 240; x++)
    {
        for(y = 0; y < 3; y++)
        {
            plot1(x, y);
            if((x < 80) || (x > 160))
            {
                plot1(x, 128 - y);
            }
            if(x < 128)
            {
                plot1(y, x); plot1(239 - y, x);
            }
            
        } 
    }
    
    
    //Batterie
    x = X_BATT_INITIAL;
    y = Y_BATT_INITIAL;
    plot1(x, y - 3); plot1(x, y - 2); plot1(x, y - 1); plot1(x, y - 2);
    plot1(x + 8, y - 3); plot1(x + 8, y - 1); plot1(x + 9, y - 3); plot1(x + 9, y - 1);
    plot1(x + 9, y - 2);
    for(x = X_BATT_INITIAL ; x != X_BATT_INITIAL + 9 ; x++){plot1(x , y - 4);plot1(x , y);}
    goto_lico(1, 36); draw_char('%');
    
    //Vitesse (cercle de 81px de large)
    //Dessin du cercle
    y = Y_COMPTEUR;
    x = X_COMPTEUR;
    plot1(x,y);
    for(i = 1; i <= 2; i++)
    {
        char s;
        if(i==1){s = 1;}
        else{s = -1;}
        plot1(x+1*s,y);plot1(x+2*s,y);plot1(x+3*s,y);plot1(x+4*s,y);plot1(x+5*s,y);plot1(x+6*s,y);
        plot1(x+7*s,y+1);plot1(x+8*s,y+1);plot1(x+9*s,y+1);plot1(x+10*s,y+1);
        plot1(x+11*s,y+2);plot1(x+12*s,y+2);plot1(x+13*s,y+2);
        plot1(x+14*s,y+3);plot1(x+15*s,y+3);plot1(x+16*s,y+3);
        plot1(x+17*s,y+4);plot1(x+18*s,y+4);
        plot1(x+19*s,y+5);plot1(x+20*s,y+5);
        plot1(x+21*s,y+6);
        plot1(x+22*s,y+7);plot1(x+23*s,y+7);
        plot1(x+23*s,y+8);
        plot1(x+24*s, y+9);
        plot1(x+25*s, y+10);plot1(x+26*s, y+10);
        plot1(x+26*s, y+11);
        plot1(x+27*s, y+12);
        plot1(x+28*s, y+13);plot1(x+28*s, y+14);
        plot1(x+29*s, y+15);
        plot1(x+30*s, y+16);
        plot1(x+31*s, y+17);plot1(x+31*s, y+18);
        plot1(x+32*s, y+19);
        plot1(x+33*s, y+20);plot1(x+33*s, y+21);
        plot1(x+34*s, y+22);plot1(x+34*s, y+23);
        plot1(x+35*s, y+24);plot1(x+35*s, y+25);plot1(x+35*s, y+26);
        plot1(x+36*s, y+27);plot1(x+36*s, y+28);plot1(x+36*s, y+29);
        plot1(x+37*s, y+30);plot1(x+37*s, y+31);plot1(x+37*s, y+32);plot1(x+37*s, y+33);
        plot1(x+38*s, y+34);plot1(x+38*s, y+35);plot1(x+38*s, y+36);plot1(x+38*s, y+37);plot1(x+38*s, y+38);
    }
    //Dessin rond centrale
    plot1(x+3, y+37);plot1(x+2, y+37);plot1(x+1, y+37);plot1(x, y+37);plot1(x-1, y+37);plot1(x-2, y+37);plot1(x-3, y+37);
    plot1(x+2, y+36);plot1(x+1, y+36);plot1(x, y+36);plot1(x-1, y+36);plot1(x-2, y+36);
    plot1(x+1, y+35);plot1(x, y+35);plot1(x-1, y+35);
    
    //dessins marqueurs et numéro
    for(i = 1; i <= 2; i++)
    {
        char s;
        if(i==1){s = 1;}
        else{s = -1;}
        plot1(x+34*s, y+21);plot1(x+33*s, y+21);plot1(x+33*s, y+22);plot1(x+32*s, y+22);plot1(x+31*s, y+22);
        plot1(x+20*s, y+6);plot1(x+19*s, y+6);plot1(x+19*s, y+7);plot1(x+19*s, y+8);plot1(x+18*s, y+8);plot1(x+18*s, y+9);
        plot1(x+35*s, y+36);plot1(x+36*s, y+36);plot1(x+37*s, y+36);plot1(x+38*s, y+36);
    }
    plot1(x, y+1);plot1(x, y+2);plot1(x, y+3);plot1(x, y+4);            //marqueur central
    goto_lico(15, 15);draw_char(0x30);goto_lico(15, 24);draw_char(0x36);//Chiffre 0 et 6
    goto_lico(14, 15);draw_char(0x31);goto_lico(14, 24);draw_char(0x35);//Chiffre 1 et 5
    goto_lico(13, 17);draw_char(0x32);goto_lico(13, 22);draw_char(0x34);//chiffre 2 et 4
    goto_lico(12, 20); draw_char(0x33);                                 //chiffre 3
    
    //thermometre 1&2
    for(l = 0; l <= 1; l++)
    {
        if(l==0){x = X_INITIAL_THERMO_EAU;}
        else{x = X_INITIAL_THERMO_HUILE;} 
        y = Y_INITIAL_THERMO;
        plot1(x, y);
        for(i = 1; i <= 2; i++)
        {
            //dessin du cercle
            char s;
            if(i==1){s = 1;}
            else{s = -1;}
            plot1(x+1*s, y);plot1(x+2*s, y);
            plot1(x+3*s, y-1);plot1(x+4*s, y-1);
            plot1(x+4*s, y-2);
            plot1(x+5*s, y-3);plot1(x+5*s, y-4);
            plot1(x+6*s, y-5);plot1(x+6*s, y-6);plot1(x+6*s, y-7);plot1(x+6*s, y-8);plot1(x+6*s, y-9);
            plot1(x+5*s, y-10);plot1(x+5*s, y-11);
            plot1(x+4*s, y-12);
            plot1(x+3*s, y-13); //plot1(x+2*s, y-13);
            //dessin du haut du thermo
            for(j = 0; j < 38 ; j++)
            {
                plot1(x+3*s, y-14-j);
            }
            //remlpissage cercle
            for(j = 0; j < 9; j++)
            {
                for(k = 0; k < 3; k++)
                {
                   plot1(x+k*s, y-11+j);
                }
            }
            for(j = 0; j < 3; j++)
            {
                for(k = 0; k < 4; k++)
                {
                   plot1(x+j*s+2*s, y-8+k);
                }
            }            
            plot1(x+3*s, y-4);plot1(x+3*s, y-9);
            plot1(x+1*s, y-2);plot1(x+1*s, y-12);
        }
        plot1(x, y-2);plot1(x, y-12);
    }
    
    goto_lico(6, 5);
    draw_string("EAU");
    goto_lico(14, 7);
    draw_string("'C");
    
    goto_lico(6,31);
    draw_string("HUILE");
    goto_lico(14, 34);
    draw_string("'C");
    
    goto_lico(1, 1);
    draw_string("FORKLIFT SIMULATOR");
    goto_lico(3, 1);
    draw_string("Conducteur      Clef      Frein a main");
}

void gui_update_batterie(char batt)
{
    unsigned char x = X_BATT_INITIAL+1;
    unsigned char y = Y_BATT_INITIAL;
    unsigned char i = 0;
    goto_lico(1,33);
    draw_dec8(batt);
    if(batt != 0)   //si batterie non nulle
    {
        if(batt <= 15)
        {
           for(i = 1; i <= 3; i++)       //Batterie faible (<15%)
           {
               plot1(x, y-i); plot0(x+1, y-i);                //affichage cran batt faible      
               plot0(x+2, y-i); plot0(x+3, y-i);                //effaçage cran batt moitié
               plot0(x+4, y-i); plot0(x+5, y-i);                //effacage cran batt 3/4
               plot0(x+6, y-i);                               //effaçage cran batt < 99
           } 
        }
        else if((batt > 15) && (batt <= 25))  //Quart de batterie
        {
            for(i = 1; i <= 3; i++)
           {
               plot1(x, y-i); plot1(x+1, y-i);                //affichage cran batt faible
               plot0(x+2, y-i); plot0(x+3, y-i);                //effaçage cran batt moitié
               plot0(x+4, y-i); plot0(x+5, y-i);                //effaçage cran batt 3/4
               plot0(x+6, y-i);                               //effaçage cran batt < 99
           } 
        }
        else if((batt > 25) && (batt <= 50))  //moitié de batterie
        {
            for(i = 1; i <= 3; i++)
           {
                plot1(x, y-i); plot1(x+1, y-i);               //affichage cran batt faible
                plot1(x+2, y-i); plot1(x+3, y-i);               //affichage cran batt moitié
                plot0(x+4, y-i); plot0(x+5, y-i);               //effaçage cran batt 3/4
                plot0(x+6, y-i);                              //effaçage cran batt < 99
            }
        }
        else if((batt > 50) && (batt <= 75))  //moitié de batterie
        {
            for(i = 1; i <= 3; i++)
           {
                plot1(x, y-i); plot1(x+1, y-i);                //affichage cran batt faible
                plot1(x+2, y-i); plot1(x+3, y-i);                //affichage cran batt moitié
                plot1(x+4, y-i); plot1(x+5, y-i);                //affichage cran batt 3/4
                plot0(x+6, y-i);                               //effaçage  cran batt < 99
            }
        }
        else if((batt > 75))                 //moitié haute
        {
            for(i = 1; i <= 3; i++)
           {
                plot1(x, y-i); plot1(x+1, y-i);                //affichage cran batt faible
                plot1(x+2, y-i); plot1(x+3, y-i);                //affichage cran batt moitié
                plot1(x+4, y-i); plot1(x+5, y-i);                //affichage cran batt 3/4
                plot1(x+6, y-i);                               //effaçage  cran batt < 99
            }
        }
        if(batt == 100){plot1(x+7, y - 2);}                      //si batt pleine, pixel bout de batt plein
        else{plot0(x+7, y - 2);}
    }
    else    //sinon batterie vide
    {
        for(i = 1; i < 3; i++)       //Batterie vide
           {
               plot0(230, y-i); plot0(231, y-i);                //affichage cran batt faible      
               plot0(232, y-i); plot0(233, y-i);                //effaçage cran batt moitié
               plot0(234, y-i); plot0(235, y-i);                //effacage cran batt 3/4
               plot0(236, y-i);                               //effaçage cran batt < 99
           } 
    }
}

void gui_update_vitesse(char vit, char vit_1)
{
    gui_erase_aiguille_vitesse(vit_1);
    gui_draw_aiguille_vitesse(vit);
}

void gui_draw_aiguille_vitesse(char vit)
{
    unsigned char x = X_COMPTEUR;
    unsigned char y = Y_COMPTEUR + 37; //point de départ = centre du cercle
    char s;
    unsigned char i;
    if((vit == 0)||(vit == 1)||(vit == 2)){s = -1;}
    else{s = 1;}
    
    if(vit == 3)
    {
        for(i = 3; i < 15 ; i++)
        {
            plot1(x, y-i);
        }
    }
    else if((vit == 1)||(vit == 5))
    {
        plot1(x+3*s, y-1);
        plot1(x+4*s, y-2);plot1(x+5*s, y-2);
        plot1(x+6*s, y-3);plot1(x+7*s, y-3);
        plot1(x+8*s, y-4);plot1(x+9*s, y-4);
        plot1(x+10*s, y-5);plot1(x+11*s, y-5);
        plot1(x+12*s, y-6);plot1(x+13*s, y-6);
        plot1(x+14*s, y-7);plot1(x+15*s, y-7);
        plot1(x+16*s, y-8);
    }
    else if((vit == 2)||(vit == 4))
    {
        plot1(x+2*s, y-3);
        plot1(x+3*s, y-4);plot1(x+3*s, y-5);
        plot1(x+4*s, y-6);
        plot1(x+5*s, y-7);plot1(x+5*s, y-8);
        plot1(x+6*s, y-9);plot1(x+6*s, y-10);
        plot1(x+7*s, y-11);
        plot1(x+8*s, y-12);plot1(x+8*s, y-13);
        plot1(x+9*s, y-14);
    }
    else if((vit == 0)||(vit == 6))
    {
        for(i = 3; i < 16; i++)
        {
            plot1(x+i*s, y-1);
        }
    }
}

void gui_erase_aiguille_vitesse(char vit)
{
    unsigned char x = X_COMPTEUR;
    unsigned char y = Y_COMPTEUR + 37; //point de départ = centre du cercle
    char s;
    unsigned char i;
    if((vit == 0)||(vit == 1)||(vit == 2)){s = -1;}
    else{s = 1;}
    
    if(vit == 3)
    {
        for(i = 3; i < 15 ; i++)
        {
            plot0(x, y-i);
        }
    }
    else if((vit == 1)||(vit == 5))
    {
        plot0(x+3*s, y-1);
        plot0(x+4*s, y-2);plot0(x+5*s, y-2);
        plot0(x+6*s, y-3);plot0(x+7*s, y-3);
        plot0(x+8*s, y-4);plot0(x+9*s, y-4);
        plot0(x+10*s, y-5);plot0(x+11*s, y-5);
        plot0(x+12*s, y-6);plot0(x+13*s, y-6);
        plot0(x+14*s, y-7);plot0(x+15*s, y-7);
        plot0(x+16*s, y-8);
    }
    else if((vit == 2)||(vit == 4))
    {
        plot0(x+2*s, y-3);
        plot0(x+3*s, y-4);plot0(x+3*s, y-5);
        plot0(x+4*s, y-6);
        plot0(x+5*s, y-7);plot0(x+5*s, y-8);
        plot0(x+6*s, y-9);plot0(x+6*s, y-10);
        plot0(x+7*s, y-11);
        plot0(x+8*s, y-12);plot0(x+8*s, y-13);
        plot0(x+9*s, y-14);
    }
    else if((vit == 0)||(vit == 6))
    {
        for(i = 3; i < 16; i++)
        {
            plot0(x+i*s, y-1);
        }
    }
}

void gui_update_temperature(char t_eau, char t_huile)
{
    unsigned char N = 0;
    unsigned char i = 0;
    
    //raz des afficheurs (si ça rend le système trop lent, alors utiliser un sample temp_n-1)
    for(i = 0; i < 36; i++)
    {
        plot0(X_INITIAL_THERMO_HUILE - 1, Y_INITIAL_THERMO -13 -i); plot0(X_INITIAL_THERMO_HUILE, Y_INITIAL_THERMO -13 -i); plot0(X_INITIAL_THERMO_HUILE + 1, Y_INITIAL_THERMO -13 -i);
        plot0(X_INITIAL_THERMO_EAU - 1, Y_INITIAL_THERMO -13 -i); plot0(X_INITIAL_THERMO_EAU, Y_INITIAL_THERMO -13 -i); plot0(X_INITIAL_THERMO_EAU + 1, Y_INITIAL_THERMO -13 -i);
    }
    
    //valeur de température entre 0 et 255, il y a 36 lignes de pixel
    //donc N lignes coloriées = temp * 36 / 255
    N = t_eau * 36 / 255;
    for(i = 0; i < N; i++)
    {
      plot1(X_INITIAL_THERMO_EAU - 1, Y_INITIAL_THERMO -13 -i); plot1(X_INITIAL_THERMO_EAU, Y_INITIAL_THERMO -13 -i); plot1(X_INITIAL_THERMO_EAU + 1, Y_INITIAL_THERMO -13 -i);  
    }
    
    N = t_huile * 36 / 255;
    for(i = 0; i < N; i++)
    {
        plot1(X_INITIAL_THERMO_HUILE - 1, Y_INITIAL_THERMO -13 -i); plot1(X_INITIAL_THERMO_HUILE, Y_INITIAL_THERMO -13 -i); plot1(X_INITIAL_THERMO_HUILE + 1, Y_INITIAL_THERMO -13 -i);
    }
    goto_lico(14, 4);
    draw_dec8(t_eau);
    
    goto_lico(14,31);
    draw_dec8(t_huile);
    
    //gui_temp_alert(t_eau, t_huile);
}

void gui_temp_alert(unsigned char t_eau, unsigned char t_huile) //a changer
{
    //Si on dépasse le suil de temp, on dessine un point d'exclamation dans le thermo et on passe l'écran en rouge
    if(t_eau >= T_SEUIL_EAU)
    {plot0(X_INITIAL_THERMO_EAU, Y_INITIAL_THERMO - 4); plot0(X_INITIAL_THERMO_EAU, Y_INITIAL_THERMO - 6); plot0(X_INITIAL_THERMO_EAU, Y_INITIAL_THERMO - 7); plot0(X_INITIAL_THERMO_EAU, Y_INITIAL_THERMO - 8); plot0(X_INITIAL_THERMO_EAU, Y_INITIAL_THERMO - 9);}
    else{plot1(X_INITIAL_THERMO_EAU, Y_INITIAL_THERMO - 4); plot1(X_INITIAL_THERMO_EAU, Y_INITIAL_THERMO - 6); plot1(X_INITIAL_THERMO_EAU, Y_INITIAL_THERMO - 7); plot1(X_INITIAL_THERMO_EAU, Y_INITIAL_THERMO - 8); plot1(X_INITIAL_THERMO_EAU, Y_INITIAL_THERMO - 9);}
    
    if(t_huile >= T_SEUIL_HUILE)
    {plot0(X_INITIAL_THERMO_HUILE, Y_INITIAL_THERMO - 4); plot0(X_INITIAL_THERMO_HUILE, Y_INITIAL_THERMO - 6); plot0(X_INITIAL_THERMO_HUILE, Y_INITIAL_THERMO - 7); plot0(X_INITIAL_THERMO_HUILE, Y_INITIAL_THERMO - 8); plot0(X_INITIAL_THERMO_HUILE, Y_INITIAL_THERMO - 9);}
    else{plot1(X_INITIAL_THERMO_HUILE, Y_INITIAL_THERMO - 4); plot1(X_INITIAL_THERMO_HUILE, Y_INITIAL_THERMO - 6); plot1(X_INITIAL_THERMO_HUILE, Y_INITIAL_THERMO - 7); plot1(X_INITIAL_THERMO_HUILE, Y_INITIAL_THERMO - 8); plot1(X_INITIAL_THERMO_HUILE, Y_INITIAL_THERMO - 9);}
    
    if(t_huile >= T_SEUIL_HUILE | t_eau >= T_SEUIL_EAU)
    {LED_G=1; LED_B=1;}
    else{LED_G=0; LED_B=0;}
}