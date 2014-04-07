#if !defined(__SONER_H)
#define __SONER_H

#include "const.h"
#include "Sone.h"
#include "funk.h"


class Soner {
	private:
		int sisteOppdrag;
		Sone* sonene[MAXSONE];

	public:
		Soner();
		~Soner();
		Sone* return_sone_nr(int nr);
		void skrivTilFil();
		bool finnesSone(int nr);
		void nyEiendom(int nr);
		void nySone(int nr);
		int display(char k);
		int display_more(char k);
		int kommando_e(char k);
		int kommando(char k);
		};

#endif

