#include <iostream>

using namespace std;

#include "const.h"
#include "funk.h"
#include "Soner.h"
#include "Kunder.h"

Kunder kundebase;					   // "Containerobjekter"
Soner sonebase;



int main() {



	char kommando;					   

	skrivMeny();					   // Menyvalg

	kommando = les();				   // Leser brukerens valg

	while (kommando != 'Q') {		   // Avslutter med 'Q'
		switch (kommando) {
		case 'E':   sonebase.kommando_e(kommando);
			break;
		case 'S':	sonebase.kommando(kommando);
			break;
		case 'K':	kundebase.kundeHandling(kommando);
			break;
		case 'U':	ukentlig();
			break;
		default:	skrivMeny();
			break;
		}

		kommando = les();
	}

	skrivTilFil();					   // Skriver til fil

	return 0;

}