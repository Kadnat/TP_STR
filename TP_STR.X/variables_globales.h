/* 
 * File:   variables_globales.h
 * Author: Franck
 *
 * Created on 29 janvier 2015, 09:59
 */

#ifndef VARIABLES_GLOBALES_H
#define	VARIABLES_GLOBALES_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "main.h"
#include "systeme.h"

            /* Constantes */
#define     NOMBRE_DE_TACHES        6
#define     TACHE1                  1
#define     TACHE2                  2
#define     TACHE3                  3
#define     TACHE4                  4
#define     TACHE5                  5
#define     TACHE6                  6

/* Variables globales */
    // On stock dans la bank0 on laisse la zone access ram (00-5F) pour le compilateur
unsigned char W_TEMPORAIRE         __at(0x60);
unsigned char STATUS_TEMPORAIRE    __at(0x61);
unsigned char BSR_TEMPORAIRE       __at(0x62);
unsigned char FSR0H_TEMPORAIRE     __at(0x63);
unsigned char FSR0L_TEMPORAIRE     __at(0x64);
unsigned char DEMARRAGE            __at(0x65);


unsigned char queue[NOMBRE_DE_TACHES]        __at(0x69);
unsigned char tache_active         __at(0x6F);
unsigned char pointeur_de_tache    __at(0x70);
unsigned int Tick_Count            __at(0x71);
unsigned char RXTX_libre        __at(0x80);
unsigned char mutexT1Flag __at(0x81);
unsigned char mutexT6Flag __at(0x82);

typedef union {
    unsigned char val; // Repr�sentation brute (8 bits) du mutex
    struct {
        unsigned libre:1;      // Bit 0 : 1 si mutex libre, 0 si pris
        unsigned attente:7;    // Bits 1-7 : bitmap des t�ches en attente (une t�che par bit)
    };
} Mutex_t;
unsigned char Mutex_t mutex __at(0x83);




//var glob tache 1

unsigned char n __at(0x745);
unsigned char buffer_vitesse_plus __at(0x700);
unsigned char buffer_vitesse_moins __at(0x701);
unsigned char vitesse              __at(0x703);
unsigned char batterie             __at(0x704);
unsigned char badge[10]            __at(0x730);
unsigned char n_octet_badge        __at(0x705);
unsigned char ANALOG_TEMP_HUILE     __at(0x706);
unsigned char ANALOG_TEMP_EAU       __at(0x707);
unsigned char ANALOG_JOYSTICK_X     __at(0x708);
unsigned char ANALOG_JOYSTICK_Y     __at(0x709);

//var glob tache 2
unsigned char alarme_frein __at(0x70A);
unsigned char alarme_cle __at(0x70B);
unsigned char alarme_eau __at(0x70C);
unsigned char alarme_huile __at(0x70D);
unsigned char alarme_batterie __at(0x70E);
unsigned char alarme_choc __at(0x70F);
unsigned char alarme_conducteur __at(0x710);

//var glob tache 3
unsigned char passageT3 __at(0x711);
unsigned int counter_T3 __at(0x712);

//var glob tache 5
unsigned char cptT5 __at(0x714);
unsigned char passageT5 __at(0x715);
unsigned int buffer_batterie __at(0x716);



//var glob tache 6


//Variable kilometrage (4 octets)
unsigned char km[4]                 __at(0x801);


    //pointeur de fonction
        //il va servir a modifier la pile pour executer les taches
void (*fptr)(void);
unsigned short int val_tos;
unsigned char * puc;
unsigned char tc[3];


//Contexte = 18 registres SFR + 48 octet de 00h � 2Fh = 66 octets
/* R�servation de la zone de 100h � 142h pour le contexte de la tache 1 */
/* R�servation de la zone de 200h � 242h pour le contexte de la tache 2 */
/* Ainsi de suite ...*/
/* Chaque contexte va utiliser 66 octets (0x42) au d�but de la banque correspondante */
unsigned char contexte1[66] __at(0x100);
unsigned char contexte2[66] __at(0x200);
unsigned char contexte3[66] __at(0x300);
unsigned char contexte4[66] __at(0x400);
unsigned char contexte5[66] __at(0x500);
unsigned char contexte6[66] __at(0x600);


unsigned char STKPTR_T1             __at(0x103);
unsigned char STKPTR_T2             __at(0x203);
unsigned char STKPTR_T3             __at(0x303);
unsigned char STKPTR_T4             __at(0x403);
unsigned char STKPTR_T5             __at(0x503);
unsigned char STKPTR_T6             __at(0x603);



#ifdef	__cplusplus
}
#endif

#endif	/* VARIABLES_GLOBALES_H */

