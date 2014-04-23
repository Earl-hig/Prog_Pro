#if !defined(__KUNDE_H)
#define __KUNDE_H

#include <iostream>
#include <fstream>

#include "const.h"
#include "IntrSone.h"
#include "listtool2.h"
#include "Eiendom.h"

using namespace std;

class Kunde : public Num_element {		// Private data:
	private:
		// num_ element -> number	// kunde nr
		int telefon;				// telefon nr
		char* navn;					// navn på kunden
		char* gate;					// gate adr
		char* adresse;				// post adr
		char* mail;					// email adr
		List* intrsone;				// liste med interesser
	
	public:							   // Medlemsfunksjoner:
		Kunde();					   // Constructor
		Kunde(ifstream & inn, int i);  // fra fil
		~Kunde();					   // Destructor
		Kunde(int nr);
		void display();
		void finn_interesser();
		void finn_ukentlig_intersser();
		char* get_navn()
		{return navn;}
		int get_number()
		{return number;}
		void skrivTilFil();
		void slettFil();
		void skriv_til_e_dta(int opp_nr);
		void er_intresert_eindom(Eiendom* eiendomen, int sone_nr);
		void endreIntrsone();
};

#endif
