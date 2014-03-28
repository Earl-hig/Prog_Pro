#include <fstream>
#include <iostream>
#include <cstring>

#include "IntrSone.h"
#include "const.h"

using namespace std;


IntrSone::IntrSone() {

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
