#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "Eiendom.h"
#include "const.h"
#include "funk.h"

Eiendom::Eiendom() {

}

Eiendom::Eiendom(ifstream & inn, int type, int i) :Num_element(i) {
	cout << "\nStarter med eiendoms biten....";
	bolig_type = (eiendomstype)type;
	char* buffer;
	buffer = new char[STRLEN+1];

	inn >> datoInn >> bruksnr >> saksb >> pris >> tomta;
	inn.ignore();

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


	cout << "\nOpdragsnr: " << number << "\tBolig type: " << bolig_type << "\tDato_inn: " << datoInn
		 << "\nBruksnr: " << bruksnr << "\t saksbehandler: " << saksb << "\tPris: " << pris
		 << "\nAreal: " << tomta << "\tGate: " << gateadr << "\tPostadr: " << postadr
		 << "\nEier: " << eier << "\tKomune: " << kommune
		 << "\nBeskrivelse: " << beskrivelse;

	delete []buffer;
}

Eiendom::~Eiendom() {

}

void Eiendom::display() {
	cout << "\nOpdragsnr: " << number << "\tBolig type: " << bolig_type << "\tDato_inn: " << datoInn
		 << "\nBruksnr: " << bruksnr << "\t saksbehandler: " << saksb << "\tPris: " << pris
		 << "\nAreal: " << tomta << "\tGate: " << gateadr << "\tPostadr: " << postadr
		 << "\nEier: " << eier << "\tKomune: " << kommune
		 << "\nBeskrivelse: " << beskrivelse;
}

void Eiendom::display_eiendommer () {
	char tmpstr[STRLEN+1];
	int tmpint;
	
	cout << "\n*** Viser eiendommer ***";
	//les("\nSkriv inn ett ordrenummer eller postnummer:",tmpstr,STRLEN);
	//tmpint=atoi(tmpstr);
	tmpint=les("\nSkriv inn ett ordrenummer eller postnummer:",1,9999);
	if (tmpint<1000) cout <<"Søker på ordrenummer "<<tmpint;
	else cout<<"Søker på postnummer "<<tmpint;
}

