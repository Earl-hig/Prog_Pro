#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "Soner.h"
#include "const.h"
#include "funk.h"


Soner::Soner() {
	cout << "\nHei jeg er soner";

	char * sonexx;
	sonexx = new char[STRLEN];
	strcpy (sonexx, "sone000.DTA");

	cout << "\nLeser fra " << siste_dta;
	ifstream inn_siste("SISTE.DTA");
	inn_siste >> sisteSone;

	for (int i = 1; i < MAXSONE; i ++) {
		
		lag_navn(sonexx, i,1, 4);

		cout << "\nFilnavn: " << sonexx;

		ifstream inn_data(sonexx);

		if (!inn_data){
			cout << "\tFant ikke";
			soner[i] = NULL;
		}

		else {
			cout << "\tÅpner opp....";
			soner[i] = new Sone(inn_data);

		}

	}
	delete []sonexx;
}

Soner::~Soner() {

}
