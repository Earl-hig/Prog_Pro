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
	//cout << "\nStarter med eiendoms biten....";
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

	display();
	delete []buffer;
	return;

	cout <<"MUHAHAHAH KJORES IKKE";
	

	
}

Eiendom::~Eiendom() {

}

void Eiendom::display() {//fordi denne kalles og overloades av samme funksjon
	display_e();
	return;
}

void Eiendom::display_e() {
	cout << "\n*** EIENDOM  ***";
	cout << "\nOpdragsnr: " << number << "\tBolig type: " << bolig_type << "\tDato_inn: " << datoInn
		 << "\nBruksnr: " << bruksnr << "\t saksbehandler: " << saksb << "\tPris: " << pris
		 << "\nAreal: " << tomta << "\tGate: " << gateadr << "\tPostadr: " << postadr
		 << "\nEier: " << eier << "\tKomune: " << kommune
		 << "\nBeskrivelse: " << beskrivelse;
}







