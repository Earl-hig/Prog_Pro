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
	bygar = les("\nByggeaar", 1900, 2014);
	bruar = les("\nBruttoareal", 10, 1000);
	boareal = les("\nBoareal", 10, bruar);
	antSov = les("\nAntall soverom", 1, 10);


		cout << "\nSalgstype ((S)alg, (L)eie, (B)egge: ";
		do valg = les();
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
	inn >> bygar >> bruar >> boareal >> antSov >> enum_temp;
	inn.ignore();

	salg_onske = (salgstype)enum_temp;
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
	
	Eiendom::skrivTilFil(ut);		   // Kaller eiendom sin skriv til fil
	ut << bygar << "  " << bruar << "  " << boareal << "  " << antSov << '\n';
	ut << salg_onske << '\n';

}

int Bolig::return_ant_sov() {return antSov;}

int Bolig::return_boareal() {return boareal;}

salgstype Bolig::return_salsg_type() {return salg_onske;}