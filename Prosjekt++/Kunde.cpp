#include <iostream>
#include <cstring>
#include <fstream>

#include "Kunde.h"
#include "const.h"
#include "listtool2.h"
#include "funk.h"

using namespace std;



Kunde::Kunde() {

}

Kunde::Kunde(int nr) : Num_element(nr) {
	cout << "\n\nLager nå en kunde!!";
	IntrSone * intrsone_temp;
	int sone, max_pris, min_ar, ant, typ, valg, onsk;
	intrsone = new List (Sorted);


	telefon = les("\nSkriv inn telefon nr: ", 100000, 999999);
	les ("\nSkriv in navnnet: ", &navn, NVNLEN);
	les ("\nSkriv in epost adr: ", &mail, STRLEN);
	les ("\nSkriv in gate adressen din: ", &adresse, STRLEN);

	cout << "\nLeser nå inn info for intrsone";

	sone = les("\nSkriv inn sonen du er intresert i:", 1, 100);
	max_pris = les("\nskriv inn max pris", 1000000, 10000000);
	min_ar = les("\nSkriv inn min areal", 50, 200);
	ant = les("\nSkriv in antall soverom", 1, 10);
	typ = les("\nTomt = 0, Enenebolig = 1, Rekke hus = 2\
			  \nLelighet = 3, hytte = 4", 0, 4);
	valg = les("\nUkentlig = 0, Salgsoppgave = 1", 0, 1);
	onsk = les("\nSalg = 0, leie = 1, begge er = 2", 0, 2);

	do {
		if (intrsone ->in_list(sone)) {
			cout << "\nSone: " << sone << " finnes allerede.";
		}
		else {
		  intrsone_temp = new IntrSone(sone, max_pris, min_ar, ant, typ, valg, onsk);
		  intrsone -> add (intrsone_temp);
		}
		sone = les("\nSkriv inn sone nr 1-100 (0 for aa avslutte)", 0, 100);
	} while (sone != 0);
	// delete intrsone_temp;
}


Kunde::Kunde(ifstream & inn, int i) :Num_element(i) {
	int ant_int_sone;
	int sone_nr;
	char* buffer;
	buffer = new char[STRLEN+1];
	intrsone = new List(Sorted);

	cout << "\nleser en kunde fra fil";
	inn >> telefon;
	inn.ignore();

	inn.getline(buffer,STRLEN);
	navn = new char [strlen(buffer) + 1];
	strcpy (navn, buffer);

	inn.getline(buffer,STRLEN);
	adresse = new char [strlen(buffer) + 1];
	strcpy (adresse, buffer);

	inn.getline(buffer,STRLEN);
	mail = new char [strlen(buffer) + 1];
	strcpy (mail, buffer);

	inn >> ant_int_sone;

	for (int j = 1; j <= ant_int_sone; j++) {

		IntrSone * intrsone_tmp;

		inn >> sone_nr;

		intrsone_tmp = new IntrSone(inn, sone_nr);

		intrsone -> add(intrsone_tmp);

		cout << "\nLeser inn int_sone:" << j;
		// delete intrsone_tmp
	}

	cout << "\nNr: " << number << "\tTlf: " <<  telefon << "\tNavn: " << navn << "\tAdresse: " << adresse << "\nMail:" << mail << "\tAnt_soner: " << ant_int_sone;

}


Kunde::~Kunde() {
	
}

void Kunde::display() {
	cout << "Viser en kundepost:";

}