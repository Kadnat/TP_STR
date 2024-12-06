/* 
 * File:   semaphore.h
 * Author: Franck
 *
 * Created on 9 février 2015, 16:58
 */

#ifndef SEMAPHORE_H
#define	SEMAPHORE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "main.h"

// Liste des semaphores
    typedef struct {
        volatile unsigned char jetons;    
        volatile unsigned char max_jetons;
        volatile unsigned char attente;  
        volatile unsigned char tache_util;  
    } Semaphore;

    Semaphore semaphores __at(0x90);

    // Prototypes
    void semaphore_init(unsigned char jetons_initiaux);
    unsigned char semaphore_tryacquire(unsigned char tache);
    void semaphore_release(unsigned char tache);
    //reentrant void P(unsigned char sem);
    //reentrant void V(unsigned char sem);


#ifdef	__cplusplus
}
#endif

#endif	/* SEMAPHORE_H */

