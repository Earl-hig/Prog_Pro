#if !defined(__SONER_H)
#define __SONER_H

#include "const.h"
#include "Sone.h"


class Soner {
	private:
		int sisteSone;
		Sone* soner[MAXSONE];

	public:
		Soner()
		{
		};
		~Soner()
		{
		};

};

#endif

