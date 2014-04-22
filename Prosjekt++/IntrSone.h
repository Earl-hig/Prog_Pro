#if !defined(__INTRSONE_H)
#define __INTRSONE_H

#include <iostream>
#include <fstream>

#include "listtool2.h"
#include "enum.h"

using namespace std;

class IntrSone : public Num_element {	// Private data:
	private:
		int maxpris, minareal, antSov;
		eiendomstype type;
		tilsending sending_valg;
		salgstype salg_onske;

	public:								// Medlemsfunksjoner:
		IntrSone();
		IntrSone(ifstream & inn, int i);
		IntrSone(int sone, int max, int min, int ant, int typ, 
				 int valg, int onsk);
		IntrSone(int n);
		~IntrSone();
		virtual void display();
		int samlign(Element* boligen);
		int return_nr();
		void skrivTilFil(ofstream & ut);
};

#endif
