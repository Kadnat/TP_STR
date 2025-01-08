/*
 * File:   mutex.c
 * Author: nathanaelblavo
 *
 * Created on January 8, 2025, 10:18 PM
 */
#include "mutex.h"
#include "main.h"

void mutex_init(void) {
    mutex.val = 0x01;      // mutex libre au départ
    mutexT1Flag = 0;
    mutexT6Flag = 0;
}

char mutex_acquire(char tache) {
    if(mutex.libre) {
        mutex.libre = 0;
        return 1;           // acquisition réussie
    }
    mutex.attente |= (1 << tache);  // marque tâche en attente
    return 0;              // échec acquisition
}

void mutex_release(char tache) {
    mutex.libre = 1;
    mutex.attente = 0;     // libère toutes les tâches en attente
}