#include <fstream>
#include <iostream>
#include <cstring>

#include "IntrSone.h"
#include "const.h"

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
