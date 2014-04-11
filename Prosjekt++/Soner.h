#if !defined(__SONER_H)
#define __SONER_H

#include "const.h"
#include "Sone.h"
#include "funk.h"


class Soner {
	private:
		int sisteOppdrag;				// Siste Oppdrag.
		Sone* sonene[MAXSONE];

	public:
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
		int getsisteOppdrag()			//Unødvendig siden sisteOppdrag ligger på denne fila
		{return sisteOppdrag;}

		void finn_intereser(int opp_nr, int sone_nr);


		void slettEiendom();

		void nyEiendom_v() ;


		};

#endif

