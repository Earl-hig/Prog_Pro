#if !defined(__KUNDER_H)
#define __KUNDER_H

#include "const.h"
#include "Kunde.h"
#include "listtool2.h"


class Kunder {
	private:
		int forste, siste;
		List* kunde;

	public:
		Kunder();
		~Kunder();
		void add_kunde();
};

#endif


