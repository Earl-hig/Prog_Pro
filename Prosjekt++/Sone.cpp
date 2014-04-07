#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "Sone.h"
#include "const.h"
#include "listtool2.h"
#include "Eiendom.h"
#include "Bolig.h"
#include "funk.h"


Sone::Sone() {

}

Sone::Sone(ifstream & inn) {
	cout << "\nLeser sone fra fil...";
	eiendom = new List(Sorted);
	int opdrags_nr, ant_eiend, type_eind;
	char* buffer;
	buffer = new char[STRLEN+1];

	inn.getline(buffer, STRLEN);
	beskrivelse = new char [strlen(buffer)+1];
	strcpy(beskrivelse, buffer);

	cout << "\nBeskrivelse: " << beskrivelse;

	inn >> ant_eiend;

	for (int i = 1; i <= ant_eiend; i++) {
		cout << "\nLeser inn eiendom nr: " << i;
		inn >> type_eind >> opdrags_nr;

		if (type_eind) {
			cout << "\n\nbolig\n\n";
			Bolig * bolig_temp;
			bolig_temp = new Bolig(inn, type_eind, opdrags_nr);
			eiendom -> add(bolig_temp);
			// delete bolig_temp;

		}

		else {
			cout << "\n\nTomt\n\n";
			Eiendom * eindom_temp;
			eindom_temp = new Eiendom(inn, type_eind, opdrags_nr);
			eiendom -> add (eindom_temp);
			// delete eindom_temp;
		}
	}
	delete []buffer;
}



Sone::~Sone() {

}

void Sone::skrivTilFil(ofstream & ut) {
	int i, ant = eiendom->no_of_elements();
	Eiendom* enptr;
	Bolig* boptr;


	ut << beskrivelse << '\n';
	ut << ant << '\n';

	for (i = 1; i <= ant; i++) {
		if (enptr = (Eiendom*)eiendom->remove_no(i)) {
			enptr->skrivTilFil(ut);
			eiendom->add(enptr);
		}
		else {
			boptr = (Bolig*)eiendom->remove_no(i);
			boptr->skrivTilFil(ut);
			eiendom->add(boptr);
		}
	}
}

void Sone::nyEiendom(int oppdnr) {
	char valg;

	do {
		cout << "\nEiendomstype ((T)omt, (E)nebolig, (R)ekkehus, (L)eilighet,"
			<< "(H)ytte: \n";
		valg = les();

		if (valg == 'T')
			eiendom->add(new Eiendom(0, oppdnr));

		else if (valg == 'E')
			eiendom->add(new Bolig(1, oppdnr));

		else if (valg == 'R')
			eiendom->add(new Bolig(2, oppdnr));

		else if (valg == 'L')
			eiendom->add(new Bolig(3, oppdnr));

		else if (valg == 'H')
			eiendom->add(new Bolig(4, oppdnr));

	} while (valg != 'T' || valg != 'E' || valg != 'R' || valg != 'L' ||
			 valg != 'H');
	
}


void Sone::nySone() {
	char buffer[STRLEN];

	les("\nBeskrivelse av sonen", buffer, STRLEN);
	beskrivelse = new char[strlen(buffer) + 1];
	strcpy(beskrivelse, buffer);

	eiendom = new List(Sorted);

}


List* Sone::return_eindom_list() {
	return eiendom;
}