#include <iostream>

using namespace std;

#include "const.h"
#include "funk.h"
#include "Soner.h"
#include "Kunder.h"

Kunder kundebase;
Soner sonebase;



int main() {



	char kommando;

	skrivMeny();

	kommando = les();

	while (kommando != 'Q') {
		switch (kommando) {
		case 'E':   sonebase.kommando(kommando);
			break;
		case 'S':	sonebase.kommando(kommando);
			break;
		case 'K':	kundeHandling(kommando);
			break;
		case 'U':	ukentlig();
			break;
		default:	skrivMeny();
			break;
		}

		kommando = les();
	}

	return 0;

}