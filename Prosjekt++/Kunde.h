#if !defined(__KUNDE_H)
#define __KUNDE_H

#include <iostream>
#include <fstream>

#include "const.h"
#include "IntrSone.h"
#include "listtool2.h"
#include "Eiendom.h"

using namespace std;

class Kunde : public Num_element {
	private:
		int telefon;
		char* navn, * gate,* adresse, * mail;
		List* intrsone;
	
	public:
		Kunde();					   // Constructor
		Kunde(ifstream & inn, int i);  // fra fil
		~Kunde();					   // Destructor
		Kunde(int nr); //: Num_element(nr); trengs ikke i deklarasjonen men bare i definisjonen
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
