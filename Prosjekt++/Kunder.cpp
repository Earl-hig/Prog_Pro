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
	kunde_temp -> finn_interesser();
	kunde -> add(kunde_temp);	
	// delete kunde_temp;
}

void Kunder::display_kunder () 
{
	char tmpstr[STRLEN+1];
	int tmpint;
	Kunde * kunde_temp;
	cout << "\n*** Viser kunder ***";
	//tmpint=les("\nSkriv inn ett kundenr:",1,9999);
	les("\nSkriv inn kundenr eller navn",tmpstr,STRLEN);
	tmpint=postadresse2int(tmpstr);
	//bruker funksjonen for å trekke nr ut av adresse
	if (tmpint) 
		{cout <<"\nSoeker paa kundernr."<<tmpint;
			kunde->display_element(tmpint);
	}

	else 
	{
		cout <<"Du skrev et navn luring.";
	}

	
}
