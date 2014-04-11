#include <iostream>
#include <cstring>
#include <fstream>

#include "Kunde.h"
#include "const.h"
#include "listtool2.h"
#include "funk.h"
#include "extern.h"
#include "Sone.h"
#include "Eiendom.h"
#include "stdio.h"

using namespace std;



Kunde::Kunde() {

}

Kunde::Kunde(int nr) : Num_element(nr) {
	cout << "\n\nLager nå en kunde!!";
	IntrSone * intrsone_temp;
	int sone, max_pris, min_ar, ant, typ, valg, onsk;
	intrsone = new List (Sorted);


	telefon = les("\nSkriv inn telefon nr: ", 10000000, 99999999);
	les ("\nSkriv inn navnnet: ", &navn, NVNLEN);
	les ("\nSkriv inn epost adr: ", &mail, STRLEN);
	les ("\nSkriv inn gate adressen din: ", &gate, STRLEN);
	les ("\nSkriv inn postnr/sted", &adresse, STRLEN);

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
	gate = new char [strlen(buffer) + 1];
	strcpy (gate, buffer);

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
	cout << "\nNr: " << number << "\tTlf: " <<  telefon << "\tNavn: " << navn << "\nGate:"<<gate
		<<"\tAdresse: " << adresse << "\nMail:" << mail << "\tAnt_soner: " << ant_int_sone;
}


Kunde::~Kunde() {
	delete []navn;
	delete []gate;
	delete []adresse;
	delete []mail;
	delete intrsone;
}

void Kunde::display() {
	cout << "Viser en kundepost:";
		cout << "\nNr: " << number << "\tTlf: " <<  telefon << "\tNavn: " << navn << "\nGate:"<<gate
		<<"\tAdresse: " << adresse << "\nMail:" << mail ;
		cout << "\nAntall interesser:" << intrsone->no_of_elements();
		intrsone->display_list();

}

void Kunde::finn_interesser() {
	cout << "\n\nNaa begyner vi aa lette etter det du er intresert i!";

	IntrSone* intresert_temp;
	Sone* sone_temp;
	List* eindoms_liste = new List(Sorted);
	Element* til_samenlign;

	for (int i = 1; i <= intrsone -> no_of_elements(); i++) {
		intresert_temp = (IntrSone*)intrsone -> remove_no(i);

		cout << "\nSone nr: " << intresert_temp -> return_nr();

		sone_temp = sonebase.return_sone_nr(intresert_temp -> return_nr());

		if (sone_temp) {
			cout << '\t' << '\'' << "aapner sonen" << '\'';
			eindoms_liste = sone_temp -> return_eindom_list();
			cout << '\n' << eindoms_liste -> no_of_elements() << " eindomer vi skal se paa...";

			for (int j = 1; j <= eindoms_liste -> no_of_elements(); j++) {
				til_samenlign = eindoms_liste -> remove_no(j);

				if ((intresert_temp -> samlign(til_samenlign)) == 2) {
					cout << "\nSkal skrive interesen til fil kommer senere";
					/*
					Skriving til spesefik fil kommer senere

					//*/
				}

				else {
					cout << "\nInteresen matchet ikke";
				}

				eindoms_liste -> add(til_samenlign);
			}
		}

		else {
			cout << "\tSonen finnes ikke enda...";
		}
		
		intrsone -> add(intresert_temp);
	}
	// delete intresert_temp;
	// delete eindoms_liste;
}

void Kunde::skrivTilFil() {
	int i, antint = intrsone->no_of_elements();
	IntrSone* is;
	char* filnavn;

	filnavn = new char[NVNLEN / 2];
	strcpy(filnavn, "K0000000.DT2");

	lag_navn(filnavn, number,1, 4);

	ofstream utfil(filnavn);

	utfil << telefon << '\n';
	utfil << navn << '\n';
	utfil << gate << '\n';
	utfil << adresse << '\n';
	utfil << mail << '\n';
	utfil << antint << '\n';

	cout << "\n\nSKRIVER KUNDE:" << number << " TIL FIL.";

	for (i = 1; i <= antint; i++) {
		is = (IntrSone*)intrsone->remove_no(i);
		is->skrivTilFil(utfil);
		intrsone->add(is);
	}
}

void Kunde::slettFil() {
	//int i, antint = intrsone->no_of_elements();
	//IntrSone* is;
	char* filnavn;

	filnavn = new char[NVNLEN / 2];
	strcpy(filnavn, "K0000000.DT2");

	lag_navn(filnavn, number,1, 4);

	//fstream utfil(filnavn);
	remove(filnavn);

	cout << "\n\nSLETTER KUNDE NR." << number << " FRA FIL.";

	
}

void Kunde::endreIntrsone() {
	IntrSone* isptr;
	int sone;

	cout << "\nDu er interessert i:\n";
	intrsone->display_list();

	sone = les("\nHvilke(n) sone(r) vil du endre dine interesser i? (0 for å avslutte)", 0, 100);

	while (sone != 0) {
		if (intrsone->in_list(sone)) {
			isptr = (IntrSone*)intrsone->destroy(sone);
			intrsone->add(new IntrSone(sone));
		}
		else
			sone = les("\nHvilke(n) sone(r) vil du "
			"endre dine interesser i? (0 for å avslutte)", 0, 100);

	}
}