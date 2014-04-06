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

List* Sone::return_eindom_list() {
	return eiendom;
}