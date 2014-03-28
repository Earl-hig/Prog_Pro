#include <iostream>
#include <cstring>
#include <fstream>

#include "Kunde.h"
#include "const.h"
#include "listtool2.h"

using namespace std;



Kunde::Kunde() {

}

Kunde::Kunde(int nr) : Num_element(nr) {

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

}