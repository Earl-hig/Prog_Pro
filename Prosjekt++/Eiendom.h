#if !defined(__EIENDOM_H)
#define __EIENDOM_H

#include "listtool2.h"
#include "enum.h"
#include "funk.h"

#include <iostream>
#include <fstream>
#include <cstring>

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
		void display_e();
		int getpnr()
		{
			return postadresse2int(postadr);}
			//return atoi(postadr[0])*1000+atoi(postadr[1])*100+atoi(postadr[2])*10+atoi[postadr[3];}


		int return_dato();
		int return_bruksnr();
		int return_saksb();
		int return_pris();
		int return_tomt_areal();
		eiendomstype return_type();

};

#endif

