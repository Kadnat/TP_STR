#include "semaphore.h"


// Initialisation d'un sémaphore
void semaphore_init(unsigned char jetons_initiaux) {
    semaphores.jetons = jetons_initiaux;
    semaphores.max_jetons = jetons_initiaux;
    semaphores.attente = 0;
}

// Acquisition non bloquante du sémaphore
unsigned char semaphore_tryacquire(unsigned char tache) {
    if (semaphores.jetons > 0) {
        semaphores.jetons--;
        return 1; // Succès
    }
    
    // Si pas de jeton, ajoute la tâche à la liste d'attente
    semaphores.attente |= (1 << tache);
    return 0; // Échec
}

// Libération du sémaphore
void semaphore_release(void) {
    if (semaphores.jetons < semaphores.max_jetons) {
        semaphores.jetons++;
        
        // Réveille une tâche en attente
        for (unsigned char i = 0; i < NOMBRE_DE_TACHES; i++) {
            if (semaphores.attente & (1 << i)) {
                // Retire la tâche de la liste d'attente
                semaphores.attente &= ~(1 << i);
                break;
            }
        }
    }
}