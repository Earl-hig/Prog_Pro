#if !defined(__SONE_H)
#define __SONE_H

#include <fstream>
#include <iostream>

#include "Eiendom.h"

using namespace std;

class Sone {
	private:
		char* beskrivelse;
		List* eiendom;

	public:
		Sone();
		Sone(ifstream & inn);
		~Sone();

};


#endif