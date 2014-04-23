#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "Eiendom.h"
#include "const.h"
#include "funk.h"

Eiendom::Eiendom() {

}
									   // Constructor som leser fra bruker:
Eiendom::Eiendom(int type, int nr) : Num_element(nr) {
	char buffer[NVNLEN];	// hjelpe variabler
	char besk[STRLEN];

	bolig_type = (eiendomstype)type;	// setter bolig typen
	
	// lesser inn resten av variablene fra brukeren

	les("\nGateadresse", buffer, NVNLEN);
	gateadr = new char[strlen(buffer) + 1];
	strcpy(gateadr, buffer);

	les("\nPostadresse", buffer, NVNLEN);
	postadr = new char[strlen(buffer) + 1];
	strcpy(postadr, buffer);

	datoInn = les("\nDato innlagt(aaaammdd)", 20100101, 20141231);
	bruksnr = les("\nBruksnummer", 1000, 9999);
	pris = les("\nPris", 500000, 10000000);
	tomta = les("\nTomt areal", 10, 10000);
	saksb = les("\nSaksbehandler", 1, 999);

	les("\nEier", buffer, NVNLEN);
	eier = new char[strlen(buffer) + 1];
	strcpy(eier, buffer);

	les("\nKommune", buffer, NVNLEN);
	kommune = new char[strlen(buffer) + 1];
	strcpy(kommune, buffer);

	les("\nBeskrivelse av eiendommen", besk, STRLEN);
	beskrivelse = new char[strlen(besk) + 1];
	strcpy(beskrivelse, besk);
}

									   // Constructor som leser fra fil:
									   // i = oppdrag nr, type = bolig_type
Eiendom::Eiendom(ifstream & inn, int type, int i) :Num_element(i) {
	//cout << "\nStarter med eiendoms biten....";
	bolig_type = (eiendomstype)type;	// setter bolig typen
	char* buffer;						// buffer
	buffer = new char[STRLEN+1];

	// leser inn inter

	inn >> datoInn >> bruksnr >> saksb >> pris >> tomta;
	inn.ignore();

	// lesser inn char pekere med hjelp av buffer

	inn.getline(buffer, STRLEN);
	gateadr = new char [strlen(buffer)+1];
	strcpy(gateadr, buffer);

	inn.getline(buffer, STRLEN);
	postadr = new char [strlen(buffer)+1];
	strcpy(postadr, buffer);

	inn.getline(buffer, STRLEN);
	eier = new char [strlen(buffer)+1];
	strcpy(eier, buffer);

	inn.getline(buffer, STRLEN);
	kommune = new char [strlen(buffer)+1];
	strcpy(kommune, buffer);

	inn.getline(buffer, STRLEN);
	beskrivelse = new char [strlen(buffer)+1];
	strcpy(beskrivelse, buffer);

	display();
	delete []buffer; // sletter bufferet
	return;	
}

Eiendom::~Eiendom() {

}

void Eiendom::display() {//fordi denne kalles og overloades av samme funksjon
	display_e();
	return;
}

void Eiendom::display_e() {		// skriver ut eindom info
	cout << "\n*** EIENDOM  ***";
	cout << "\nOpdragsnr: " << number << "\tBolig type: " << bolig_type << "\tDato_inn: " << datoInn
		 << "\nBruksnr: " << bruksnr << "\t saksbehandler: " << saksb << "\tPris: " << pris
		 << "\nAreal: " << tomta << "\tGate: " << gateadr << "\tPostadr: " << postadr
		 << "\nEier: " << eier << "\tKomune: " << kommune
		 << "\nBeskrivelse: " << beskrivelse;
}

// retunerer pris
int Eiendom::return_pris(){return pris;}

// retunerer tamt areal
int Eiendom::return_tomt_areal(){return tomta;}

// retunerer oppdrags nr
int Eiendom::return_opdrag_nr() {return number;}

// retunerer bolig typen
eiendomstype Eiendom::return_type(){return bolig_type;}

void Eiendom::skrivTilFil(ofstream & ut) {

	// Skriver all data til ut

	ut << bolig_type << '\n';
	ut << number << "  " << datoInn << "  " << bruksnr << "  " << saksb;
	ut << '\n' << pris << "  " << tomta << '\n';
	ut << gateadr << '\n';
	ut << postadr << '\n';
	ut << eier << '\n';
	ut << kommune << '\n';
	ut << beskrivelse << '\n';
}

bool Eiendom::harOppdnr(int nr){	   // Returnerer oppragsnummeret
	return (nr == number);
}