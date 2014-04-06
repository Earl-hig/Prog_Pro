#if !defined(__SONE_H)
#define __SONE_H

#include <fstream>
#include <iostream>

#include "Eiendom.h"

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

		int kommando(char k);//bare tull?

};


#endif