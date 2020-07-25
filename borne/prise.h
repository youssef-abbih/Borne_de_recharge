/**
* @file prise.h
* @brief Ce fichier d'en-tete contiendra la class Prise.
*
* @author Youssef Abbih
*
* @date 25/04/2020
*/

#ifndef PRISE_H
#define PRISE_H
#include <lcarte.h>
#include "donnees_borne.h"
#include "mem_sh.h"
#include "donnees.h"
#include "voyants.h"

using namespace std;

  /*! \class Prise
   * \brief classe representant le prise de la borne
   *
   *  La classe gere le prise de la borne
   */
class Prise
{
	
	private :
		entrees *io;
		int shmid;	
	public : 
		
        Prise();
		void dev_trappe();
		void ver_trappe();
		void set_prise();



};




#endif // PRISE_H
