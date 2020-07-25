/**
* @file lecteurcarte.cpp
* @brief Ce fichier contiendra les definition des methodes de la class LecteurCarte.
*
* @author Youssef Abbih
*
* @date 25/04/2020
*
**/

#include "lecteurcarte.h"


using namespace std;


/**
* Constructeur LecteurCarte.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
LecteurCarte::LecteurCarte()
{	
          io=acces_memoire(&shmid);	
}

/**
* Cette methode sera utilisee pour initialiser les ports.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void LecteurCarte::initialiser()   
{
	initialisations_ports();  
}

/**
* Cette methode sera utilisee pour la lecture du numero de la carte, et l’authentification du client.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void LecteurCarte::lire_carte()
{	
	boutons_init();

	cout << " Veuillez inserer votre carte SVP" << endl;
	
	attente_insertion_carte();
	carte_inseree();
	numero=lecture_numero_carte();

	cout << "le numero de votre carte inseree est: " << numero << endl ;
	resultclient=authentifier(numero);

	if(resultclient==1)
	{
		
		cout << "vous etes un client authentifie" << endl ;
		set_charge_vert();
  		clignoter();
		while(timer_valeur() <= 60)
		{
			if(boutons_charge()== 1)
			{
				idok = 1;
				break;
			}
		
		}
       		if(idok==1)                                      // si j'appuie sur le bouton charge il aura : 
		{
		
			charge_disp_rouge();                      // voyant dispo 
			cout << "Retirer votre carte SVP" << endl ;		
			attente_retrait_carte();  
			set_charge_rouge();  
			dev_trappe();   		                    //  Deverouiller la Trappe 
		   
			genSAVE_mef();                   // machine à etat generateur save
		}
		else
		{
			cout << "Retirer votre carte SVP" << endl ;
			attente_retrait_carte();
			return;
			
		}
	}
	else
	{	
		cout << "vous etes un client non authentifie" << endl ;
		cout << "Retirer votre carte SVP" << endl ;
		clign_def();
	}

	
	liberation_ports();
}


