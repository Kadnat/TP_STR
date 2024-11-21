#include "semaphore.h"


// Initialisation d'un s�maphore
void semaphore_init(unsigned char jetons_initiaux) {
    semaphores.jetons = jetons_initiaux;
    semaphores.max_jetons = jetons_initiaux;
    semaphores.attente = 0;
}

// Acquisition non bloquante du s�maphore
unsigned char semaphore_tryacquire(unsigned char tache) {
    if (semaphores.jetons > 0) {
        semaphores.jetons--;
        return 1; // Succ�s
    }
    
    // Si pas de jeton, ajoute la t�che � la liste d'attente
    semaphores.attente |= (1 << tache);
    return 0; // �chec
}

// Lib�ration du s�maphore
void semaphore_release(void) {
    if (semaphores.jetons < semaphores.max_jetons) {
        semaphores.jetons++;
        
        // R�veille une t�che en attente
        for (unsigned char i = 0; i < NOMBRE_DE_TACHES; i++) {
            if (semaphores.attente & (1 << i)) {
                // Retire la t�che de la liste d'attente
                semaphores.attente &= ~(1 << i);
                break;
            }
        }
    }
}