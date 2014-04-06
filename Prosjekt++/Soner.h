#if !defined(__SONER_H)
#define __SONER_H

#include "const.h"
#include "Sone.h"
#include "funk.h"


class Soner {
	private:
		int sisteSone;
		Sone* soner[MAXSONE];

	public:
		Soner();
		~Soner();
		Sone* return_sone_nr(int nr);

		int display(char k)
		{
			int tmpint;
			tmpint=les("Velg sone:",1,MAXSONE-1);
			//for (int j=0; j<MAXSONE;j++)
			{
				if (soner[tmpint]==NULL)
				{
					cout << "Neinei, denne finnes ikke.";
				}
				else soner[tmpint]->display();
			}

			return 0;
		};

		int display_more(char k)
		{
			int tmpint;
			cout<<"Eiendom Display";
			tmpint=les("Velg sone:",1,MAXSONE-1);
			for (int j=0; j<MAXSONE;j++)
			{
				if (soner[j]==NULL)
				{
					//cout << "Neinei, denne finnes ikke.";
				}
				else soner[tmpint]->display();
				// her trengs en filterfunksjon som gjør
				// at kun visse oppdragsnr og postnr vises
			}

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

