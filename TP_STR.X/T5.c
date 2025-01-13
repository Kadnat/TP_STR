#include "T5.h"

/**
 * Tâche 5: Gestion de la batterie et calcul de la vitesse moyenne
 * Cette tâche s'occupe de :
 * - Calculer la consommation de la batterie
 * - Gérer la vitesse moyenne du véhicule
 * - Mettre à jour l'état de la batterie
 */
void tache5(void) {
    // Initialisation des variables de timing
    unsigned int length_tick = 100;         // Période d'actualisation
    
    // Variables pour le calcul de vitesse moyenne
    unsigned char sample_vitesse[20];       // Tableau des échantillons de vitesse
    unsigned char sample_count = 10;        // Nombre d'échantillons à moyenner
    unsigned char average_speed = 0;        // Vitesse moyenne calculée
    
    // Initialisation des états
    batterie = 100;                        // Niveau initial de batterie
    vitesse = 0;                           // Vitesse initiale
    buffer_batterie = batterie * 100;      // Buffer pour calculs précis
    passageT5 = 0;
    
    while(1) {   
        if(batterie != 0) {  // Traitement uniquement si batterie non vide
            if(passageT5 == 0) {
                if(cptT5 == sample_count) {
                    // Calcul de la vitesse moyenne
                    for(char i = 0; i < sample_count; i++) {
                        average_speed += sample_vitesse[i];
                    }
                    average_speed = average_speed / sample_count;
                    
                    // Mise à jour du niveau de batterie (formule: b% = b - 0.15x - 0.1)
                    buffer_batterie = buffer_batterie - 15 * average_speed - 10;
                    batterie = buffer_batterie / 100;
                    cptT5 = 0;
                } else {
                    // Échantillonnage de la vitesse
                    sample_vitesse[cptT5] = vitesse;
                    cptT5++;
                }
                passageT5 = 1;
            }
        } else {
            // Réinitialisation si batterie vide
            for(char i = 0; i<sample_count; i++)
            {
                sample_vitesse[i]=0;
            }
            average_speed = 0;   
        }
    }
}