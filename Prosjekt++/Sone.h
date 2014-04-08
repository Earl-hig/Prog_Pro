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
		void skrivTilFil(ofstream & ut);
		void nyEiendom(int oppdnr);
		void nySone();
		List* return_eindom_list();
		int display();
		int display_some(int postnr);
		int slett(int oppdragsnr);
		
};

#endif