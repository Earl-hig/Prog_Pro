#if !defined(__KUNDE_H)
#define __KUNDE_H

#include <iostream>
#include <fstream>

#include "const.h"
#include "IntrSone.h"
#include "listtool2.h"

using namespace std;

class Kunde : public Num_element {
	private:
		int telefon;
		char* navn, * adresse, * mail;
		List* intrsone;
	
	public:
		Kunde();					   // Constructor
		Kunde(ifstream & inn, int i);  // fra fil
		~Kunde();					   // Destructor
		Kunde(int nr); //: Num_element(nr); trengs ikke i deklarasjonen men bare i definisjonen
		void display();
		void finn_interesser();

};

#endif
