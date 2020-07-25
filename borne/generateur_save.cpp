/**
* @file generateur_save.cpp
* @brief Ce fichier contiendra les definition des methodes de la class GenerateurSave.
*
* @author Youssef Abbih
*
* @date 25/04/2020
*
**/

#include "generateur_save.h"


/**
* Constructeur GenerateurSave.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
GenerateurSave::GenerateurSave()
{
	io=acces_memoire(&shmid);
	Fin=1;
}

/**
* Cette methode sera utilisee pour genere un signal pwm.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void GenerateurSave::generer_PWM()
{
	io->gene_pwm=DC;	
}

/**
* Cette methode sera utilisee pour genere un signal pwmac.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void GenerateurSave::generer_PWMAC()
{
	io->gene_pwm=AC_1K;
}

/**
* Cette methode sera utilisee pour genere un signal pwmcl.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void GenerateurSave::generer_PWMCL()
{
	io->gene_pwm=AC_CL;
}

 
/**
* Cette methode sera utilisee pour charge la batterie du vehicule.
* @author Youssef Abbih
* @param void
* @return 1 or 0
* @date 25/04/2020
*/
int GenerateurSave::verfier_reprise()
{
    BaseClient baseclient ;

	if(carte_inseree()==0)

 		 return 0 ;

		 else if(carte_inseree())                                              
			    {	num = lecture_numero_carte();                              // recuperation du numero de la carte inseree
        			if(io->bouton_stop==1 && baseclient.reprise(num) == 1)     // appuie sur stop +  verification ----> reprise
					{   
				return 1;
			        }
                }		

}

/**
* Cette methode sera utilisee pour charge la batterie du vehicule.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void GenerateurSave::genSAVE_mef()
{

	BaseClient baseclient ;
	Prise prise;
	Voyants voyant ;

	etatMEF etatACTUEL=etatA;
	etatMEF etatSUIVANT=etatA;

cout <<"Veuillez insere votre carte pour prendre votre vehicule "<< endl ;

	while(Fin)
	{
		switch(etatACTUEL)
		{
			case etatA:
				if(io->gene_u==9)etatSUIVANT=etatB;
				break;
			
			case etatB:
				if(io->gene_u==6)etatSUIVANT=etatC;
		                
				if(GenerateurSave::verfier_reprise()==1)etatSUIVANT=etatE;

				
				break;

			case etatC:
				if(io->gene_u==6)etatSUIVANT=etatD;
					if(GenerateurSave::verfier_reprise()==1)etatSUIVANT=etatE;   
				break;
				
			case etatD:
				if(io->gene_u==9)etatSUIVANT=etatE;
				if(GenerateurSave::verfier_reprise()==1 ) etatSUIVANT=etatE;
			
				break;
			
			case etatE:
				if(io->gene_u==12)etatSUIVANT=etatF;
				break;
			case etatF:
				break;
		}
		
		etatACTUEL=etatSUIVANT;
	
		if(etatACTUEL==etatA)
		{	
			
			voyant.set_charge_rouge();
			
			prise.dev_trappe();
			
			generer_PWM();
			
			
			
			
		}
	
		if(etatACTUEL==etatB)
		{
			

			prise.ver_trappe();

			prise.set_prise();
			
			GenerateurSave::generer_PWMAC();
			

			
		}

		if(etatACTUEL==etatC)
		{
		
			fermer_AC();
			GenerateurSave::generer_PWMCL();
					
		}

		if(etatACTUEL==etatD)
		{
		}

		if(etatACTUEL==etatE)
		{
			
			GenerateurSave::ouvrir_AC();
			GenerateurSave::generer_PWM();
			voyant.set_charge_vert();
			attente_insertion_carte();
			carte_inseree();
			io->led_trappe=VERT;
			
			
		}
		if(etatACTUEL==etatF)
		{
			
			prise.ver_trappe();
			io->led_charge=OFF;
			io->gene_pwm=STOP;
			io->bouton_stop=0;
			io->led_dispo=VERT;
			io->led_prise=OFF;
			cout << "Retirer votre carte SVP" << endl ;
			attente_retrait_carte();
			Fin=0;
			

		}

	}
	cout << "Succes de charge" << endl ;
}

/**
* Cette methode sera utilisee pour renvoie la valeur de la tension genere.
* @author Youssef Abbih
* @param void
* @return DC
* @date 25/04/2020
*/
float GenerateurSave::tension()
{	
	return(io->gene_pwm=DC);
}

/**
* Cette methode deconnecte le vehicule.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void GenerateurSave::deconnecter()
{
		
}	

/**
* Cette methode sera utilisee pour ouvrir le contacteur AC.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void GenerateurSave::ouvrir_AC()
{
	io->contacteur_AC=0;	
}

/**
* Cette methode sera utilisee pour fermer le contacteur AC.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void GenerateurSave::fermer_AC()
{
	io->contacteur_AC=1;	
}

/**
* Cette methode sera utilisee pour eteindre les leds.
* @author Youssef Abbih
* @param void
* @return void
* @date 25/04/2020
*/
void GenerateurSave::init_led()
{	
	io->led_charge=OFF;
	io->led_prise=OFF;
	io->led_trappe=OFF;	
}



