/**
* @file timer.h
* @brief Ce fichier d'en-tete contiendra la class Timer.
* @author Youssef Abbih
* @date 25/04/2020
*/

#ifndef TIMER_H
#define TIMER_H
#include <lcarte.h>
#include "donnees_borne.h"
#include "donnees_borne.h"
#include "mem_sh.h"
#include "donnees.h"
#include "memoire_borne.h"
#include <iostream>

using namespace std;


  /*! \class Timer
   * \brief classe representant le temps.
   *
   *  La classe gere le temps
   */
class Timer
{
	private :
		entrees *io;
		int shmid;
		int depart_timer;
	public : 

        Timer();
		int timer_valeur();
		



};



#endif 
