#if !defined(__SONER_H)
#define __SONER_H

#include "const.h"
#include "Sone.h"
#include "funk.h"


class Soner {						   // Private data:
	private:
		int sisteOppdrag;			// Sist brukt oppdrags nr
		Sone* sonene[MAXSONE];		// aray med soner

	public:							   // Medlemsfunksjoner:
		Soner();
		~Soner();
		Sone* return_sone_nr(int nr);
		void skrivTilFil();
		void skrivTilEnFil(int i);
		bool finnesSone(int nr);
		void nyEiendom(int nr);
		void nySone(int nr);
		int display(char k);
		int display_more(char k);
		int kommando_e(char k);
		int kommando(char k);
		void endreEiendom();
		int getsisteOppdrag()			
		{return sisteOppdrag;}

		void finn_intereser(int opp_nr, int sone_nr);


		void slettEiendom();

		void nyEiendom_v() ;


		};

#endif

