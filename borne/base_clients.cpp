/**
* @file base_clients.cpp
* @brief Ce fichier contiendra les definition des methodes de la class BaseClient.
*
* @author Youssef Abbih
*
* @date 25/04/2020
*
**/


#include "base_clients.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


/**
* constructeur BaseClient()
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
BaseClient :: BaseClient() 
{
		
}

/**
* cette methodes ouvre la base clients (fichier.txt), elle cherche si le
* numero de carte apparaient a cette base, si oui elle retourne 1 sin non elle retourne 0.
* @author Youssef Abbih
* @param void
* @return 1 or 0
* @date 25/04/2020
*/
int BaseClient :: authentifier(unsigned short int numero_carte)
{	
	aut=&auth ; 
	ifstream fichier("fichier.txt", ios::in);                        //on ouvre le ficher 
	if(fichier)                                                      // si le fichier est ouvert
	    	{
	    
		    while(getline(fichier, line)) 
		    { 
			++Nbr_clients; 
		    }  
		    
		   liste_clients = new  unsigned short int [Nbr_clients];   // on declare un tableaux  pour stocker le contenu de notre fichier   

		 
		    for(int i = 0; i < Nbr_clients; i++)   
		    { 
			liste_clients[i] = 0; 
		    }
			fichier.clear();  
		    fichier.seekg(0, ios::beg); 

		    
		    for(int i = 0; i < Nbr_clients ; i++) 
		    { 
		   	fichier >> liste_clients[i];
		    }
      
   
		    for(int i = 0; i < Nbr_clients ; i++)   
		    { 
					  
			    if(liste_clients[i] == numero_carte)
				{
                                auth=numero_carte;
				return 1 ; 
				}
		    }   
		fichier.close();
	
		for(int i = 0 ; i < Nbr_clients ; i++)   
	    	{   
	
			if(liste_clients[i]!= numero_carte)
			{
				cout << "client non autentifié" << endl ;
			return 0 ;    
			}
	    	} 
		fichier.close();      
	
    }
	 
else
cerr << "Impossible d'ouvrir ce fichier !" << endl;
return 0;
}


/**
* cette methode est utliser pour autoriser le stop, le client qui est deja autentifie est le seul qui peux stopper la charge et prendre sa voiture.
* @author Youssef Abbih
* @param void
* @return 1 or 0
* @date 25/04/2020
*/
int BaseClient :: reprise(int numero_reprise)      
{
		if(numero_reprise!=*aut)
   	{
         cout<< "ce n'est pas votre vehicule"<<endl;
  	     return 0;
    }
	else
	{
	return 1;
	}
}




