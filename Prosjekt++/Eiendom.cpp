#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "Eiendom.h"
#include "const.h"
#include "funk.h"

Eiendom::Eiendom() {

}

Eiendom::Eiendom(int type, int nr) : Num_element(nr) {
	char buffer[NVNLEN];
	char besk[STRLEN];

	bolig_type = (eiendomstype)type;
	
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

int Eiendom::return_pris(){return pris;}

int Eiendom::return_tomt_areal(){return tomta;}

eiendomstype Eiendom::return_type(){return bolig_type;}

void Eiendom::skrivTilFil(ofstream & ut) {

	ut << bolig_type << '\n';
	ut << number << "  " << datoInn << "  " << bruksnr << "  " << saksb;
	ut << '\n' << pris << "  " << tomta << '\n';
	ut << gateadr << '\n';
	ut << postadr << '\n';
	ut << eier << '\n';
	ut << kommune << '\n';
	ut << beskrivelse << '\n';

}

bool Eiendom::harOppdnr(int nr){
	return (nr == number);
}