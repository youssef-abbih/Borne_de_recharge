/**
* @file voyants.cpp
* @brief Ce fichier contiendra les definition des methodes de la class Voyants.
*
* @author Youssef Abbih
*
* @date 25/04/2020
*
**/

#include <iostream>
#include "voyants.h"

/**
* Cette method sera utilisee pour insitialisation de la memoire partage.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
Voyants::Voyants()
{
	io=acces_memoire(&shmid);      
}

/**
* Cette method sera utilisee pour allumer le voyant charge en vert.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void Voyants::set_charge_vert()   
{
	
	io->led_charge=VERT;
}

/**
* Cette method sera utilisee pour clignoter le voyant charge ent vert pendant 8 s.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void Voyants::clignoter()        
{
	
	int i;
	for(i = 0; i < 8; ++i)	
	{
		
		
		io->led_charge=VERT;
		system("sleep 0.5");
		io->led_charge=OFF;
		system("sleep 0.5");
		
		
	}
}

/**
* Cette methode sera utilisee pour clignoter le voyant defaut ent vert pendant 8 s.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void Voyants::clign_def()      
{
	
	int i;
	
	for(i = 0; i < 8; ++i)	
	{
		
		
		io->led_defaut=ROUGE;
		system("sleep 0.5");
		io->led_defaut=OFF;
		system("sleep 0.5");
		
	}
}


/**
* Cette methode sera utilisee pour allumer le voyant charge en rouge.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void Voyants::set_charge_rouge()        
{
	
	io->led_charge=ROUGE;
		
}

/**
* Cette method sera utilisee pour allumer le voyant dispo en rouge.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void Voyants::set_dispo_rouge()     
{

	io->led_dispo=ROUGE;

}

/**
* Cette methode sera utilisee pour le voyant charge dispo en rouge.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void Voyants :: charge_disp_rouge()
{	
		io->led_dispo=ROUGE;
		
}

