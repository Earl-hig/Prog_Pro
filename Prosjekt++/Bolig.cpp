#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "Bolig.h"
#include "Eiendom.h"
#include "const.h"

Bolig::Bolig() {					   // Tom parameterløs constructor

}
									   // Constructor som leser inn fra bruker	
Bolig::Bolig(int type, int nr) : Eiendom(type, nr) {
	char valg;
									   // Leser inn relevant data:

	// leser inn inter
	bygar = les("\nByggeaar", 1900, 2014);
	bruar = les("\nBruttoareal", 10, 1000);
	boareal = les("\nBoareal", 10, bruar);
	antSov = les("\nAntall soverom", 1, 10);

	// leser inn salg_onske
	// looper til enten (S)alg, (L)eie eller (B)egge
		cout << "\nSalgstype ((S)alg, (L)eie, (B)egge: ";
		do { valg = les(); }
		while (!(valg == 'S') && !(valg == 'L') && !(valg == 'B'));

		
			switch (valg)
		{
				case 'S': salg_onske = Salg;
					break;

				case 'L': salg_onske = Leie;
					break;

				case 'B': salg_onske = Begge;
					break;
			
		}		
}

									   // Constructor som leser fra fil
Bolig::Bolig(ifstream & inn, int type, int i) :Eiendom(inn, type, i) {
	//cout << "\n\nNå er vi på bolig delen....";
	int enum_temp;

	// leser inn inter
	inn >> bygar >> bruar >> boareal >> antSov >> enum_temp;
	inn.ignore();

	// konverterer int til enum
	salg_onske = (salgstype)enum_temp;

	// Utskrift
	cout << "\n*** BOLIG  ***";
	cout << "\nByggareal: " << bygar << "\tBrutto areal: " 
		 << bruar << "\tBoareal: " << boareal
		 << "\nAnt soverom: " << antSov << "\tSalg oenske: " 
		 << salg_onske << endl;
}

Bolig::~Bolig() {

}



void Bolig::display() {				   // Displayer bolig objekter
	display_e();	//Eiendom:display();
	cout << "\n*** BOLIG  ***";
	cout << "\nByggareal: " << bygar << "\tBrutto areal: " << bruar 
		 << "\tBoareal: " << boareal
		 << "\nAnt soverom: " << antSov << "\tSalg oenske: " 
		 << salg_onske << endl;

}

void Bolig::skrivTilFil(ofstream & ut) { // Skriver bolig til fil
	
	// Kaller eiendom sin skriv til fil
	Eiendom::skrivTilFil(ut);

	// Skriver all eiendoms data til ut
	ut << bygar << "  " << bruar << "  " << boareal << "  " << antSov << '\n';
	ut << salg_onske << '\n';

}

// retunerer antall soverom
int Bolig::return_ant_sov() {return antSov;}

// retunerer bo areal
int Bolig::return_boareal() {return boareal;}

// retunerer salgs type
salgstype Bolig::return_salsg_type() {return salg_onske;}