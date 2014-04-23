#if !defined(__EIENDOM_H)
#define __EIENDOM_H

#include "listtool2.h"
#include "enum.h"
#include "funk.h"

#include <iostream>
#include <fstream>
#include <cstring>

class Eiendom : public Num_element {	// Private data:
	private:
		// num_ element -> number	// Oppdrags number
		int datoInn;				// dato lagt til
		int bruksnr;				// komunens bruks nr
		int saksb;					// Nr på saksbehandler
		int pris;					// pris for tomt / boligen
		int tomta;					// tomt areal
		char* gateadr;				// (gate + nr)
		char* postadr;				// (nr + poststed)
		char* eier;					// Hvem eier tomt / boligen
		char* kommune;				// hvilken kommune den liger i
		char* beskrivelse;			// beskrivelse av eindom
		eiendomstype bolig_type;	// Hva slags bolig

	public:								// Medlemsfunksjoner
		Eiendom();
		Eiendom(int type, int nr);
		Eiendom(ifstream & inn, int type, int i);
		Eiendom(int n); 
		~Eiendom();
		virtual void skrivTilFil(ofstream & ut);
		virtual void display();
		void display_e();
		bool harOppdnr(int nr);
		int getpnr()
		{return postadresse2int(postadr);}
		int getordrenr()	
		{return 0;}

		int return_opdrag_nr();
		int return_dato();
		int return_bruksnr();
		int return_saksb();
		int return_pris();
		int return_tomt_areal();
		eiendomstype return_type();

};

#endif