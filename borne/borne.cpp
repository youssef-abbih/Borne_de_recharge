
/**
* @file borne.cpp
* @brief fichier principale contenant la fonction main.
*
* @author Youssef Abbih
*
* @date 25/04/2020
*
**/
#include "lecteurcarte.h"

using namespace std;


/**
* @brief fonction main.
* @author Youssef Abbih
* @param void
* @return 0
* @date 25/04/2020
*/
int main()
{
	LecteurCarte lecteurcarte;
    while (1)
    {
	    lecteurcarte.initialiser();
	    lecteurcarte.lire_carte();
    }
    return 0;
}
