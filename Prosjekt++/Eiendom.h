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
		int datoInn, bruksnr, saksb, pris, tomta;
		char* gateadr, * postadr, * eier, * kommune, * beskrivelse;
		eiendomstype bolig_type;

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