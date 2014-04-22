#if !defined(__KUNDER_H)
#define __KUNDER_H

#include "const.h"
#include "Kunde.h"
#include "listtool2.h"
#include "funk.h"
#include "Eiendom.h"


class Kunder {						   // Private data:
	private:
		int forste, siste;
		List* kunde;

	public:							   // Medlemsfunksjoner:
		Kunder();
		~Kunder();
		void add_kunde();
		void display_kunder();
		void skrivTilFil();
		void kundeHandling(char k);
		void finn_interesser_for_eindom(Eiendom* eindomen, int sone_nr);
		void finn_ukentlig_interessee();
		void slett_kunde();
		void endreKunde();
};

#endif


