#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "Soner.h"
#include "const.h"
#include "funk.h"
#include "Sone.h"


Soner::Soner() {
	cout << "\nHei jeg er soner";

	char * sonexx;
	sonexx = new char[STRLEN];
	strcpy (sonexx, "sone000.DTA");

	cout << "\nLeser fra " << siste_dta;
	ifstream inn_siste("SISTE.DTA");
	inn_siste >> sisteOppdrag;

	for (int i = 1; i < MAXSONE; i ++) {
		
		lag_navn(sonexx, i,1, 4);

		cout << "\nFilnavn: " << sonexx;

		ifstream inn_data(sonexx);

		if (!inn_data){
			cout << "\tFant ikke";
			sonene[i] = NULL;
		}

		else {
			cout << "\tÅpner opp....";
			sonene[i] = new Sone(inn_data);

		}

	}
	delete []sonexx;
}

Soner::~Soner() {

}

Sone* Soner::return_sone_nr(int nr) {
	if (nr < 1 || 100 < nr) {
		return NULL;
	}

	Sone* return_ptr = sonene[nr];

	return return_ptr;
}

void Soner::skrivTilFil() {
	char* filnavn;

	filnavn = new char[NVNLEN / 2];
	strcpy(filnavn, "SONE000.DT2");

	ofstream utfil1("SISTE.DT2");

	utfil1 << sisteOppdrag << '\n';

	for (int i = 1; i <= MAXSONE; i++) {
		if (sonene[i] != 0) {
			lag_navn(filnavn, i, 4);
			ofstream utfil2(filnavn);
			
			sonene[i]->skrivTilFil(utfil2);
		}
		else cout << "\nIngen soner registrert!";
	}
}

bool Soner::finnesSone(int nr) {
	if (sonene[nr])
		return true;
	else
		return false;
}


void Soner::nyEiendom(int nr) {
	sisteOppdrag++;
	sonene[nr]->nyEiendom(sisteOppdrag);
}

void Soner::nySone(int nr) {
	sonene[nr]->nySone();
}