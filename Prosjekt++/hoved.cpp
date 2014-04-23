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
		case 'E':   sonebase.kommando_e(kommando);		// eindom
			break;
		case 'S':	sonebase.kommando(kommando);		// sone
			break;
		case 'K':	kundebase.kundeHandling(kommando);	// kunde
			break;
		case 'U':	ukentlig();							// ukentlig utskrift
			break;
		default:	skrivMeny();						// skriver meny
			break;
		}

		kommando = les();
	}

	skrivTilFil();					   // Skriver til fil

	return 0;

}