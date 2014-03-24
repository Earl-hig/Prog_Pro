#if !defined(__KUNDE_H)
#define __KUNDE_H

#include "const.h"
#include "IntrSone.h"
#include "listtool2.h"

class Kunde : public Num_element {
	private:
		int telefon;
		char* navn, adresse, mail;
		IntrSone* intrsone;
	
	public:
		Kunde();					   // Constructor
		~Kunde();					   // Destructor
		Kunde(int nr); //: Num_element(nr); trengs ikke i deklarasjonen men bare i definasjonen
		void display();

};

#endif
