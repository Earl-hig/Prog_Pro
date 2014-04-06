#if !defined(__SONE_H)
#define __SONE_H

#include <fstream>
#include <iostream>

#include "Eiendom.h"
#include "funk.h"
using namespace std;

class Sone {
	private:
		char* beskrivelse;
		List* eiendom;

	public:
		Sone();
		Sone(ifstream & inn);
		~Sone();
		List* return_eindom_list();
		int display()
		{
			cout <<"Viser sone:";
			eiendom->display_list();
			
			return 0;
		}

		int display_some(int postnr)
		{int tmpint;

		  
		   Eiendom * tmpeiendom;
			//cout <<"\nViser utvalgt sone:";
		    
			tmpint=eiendom->no_of_elements();
			//cout <<"Valgt sone har "<<tmpint<<" elementer";
			//cout <<"Viser element";

			for (int j=1;j<=tmpint;j++)
			{
			tmpeiendom=(Eiendom*)eiendom->remove_no(j);
			if (tmpeiendom->getpnr()==postnr) tmpeiendom->display();
			eiendom->add(tmpeiendom);
			}
			return 0;
		}


		int kommando(char k);//bare tull?

};


#endif