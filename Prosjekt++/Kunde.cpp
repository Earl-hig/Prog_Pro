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
	cout << "\n\nLager n� en kunde!!";
	IntrSone * intrsone_temp;
	int sone, max_pris, min_ar, ant, typ, valg, onsk;
	intrsone = new List (Sorted);


	telefon = les("\nSkriv inn telefon nr: ", 10000000, 99999999);
	les ("\nSkriv inn navnnet: ", &navn, NVNLEN);
	les ("\nSkriv inn epost adr: ", &mail, STRLEN);
	les ("\nSkriv inn gate adressen din: ", &gate, STRLEN);
	les ("\nSkriv inn postnr/sted: ", &adresse, STRLEN);

	cout << "\nLeser n� inn info for intrsone";

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
	Eiendom* til_samenlign;
	int oppdrag_nr;

	for (int i = 1; i <= intrsone -> no_of_elements(); i++) {
		intresert_temp = (IntrSone*)intrsone -> remove_no(i);

		cout << "\nSone nr: " << intresert_temp -> return_nr();

		sone_temp = sonebase.return_sone_nr(intresert_temp -> return_nr());

		if (sone_temp) {
			cout << '\t' << '\'' << "aapner sonen" << '\'';
			eindoms_liste = sone_temp -> return_eindom_list();
			cout << '\n' << eindoms_liste -> no_of_elements() << " eindomer vi skal se paa...";

			for (int j = 1; j <= eindoms_liste -> no_of_elements(); j++) {
				til_samenlign = (Eiendom*)eindoms_liste -> remove_no(j);

				if ((intresert_temp -> samlign(til_samenlign)) == 2) {
					
					cout << "\n\n***skal skrive til: " << til_samenlign -> return_opdrag_nr() << "***";
					oppdrag_nr = til_samenlign -> return_opdrag_nr();
					skriv_til_e_dta(oppdrag_nr);

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


void Kunde::finn_ukentlig_intersser() {
	cout << "\n\nNaa begyner vi aa lette etter det du er intresert i!";

	IntrSone* intresert_temp;
	Sone* sone_temp;
	List* eindoms_liste = new List(Sorted);
	Eiendom* til_samenlign;

	char* filnavn;
	filnavn = new char[NVNLEN / 2];
	strcpy(filnavn, "K0000000.INF");
	lag_navn(filnavn, number,1, 4);
	
	ofstream ut_data(filnavn);

	ut_data << navn << '\t' << telefon << '\t' << mail
		<< '\n' << gate << '\t' << adresse
		<< "\n\n**********Detter kunden intresert i**********\n\n";

	for (int i = 1; i <= intrsone -> no_of_elements(); i++) {
		intresert_temp = (IntrSone*)intrsone -> remove_no(i);

		cout << "\nSone nr: " << intresert_temp -> return_nr();

		sone_temp = sonebase.return_sone_nr(intresert_temp -> return_nr());

		if (sone_temp) {
			cout << '\t' << '\'' << "aapner sonen" << '\'';
			eindoms_liste = sone_temp -> return_eindom_list();
			cout << '\n' << eindoms_liste -> no_of_elements() << " eindomer vi skal se paa...";

			for (int j = 1; j <= eindoms_liste -> no_of_elements(); j++) {
				til_samenlign = (Eiendom*)eindoms_liste -> remove_no(j);

				if ((intresert_temp -> samlign(til_samenlign)) == 1) {
					
					cout << "\n\n***skal lege til  oppdrag: " << til_samenlign -> return_opdrag_nr() << "***";
		

					ut_data << "\n**************************************************";
					til_samenlign -> skrivTilFil(ut_data);
					ut_data << "\n**************************************************";

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

	delete []filnavn;
}

void Kunde::skriv_til_e_dta(int opp_nr) {
	char* filnavn;

	filnavn = new char[NVNLEN / 2];
	strcpy(filnavn, "E0000000.DTA");
	lag_navn(filnavn, opp_nr, 1, 4);

	fstream ut_data(filnavn, ios::app);

	ut_data << "**********\n" << navn << '\n' << gate << '\n' << adresse << '\n';

	delete []filnavn;
}

void Kunde::er_intresert_eindom(Eiendom* eiendomen, int sone_nr) {
	IntrSone* temp_intrsone;
	if (intrsone -> in_list(sone_nr)) {
		cout << "\nDet finnes en mulighet";
		temp_intrsone = (IntrSone*)intrsone -> remove(sone_nr);

		if ( (temp_intrsone -> samlign(eiendomen) ) == 2) {
			skriv_til_e_dta( eiendomen -> return_opdrag_nr() );
		}

		intrsone -> add(temp_intrsone);
	}
	else
		cout << "\nFant ikke sonen";

	// delete temp_intrsone;
}