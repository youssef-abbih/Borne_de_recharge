
/**
* @file bouton.cpp
* @brief Ce fichier contiendra les definition des methodes de la class Bouton
*
* @author Youssef Abbih
*
* @date 25/04/2020
*
**/
#include "bouton.h"


/**
* Cette methode sera utilisee pour initialisation de la memoire partagee.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
Bouton::Bouton()
{
	
	io=acces_memoire(&shmid);
		
}

/**
* Cette methode sera utilisee pour retourne l'etat du bouton charge .
* @author Youssef Abbih
* @param void
* @return 1 or 0
* @date 25/04/2020
*/
int Bouton :: boutons_charge()
{

if (io->bouton_charge==1) return 1;
else return 0;
}

/**
* Cette methode sera utilisee pour retourne l'etat du bouton stop.
* @author Youssef Abbih
* @param void
* @return 1 or 0
* @date 25/04/2020
*/
int Bouton :: boutons_stop()
{
if (io->bouton_stop==1) return 1;
else return 0;
}

/**
* Cette methode sera utilisee pour initialiser l'etat du voyant "disponible".
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void Bouton::boutons_init()
{

	io->led_dispo=VERT;
	
}

