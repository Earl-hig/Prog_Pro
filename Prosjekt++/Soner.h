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

		kommando = les();
	

	return 0;

};



};

#endif

