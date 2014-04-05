#include <iostream>
#include <fstream>
#include <cstring>

#include "Kunder.h"
#include "const.h"
#include "funk.h"
#include "listtool2.h"

using namespace std;






Kunder::Kunder() {

	char * kxx;
	kxx = new char[STRLEN];
	strcpy (kxx, "K0000000.DTA");
	kunde = new List(Sorted);

	cout << "\nHei jeg er kunder";

	cout << "\nLeser fra " << siste_dta;
	ifstream inn_siste("SISTE.DTA");
	inn_siste >> forste >> forste >> siste;

	cout << "\nForste er: " << forste << "\nSiste er: " << siste;

	for (int i = forste; i <= siste; i++) {
		cout << "\nPrøver å lese kunde nr: " << i;
		lag_navn(kxx, i ,1, 4);
		cout << '\n' << kxx;

		ifstream inn_data(kxx);

		if (!inn_data) {
			cout << "\nTrue";
		}

		else {
			
			Kunde * kunde_temp;

			kunde_temp = new Kunde(inn_data, i);

			kunde -> add(kunde_temp);

			// delete kunde_temp;
		}
	}
	delete []kxx;
}

Kunder::~Kunder() {

}

void Kunder::add_kunde () {
	Kunde * kunde_temp;
	kunde_temp = new Kunde(++siste);
	kunde -> add(kunde_temp);
	// delete kunde_temp;
}
