#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "Bolig.h"
#include "Eiendom.h"
#include "const.h"

Bolig::Bolig() {

}

Bolig::Bolig(ifstream & inn, int type, int i) :Eiendom(inn, type, i) {
	cout << "\n\nNå er vi på bolig delen....";
	int enum_temp;
	inn >> bygar >> bruar >> boareal >> antSov >> enum_temp;
	inn.ignore();

	salg_onske = (salgstype)enum_temp;
	
	cout << "\nByggareal: " << bygar << "\tBrutto areal: " << bruar << "\tBoareal: " << boareal
		 << "\nAnt soverom: " << antSov << "\tSalg ønske: " << salg_onske;
}

Bolig::~Bolig() {

}

void Bolig::display() {

}