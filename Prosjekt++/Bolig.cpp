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
	//cout << "\n\nN� er vi p� bolig delen....";
	int enum_temp;
	inn >> bygar >> bruar >> boareal >> antSov >> enum_temp;
	inn.ignore();

	salg_onske = (salgstype)enum_temp;
	cout << "\n*** BOLIG  ***";
	cout << "\nByggareal: " << bygar << "\tBrutto areal: " << bruar << "\tBoareal: " << boareal
		 << "\nAnt soverom: " << antSov << "\tSalg �nske: " << salg_onske<<endl;
	//return;
}

Bolig::~Bolig() {

}



void Bolig::display() {
	display_e();	//Eiendom:display();
	cout << "\n*** BOLIG  ***";
	cout << "\nByggareal: " << bygar << "\tBrutto areal: " << bruar << "\tBoareal: " << boareal
		 << "\nAnt soverom: " << antSov << "\tSalg �nske: " << salg_onske<<endl;

}

int Bolig::return_ant_sov() {return antSov;}

int Bolig::return_boareal() {return boareal;}

salgstype Bolig::return_salsg_type() {return salg_onske;}