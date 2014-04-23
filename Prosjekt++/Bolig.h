#if !defined(__BOLIG_H)
#define __BOLIG_H

#include <iostream>
#include <fstream>

#include "enum.h"
#include "Eiendom.h"
#include "listtool2.h"


class Bolig : public Eiendom {			// Private data:
	private:
		int bygar;				// byge år
		int bruar;				// bruks areal
		int boareal;			// bo areal
		int antSov;				// antall sove rom
		salgstype salg_onske;	// leie - salg - begge

	public:								// Medlemsfunksjoner:
		Bolig();
		Bolig(int type, int nr);
		Bolig(ifstream & inn, int type, int i);
		~Bolig();
		virtual void display();
		salgstype return_salsg_type();
		int return_ant_sov();
		int return_boareal();
		void skrivTilFil(ofstream & ut);
};

#endif
