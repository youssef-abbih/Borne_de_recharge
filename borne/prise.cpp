/**
* @file prise.cpp
* @brief Ce fichier contiendra les definition des methodes de la class Prise.
*
* @author Youssef Abbih
*
* @date 25/04/2020
*
**/

#include "prise.h"


/**
* Cette method sera utilisee pour initialisr la memoir partage.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
Prise::Prise()
{
	
	io=acces_memoire(&shmid);  
	
}

/**
* Cette methode sera utilisee pour deverouiller la trape pour pour connecter ou deconncter la prise.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void Prise::dev_trappe()        
{
	io->led_trappe=VERT;
	
}

/**
* Cette methode sera utilisee pour verouiller la trape pour pour connecter ou deconncter la prise.
* @author Youssef Abbih
* @param void
* @date 25/04/2020
*/
void Prise::ver_trappe()     
{

	io->led_trappe=OFF;		
}

/**
* Cette methode sera utilisee pour allume le voyan prise en vert.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void Prise::set_prise()      
{

	io->led_prise=VERT;
	

}

