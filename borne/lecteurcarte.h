/**
* @file lecteurcarte.h
* @brief Ce fichier d'en-tete contiendra la class LecteurCarte.
*
* @author Youssef Abbih
*
* @date 25/04/2020
*/

#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H
#include <lcarte.h>
#include <memoire_borne.h>
#include <donnees_borne.h>
#include <iostream>
#include <new>
#include "base_clients.h"
#include "voyants.h"
#include "timer.h"
#include "bouton.h"
#include "generateur_save.h"


using namespace std;


  /*! \class LecteurCarte
   * \brief classe representant le lecteur carte de la borne.
   *
   *  lecture du numéro de la carte, et l’authentification du client
   */
class LecteurCarte : protected BaseClient, protected Voyants, protected Prise, protected Timer, protected Bouton, protected GenerateurSave
{

	private :          
		entrees *io;
		int shmid;
		int numero;
		int resultclient;
		int idok;	

	public :           
		
		LecteurCarte();
		void initialiser();
		void lire_carte();



};

#endif // LECTEURCARTE_H
