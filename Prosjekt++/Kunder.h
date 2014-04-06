#if !defined(__KUNDER_H)
#define __KUNDER_H

#include "const.h"
#include "Kunde.h"
#include "listtool2.h"
#include "funk.h"


class Kunder {
	private:
		int forste, siste;
		List* kunde;

	public:
		Kunder();
		~Kunder();
		void add_kunde();
		void display_kunder();


		void kundeHandling(char k) 
		{
	     char kommando;
	     cout << "Kundebase";
	     kommando = les();

	
		switch (kommando) {
		case 'D': display_kunder();
			break;
		case 'N': add_kunde();
			break;
		case 'S':	
			break;
		case 'E':	
			break;
		default:
			break;
		}
		}
	

};

#endif


