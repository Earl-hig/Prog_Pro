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


		int display(char k)
		{
			int tmpint;
			tmpint=les("Velg sone:",1,MAXSONE-1);
			//for (int j=0; j<MAXSONE;j++)
			{
				if (sonene[tmpint]==NULL)
				{
					cout << "Neinei, denne finnes ikke.";
				}
				else sonene[tmpint]->display();
			}

			return 0;
		};

		int display_more(char k)
		{

			int tmpint,postnr;
			bool ok=false;
			cout<<"Eiendom Display";
			//tmpint=les("Velg sone:",1,MAXSONE-1);

						
		    postnr=les("Postnr eller oppdragsnr:",1000,999999);


			for (int j=0; j<MAXSONE;j++)
			{
				if (sonene[j]==NULL)
				{
					//cout << "Neinei, denne finnes ikke.";
				}
				else 
				{
					//cout << "Display some";
					sonene[j]->display_some(postnr);
					ok=true;
				}
				
				// her trengs en filterfunksjon som gjør
				// at kun visse oppdragsnr og postnr vises
			}
			if (!ok) cout << "\nSoeket fant ingen poster.";
			return 0;
		};

	int kommando_e(char k)
		{
	char kommando;

	cout << "\nSonebase - Eiendom";
	kommando = les();

	
		switch (kommando) {
		case 'D':   display_more(kommando);
			break;
		case 'S':	;
			break;
		case 'K':	;
			break;
		case 'U':	;
			break;
		default:	;
			break;
		}

	
	

	return 0;

};

		int kommando(char k)
		{
	char kommando;

	cout << "\nSonebase";
	kommando = les();

	
		switch (kommando) {
		case 'D':   display(kommando);
			break;
		case 'S':	;
			break;
		case 'K':	;
			break;
		case 'U':	;
			break;
		default:	;
			break;
		}

	
	

	return 0;

};


};

#endif

