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
		void skrivTilEnFil(int i);
		bool finnesSone(int nr);
		void nyEiendom(int nr);
		void nySone(int nr);
		int display(char k);
		int display_more(char k);
		int kommando_e(char k);
		int kommando(char k);



		void slettEiendom()
		{
			
			int tmpint;
			tmpint=les("Velg oppdragsnummer:",10000,999999);
			for (int j=0; j<MAXSONE;j++)
			{
				if (sonene[j]==NULL)
				{
					//cout << "Neinei, denne finnes ikke.";
				}
				else 
					if (sonene[j]->slett(tmpint))skrivTilEnFil(j);




			}

			skrivTilFil();
			// skriver alle soner til fil, mulig det er litt overkill;
			
		
		};

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

