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

		int display_ordrenr(int ordrenr)//ikke i bruk
		{int tmpint;
		  
		   Eiendom * tmpeiendom;
		    
			tmpint=eiendom->no_of_elements();

			for (int j=1;j<=tmpint;j++)
			{
				eiendom->display_element(ordrenr);
			//tmpeiendom=(Eiendom*)eiendom->remove_no(j);
			//if (tmpeiendom->getordrenr()==ordrenr) tmpeiendom->display();
			//eiendom->add(tmpeiendom);
			}
			return 0;
		}

		int display_some(int postnr)
		{int tmpint;

		  
		   Eiendom * tmpeiendom;
		
		    
			tmpint=eiendom->no_of_elements();
			cout <<"Valgt sone har "<<tmpint<<" elementer";
			

			for (int j=1;j<=tmpint;j++)
			{
				if (postnr>9999)
				{
					eiendom->display_element(postnr);
				}
				else
				{
			tmpeiendom=(Eiendom*)eiendom->remove_no(j);
			if (tmpeiendom->getpnr()==postnr) tmpeiendom->display();
			eiendom->add(tmpeiendom);
				}
			}
			return 0;
		}


		int kommando(char k);//bare tull?

};


#endif