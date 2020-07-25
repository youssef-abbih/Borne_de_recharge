/**
* @file bouton.h
* @brief Ce fichier d'en-tête contiendra la class Bouton.
*
* @author Youssef Abbih
*
* @date 25/04/2020
*/

#ifndef BOUTONS_H
#define BOUTONS_H
#include <lcarte.h>
#include "timer.h"
#include <iostream>
#include "donnees_borne.h"
#include "mem_sh.h"
#include "donnees.h"

using namespace std;

  /*! \class Bouton
   * \brief classe representant les boutons de la borne
   *
   *  La classe gere les boutons de la borne
   */
class Bouton
{
    private :
	entrees *io;
	int shmid; 

	public : 
		Bouton();
		void boutons_init();
        int boutons_charge();
        int boutons_stop();
        
        

};



#endif // BOUTONS_H
