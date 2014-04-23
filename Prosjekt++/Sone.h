#if !defined(__SONE_H)
#define __SONE_H

#include <fstream>
#include <iostream>

#include "Eiendom.h"
#include "funk.h"
using namespace std;

class Sone {						   // Private data:
	private:
		char* beskrivelse;	// beskrivelse av sonen
		List* eiendom;		// liste med tomt / boliger

	public:							   // Medlemsfunksjoner:
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
		bool harOppdnr(int nr);
		void endreEiendom(int oppdnr);
		
};

#endif