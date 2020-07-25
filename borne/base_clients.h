/**
* @file base_clients.h
* @brief Ce fichier d'en-tête contiendra la class BaseClient.
*
* @author Youssef Abbih
*
* @date 25/04/2020
*/

#ifndef BASE_CLIENTS_H
#define BASE_CLIENTS_H
#include <lcarte.h>
#include <memoire_borne.h>
#include <donnees_borne.h>
#include <iostream>
using namespace std;


  /*! \class BaseClient
   *  \brief classe representant le lecteur
   *
   *  La classe gere la base clients utilisant la borne de recharge, elle cherche si le
   *  numéro de carte appariaient a cette base ou non
   */
class BaseClient
{

    private :

		int Nbr_clients ;
		int auth ;      
		unsigned short int *liste_clients;
		string line;
        int *aut ;
	public : 

        BaseClient();
		int authentifier(unsigned short int numero_carte);
		int reprise(int numero_reprise);
		


		
};

#endif // BASE_CLIENTS_H
