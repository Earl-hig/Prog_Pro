#if !defined(__EIENDOM_H)
#define __EIENDOM_H

#include "listtool2.h"
#include "enum.h"

class Eiendom : public Num_element {
	private:
		int datoInn, bruksnr, saksb, pris, tomta;
		char* gateadr, * postadr, * eier, * kommune, * beskrivelse;
		eiendomstype bolig_type;

	public:
		Eiendom();
		Eiendom(ifstream & inn, int type, int i);
		Eiendom(int n); // : Num_element(n); trengs ikke i deklarasjonen men bare i definasjonen
		~Eiendom();
		virtual void display();
		void display_eiendommer ();

};

#endif

