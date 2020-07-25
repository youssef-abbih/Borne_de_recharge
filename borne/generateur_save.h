/**
* @file generateur_save.h
* @brief Ce fichier d'en-tete contiendra la class GenerateurSave.
*
* @author Youssef Abbih
*
* @date 25/04/2020
*/

#ifndef GS_H
#define GS_H
#include <iostream>
#include <lcarte.h>
#include "prise.h"
#include "donnees_borne.h"
#include "mem_sh.h"
#include "donnees.h"
#include "voyants.h"
#include <donnees_borne.h>
#include <memoire_borne.h>
#include"base_clients.h"
#include "bouton.h"

using namespace std;

/**
 * \enum etatMEF
 * \brief etats que peut prendre la MEF.
 *
 * etatMEF est une serie de constantes predefinie qui represetent l'etats que peut prendre la MEF.
 */
typedef enum etatMEF {etatA,etatB,etatC,etatD,etatE,etatF} etat;

  /*! \class GenerateurSave
   * \brief classe representant la mef de pour charger la batterie
   *
   *  La classe gere la MEF
   */
class GenerateurSave
{
      private :
		entrees *io;
		int shmid;
		int Fin;
		int num;
		etatMEF etat; 

	public : 
		GenerateurSave();
		void generer_PWM();
		float tension();
		void genSAVE_mef();
		void deconnecter();
		void generer_PWMAC();
		void generer_PWMCL();
		void ouvrir_AC();
		void fermer_AC();
		void init_led();
		int verfier_reprise();


};



#endif 
