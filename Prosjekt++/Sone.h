#if !defined(__SONE_H)
#define __SONE_H


#include "Eiendom.h"

class Sone {
	private:
		char* beskrivelse;
		Eiendom* eiendom;

	public:
		Sone();
		~Sone();

};


#endif