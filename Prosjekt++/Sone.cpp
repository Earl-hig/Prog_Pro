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

Sone::Sone(ifstream & inn) {  // Constructor som leser fra fil:
	cout << "\nLeser sone fra fil...";
	eiendom = new List(Sorted);	// Oppretter ny liste (sortert)
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

void Sone::skrivTilFil(ofstream & ut) { // Skriver Sone til fil
	int i, ant = eiendom->no_of_elements();
	Eiendom* enptr;


	ut << beskrivelse << '\n';
	ut << ant << '\n';

	for (i = 1; i <= ant; i++) {
		enptr = (Eiendom*)eiendom->remove_no(i);
		enptr->skrivTilFil(ut);
		eiendom->add(enptr);
	
	}
}

void Sone::nyEiendom(int oppdnr) { // Oppretter ny eiendom
	char valg;

	do {						// Leser eiendomstype
		cout << "\nEiendomstype (T)omt, (E)nebolig, (R)ekkehus, (L)eilighet,"
			<< "(H)ytte: \n";
		valg = les();} 
	
	while (valg != 'T' && valg != 'E' && valg != 'R' && valg != 'L' &&
			 valg != 'H');


		if (valg == 'T')		// Hvis det er en tomt, legges kun eiendom inn
			eiendom->add(new Eiendom(0, oppdnr));

		else if (valg == 'E')  // Alle andre tilfeller legges det inn en bolig
			eiendom->add(new Bolig(1, oppdnr));

		else if (valg == 'R')
			eiendom->add(new Bolig(2, oppdnr));

		else if (valg == 'L')
			eiendom->add(new Bolig(3, oppdnr));

		else if (valg == 'H')
			eiendom->add(new Bolig(4, oppdnr));
}


void Sone::nySone() {			// Legger inn en ny Sone
	char buffer[STRLEN];
								// Leser beskrivelse
	les("\nBeskrivelse av sonen", buffer, STRLEN);
	beskrivelse = new char[strlen(buffer) + 1];
	strcpy(beskrivelse, buffer);

	eiendom = new List(Sorted); // Oppretter ny eiendomsliste

}



int Sone::display()				// Displayer Sone
		{
			cout <<"Viser sone med "<< eiendom->no_of_elements()<<" elementer."; 

			eiendom->display_list();
			
			return 0;
		}


List* Sone::return_eindom_list() {
	return eiendom;
}


int Sone::display_some(int postnr)
		{int tmpint;

		  
		   Eiendom * tmpeiendom;
		
		    
			tmpint=eiendom->no_of_elements();
			//cout <<"Valgt sone har "<<tmpint<<" elementer";
			if (postnr>9999)
			//postnr er ikke et postnr men et ordrenr
				{
					eiendom->display_element(postnr);
				}
			else
			//postnr er et korrekt postnr
			for (int j=1;j<=tmpint;j++)
			{
		
			tmpeiendom=(Eiendom*)eiendom->remove_no(j);
			if (tmpeiendom->getpnr()==postnr) tmpeiendom->display();
			eiendom->add(tmpeiendom);
				
			}
			return 0;
		};


int Sone::slett(int oppdragsnr)
		{int tmpint;
 
		   Eiendom * tmpeiendom;
				    
			tmpint=eiendom->no_of_elements();
			cout <<"\nValgt sone har "<<tmpint<<" elementer";
			//tmpeiendom=NULL;
			tmpeiendom=(Eiendom*)eiendom->remove(oppdragsnr);
			//cout << int(tmpeiendom);
			return int(tmpeiendom);
		};

bool Sone::harOppdnr(int nr){   // Returnerer True/False om sonen har oppnr
	int i, ant = eiendom->no_of_elements();
	Eiendom* enptr;
	
	for (i = 1; i <= ant; i++){ // Går gjennom lista
		enptr = (Eiendom*)eiendom->remove_no(i);
		if (enptr->harOppdnr(nr)) // Hvis eiendom har gitt oppdragsnummer
			return true;		  // Returnerer true
		eiendom->add(enptr);
	}
	return false;				  // Returnerer false
}

void Sone::endreEiendom(int oppdnr) { // Endrer gitt eiendom
	Bolig* boptr;
	Eiendom* enptr;
									   // Hvis det er en bolig
	if (boptr = (Bolig*)eiendom->remove(oppdnr)){
		delete boptr;				   // Sletter bolig
		nyEiendom(oppdnr);			   // Legger inn på nytt
	}
	else {							   // Hvis det er en eiendom
		enptr = (Eiendom*)eiendom->destroy(oppdnr); // Sletter eiendom
		nyEiendom(oppdnr);			   // Legger inn på nytt
	}
}

		
		


