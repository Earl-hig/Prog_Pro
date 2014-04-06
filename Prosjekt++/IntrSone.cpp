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
	cout << "\nSone: " << number << "\tPris: " << maxpris << "\tAreal: " << minareal << "\tSoverom: " << antSov;

	inn >> enum_temp;
	sending_valg = (tilsending)enum_temp;

	inn >> enum_temp;
	salg_onske = (salgstype)enum_temp;

	inn >> enum_temp;
	type = (eiendomstype)enum_temp;

	cout << "\nSending valg: " << sending_valg << "\tSalgs ønske: " << salg_onske << "\tType bolig:" << type;

	
}

IntrSone::~IntrSone() {

}

void IntrSone::display() {

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
		cout << "\nvi er på ret spor";

		if ((eindom_temp ->return_type()) == Tomt) {
			cout << "\nDene oppdraget er en tomt";

			if ((eindom_temp ->return_pris()) < maxpris) {
				cout << "\nPrisen er grei";
			

			if (minareal < (eindom_temp -> return_tomt_areal())) {
				cout << "\nAreal er ogsaa grei";

				ret_val = true_ret;
			}
			}
		}
		else {
			cout << "\ndu har med en byg aa gjore";
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