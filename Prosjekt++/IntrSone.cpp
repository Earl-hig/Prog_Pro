#include <fstream>
#include <iostream>
#include <cstring>

#include "IntrSone.h"
#include "const.h"
#include "Eiendom.h"
#include "Bolig.h"

using namespace std;


IntrSone::IntrSone() {

}

IntrSone::IntrSone(int sone, int max, int min, int ant, int typ, int valg, int onsk) :Num_element(sone) {
	cout << "\n construktor type alle variabler kjent";
	maxpris = max;
	minareal = min;
	antSov = ant;
	type = (eiendomstype)typ;
	salg_onske = (salgstype)onsk;
	sending_valg = (tilsending)valg;
}

IntrSone::IntrSone(ifstream & inn, int i) :Num_element(i) {

	int enum_temp;

	cout << "\nInne i les fra fil construkt";
	inn >> maxpris >> minareal >> antSov;
	

	inn >> enum_temp;
	sending_valg = (tilsending)enum_temp;

	inn >> enum_temp;
	salg_onske = (salgstype)enum_temp;

	inn >> enum_temp;
	type = (eiendomstype)enum_temp;


	cout << "\nSone: " << number << "\tPris: " << maxpris << "\tAreal: " << minareal << "\tSoverom: " << antSov;
	cout << "\nSending valg: " << sending_valg << "\tSalgs oenske: " << salg_onske << "\tType bolig:" << type;

	
}

IntrSone::IntrSone(int sone) {
	int max_pris, min_ar, ant, typ, valg, onsk;
	
	max_pris = les("\nskriv inn max pris", 1000000, 10000000);
	min_ar = les("\nSkriv inn min areal", 50, 200);
	ant = les("\nSkriv in antall soverom", 1, 10);
	typ = les("\nTomt = 0, Enenebolig = 1, Rekke hus = 2\
			  			  \nLelighet = 3, hytte = 4", 0, 4);
	valg = les("\nUkentlig = 0, Salgsoppgave = 1", 0, 1);
	onsk = les("\nSalg = 0, leie = 1, begge er = 2", 0, 2);
}

IntrSone::~IntrSone() {

}

void IntrSone::display() {
	cout << "\nSone: " << number << "\tPris: " << maxpris << "\tAreal: " << minareal << "\tSoverom: " << antSov;
	cout << "\nSending valg: " << sending_valg << "\tSalgs oenske: " << salg_onske << "\tType bolig:" << type;
}

// 0 = ingen interesse, 1 = ukentlig innteresse, 2 = salgsopgave
int IntrSone::samlign(Element* boligen) {
	cout << "\n\nSamenligner interesse med en eindom";
	int true_ret;
	int ret_val = 0;
	Eiendom* eindom_temp;
	Bolig* bolig_temp;

	if (sending_valg == Ukentlig) {
		true_ret = 1;
	}
	else if (sending_valg == Salgsoppgave) {
		true_ret = 2;
	}

	eindom_temp = (Eiendom*)boligen;


	if (type == eindom_temp ->return_type()) {
		cout << "\nVi er paa ret spor";

		if ((eindom_temp ->return_type()) == Tomt) {
			cout << "\nDette oppdraget er en tomt";

			if ((eindom_temp ->return_pris()) < maxpris) {
				cout << "\nPrisen er grei";
			

			if (minareal < (eindom_temp -> return_tomt_areal())) {
				cout << "\nAreal er ogsaa grei";

				ret_val = true_ret;
			}
			}
		}
		else {
//cout << "\ndu har med en bygg aa gjore";
			bolig_temp = (Bolig*)eindom_temp;

			if (antSov < (bolig_temp -> return_ant_sov())) {
				cout << "\nSoverom er grei";
			
			if ((bolig_temp -> return_pris()) < maxpris) {
				cout << "\nPris er grei";
			
			if (minareal < (bolig_temp -> return_boareal())) {
				cout << "\nAreal er grei";
			
			if (((bolig_temp -> return_salsg_type()) == Begge) || (salg_onske == Begge) || ((bolig_temp -> return_salsg_type()) == salg_onske)) {
				cout << "\nSalgsonske er grei";
				ret_val = true_ret;
			}
			}
			}
			}
		}
	}

	else {
		cout << "\nIkke det du lette etter";
	}

	


	// delete eindom_temp;
	// delete bolig_temp;
	return ret_val;
}


int IntrSone::return_nr() {
	return number;
}

void IntrSone::skrivTilFil(ofstream & ut){
	ut << number << "  " << maxpris << "  ";
	ut << minareal << "  " << antSov << '\n';
	ut << sending_valg << '\n';
	ut << salg_onske << '\n';
	ut << type << '\n';
}