/**
* @file voyants.h
* @brief Ce fichier d'en-tete contiendra la class Voyants.
*
* @author Youssef Abbih
*
* @date 25/04/2020
*/

#ifndef VOYANTS_H
#define VOYANTS_H
#include <lcarte.h>
#include "donnees_borne.h"
#include "mem_sh.h"
#include "donnees.h"
#include "timer.h"
using namespace std;


  /*! \class Voyants
   * \brief classe representant les voyants de la borne
   *
   *  La classe gere les voyants de la borne
   */
class Voyants
{

    private :
		entrees *io;
		int shmid;	
	public : 

        Voyants();
		void set_charge_vert();
		void set_charge_rouge();
		void set_dispo_rouge();
		void clign_def();
		void clignoter();
        void charge_disp_rouge();
		



};



#endif // VOYANTS_H
