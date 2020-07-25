/**
* @file timer.cpp
* @brief Ce fichier contiendra les definition des methodes de la class Timer.
*
* @author Youssef Abbih
*
* @date 25/04/2020
*
**/


#include <iostream>
#include <string>
#include <fstream>
#include "timer.h"


/**
* Cette method sera utilisee pour initialisation da la memoire partage et prend l'origine du temps l'instant actuelle et stocker le dans depart timer.
* @author Youssef Abbih
* @param none
* @return void
* @date 25/04/2020
*/
Timer:: Timer()
{
	io=acces_memoire(&shmid);           
	depart_timer=io->timer_sec;        

}

/**
* Cette method sera utilisee pour retourner le temps qui s'ecoule entre l'origine du temps et l'instant actuelle.
* @author Youssef Abbih
* @param void
* @return (timer_sec - depart_timer)
* @date 25/04/2020
*/
int Timer::timer_valeur()
{
	return(io->timer_sec - depart_timer);

}

