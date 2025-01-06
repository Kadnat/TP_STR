/* 
 * File:   afficheur.h
 * Author: Franck
 *
 * Created on 29 janvier 2015, 18:14
 */

#ifndef GUI_H
#define	GUI_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "main.h"

#define X_BATT_INITIAL 225 
#define Y_BATT_INITIAL 13
    
#define X_COMPTEUR  120
#define Y_COMPTEUR  90
    
#define X_INITIAL_THERMO_EAU    40
#define X_INITIAL_THERMO_HUILE  199
#define Y_INITIAL_THERMO        110
    
    
#define T_SEUIL_EAU 100
#define T_SEUIL_HUILE 110
    
void gui_init();
void gui_update_batterie(char batterie);
void gui_update_vitesse(char vit, char vit_1);
void gui_draw_aiguille_vitesse(char vit);
void gui_erase_aiguille_vitesse(char vit);
void gui_update_temperature(char t_eau, char t_huile);
void gui_temp_alert(unsigned char t_eau, unsigned char t_huile);


#endif	/* GUI_H */
