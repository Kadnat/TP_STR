/* 
 * File:   variables_globales.h
 * Author: Franck
 *
 * Created on 29 janvier 2015, 09:59
 */

/*
 * CARTOGRAPHIE MÉMOIRE:
 * --------------------
 * 0x60-0x64 : Variables temporaires pour la sauvegarde de contexte
 * 0x65      : Variable de démarrage
 * 0x69-0x6F : File d'attente des tâches
 * 0x70-0x72 : Variables système (pointeur et compteur)
 * 0x80-0x83 : Variables de mutex et communication
 * 0x700-0x745: Variables globales des tâches
 * 0x801-0x804: Kilométrage
 * 0x100-0x142: Contexte tâche 1
 * 0x200-0x242: Contexte tâche 2
 * 0x300-0x342: Contexte tâche 3
 * 0x400-0x442: Contexte tâche 4
 * 0x500-0x542: Contexte tâche 5
 * 0x600-0x642: Contexte tâche 6
 */

#ifndef VARIABLES_GLOBALES_H
#define	VARIABLES_GLOBALES_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "main.h"

            /* Constantes */
#define     NOMBRE_DE_TACHES        6
#define     TACHE1                  1
#define     TACHE2                  2
#define     TACHE3                  3
#define     TACHE4                  4
#define     TACHE5                  5
#define     TACHE6                  6

/* Variables de sauvegarde de contexte */
unsigned char W_TEMPORAIRE         __at(0xA00);    // Sauvegarde W
unsigned char STATUS_TEMPORAIRE    __at(0xA01);    // Sauvegarde STATUS
unsigned char BSR_TEMPORAIRE       __at(0xA02);    // Sauvegarde BSR
unsigned char FSR0H_TEMPORAIRE     __at(0xA03);    // Sauvegarde FSR0H
unsigned char FSR0L_TEMPORAIRE     __at(0xA04);    // Sauvegarde FSR0L
unsigned char DEMARRAGE            __at(0xA05);    // Flag de démarrage système

/* Variables système */
unsigned char queue[NOMBRE_DE_TACHES]  __at(0xA09);    // File d'attente des tâches
unsigned char tache_active             __at(0xA0F);    // Tâche en cours d'exécution
unsigned char pointeur_de_tache        __at(0xA10);    // Pointeur de tâche courante
unsigned int Tick_Count                __at(0xA11);    // Compteur système

/* Variables de mutex et communication */
unsigned char RXTX_libre              __at(0xA14);    // État communication série
unsigned char mutexT1Flag             __at(0xA15);    // Mutex tâche 1
unsigned char mutexT6Flag             __at(0xA16);    // Mutex tâche 6
typedef union {
    unsigned char val; // Repr�sentation brute (8 bits) du mutex
    struct {
        unsigned libre:1;      // Bit 0 : 1 si mutex libre, 0 si pris
        unsigned attente:7;    // Bits 1-7 : bitmap des t�ches en attente (une t�che par bit)
    };
} Mutex_t;
Mutex_t mutex __at(0xA17);

/* Variables Tâche 1 - Gestion des entrées */
unsigned char n                       __at(0x745);    // Compteur général
unsigned char buffer_vitesse_plus     __at(0x700);    // Buffer vitesse +
unsigned char buffer_vitesse_moins    __at(0x701);    // Buffer vitesse -
unsigned char vitesse                 __at(0x703);    // Vitesse courante
unsigned char batterie                __at(0x704);    // Niveau batterie
unsigned char badge[10]               __at(0x730);    // Buffer badge RFID
unsigned char n_octet_badge           __at(0x705);    // Compteur octets badge
unsigned char ANALOG_TEMP_HUILE       __at(0x706);    // Température huile
unsigned char ANALOG_TEMP_EAU         __at(0x707);    // Température eau
unsigned char ANALOG_JOYSTICK_X       __at(0x708);    // Position X joystick
unsigned char ANALOG_JOYSTICK_Y       __at(0x709);    // Position Y joystick

/* Variables Tâche 2 - Gestion des alarmes */
unsigned char alarme_frein            __at(0x70A);    // État alarme frein
unsigned char alarme_cle              __at(0x70B);    // État alarme clé
unsigned char alarme_eau              __at(0x70C);    // État alarme eau
unsigned char alarme_huile            __at(0x70D);    // État alarme huile
unsigned char alarme_batterie         __at(0x70E);    // État alarme batterie
unsigned char alarme_choc             __at(0x70F);    // État alarme choc
unsigned char alarme_conducteur       __at(0x710);    // État alarme conducteur

/* Variables Tâche 3 - Gestion de l'EEPROM */
unsigned char passageT3               __at(0x711);    // Compteur passage T3
unsigned int counter_T3               __at(0x712);    // Compteur général T3

/* Variables Tâche 5 - Gestion batterie */
unsigned char cptT5                   __at(0x714);    // Compteur T5
unsigned char passageT5               __at(0x715);    // Compteur passage T5
unsigned int buffer_batterie          __at(0x716);    // Buffer niveau batterie

/* Variables système - Kilométrage */
unsigned char km[4]                   __at(0x801);    // Compteur kilométrage
typedef struct {
    uint8_t priority;
    uint16_t period;    // multiple de 10ms
    uint16_t next_tick;
    uint8_t is_ready;
} TaskControl;
TaskControl task_control[NOMBRE_DE_TACHES] __at(0x805);

uint8_t i_m __at(0x900);
uint8_t i_mutex2 __at(0x901);
uint8_t highest_prio __at(0x902);

/* Contextes des tâches */
unsigned char contexte1[66] __at(0x100);    // Contexte tâche 1
unsigned char contexte2[66] __at(0x200);    // Contexte tâche 2
unsigned char contexte3[66] __at(0x300);    // Contexte tâche 3
unsigned char contexte4[66] __at(0x400);    // Contexte tâche 4
unsigned char contexte5[66] __at(0x500);    // Contexte tâche 5
unsigned char contexte6[66] __at(0x600);    // Contexte tâche 6

/* Pointeurs de pile des tâches */
unsigned char STKPTR_T1               __at(0x103);    // Pointeur pile T1
unsigned char STKPTR_T2               __at(0x203);    // Pointeur pile T2
unsigned char STKPTR_T3               __at(0x303);    // Pointeur pile T3
unsigned char STKPTR_T4               __at(0x403);    // Pointeur pile T4
unsigned char STKPTR_T5               __at(0x503);    // Pointeur pile T5
unsigned char STKPTR_T6               __at(0x603);    // Pointeur pile T6

    //pointeur de fonction
        //il va servir a modifier la pile pour executer les taches
void (*fptr)(void);
unsigned short int val_tos;
unsigned char * puc;
unsigned char tc[3];

#ifdef	__cplusplus
}
#endif

#endif	/* VARIABLES_GLOBALES_H */

