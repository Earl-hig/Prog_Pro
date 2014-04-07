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
		void nyEiendom_v() 
		{
			int nr;
			nr=les("Velg sone:",1,100);
 	      if (finnesSone(nr))
		  {
		   nyEiendom(nr);
	      }
	else 
	{
		nySone(nr);
		nyEiendom(nr);
	}
}


		};

#endif

