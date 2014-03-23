#if !defined(__INTRSONE_H)
#define __INTRSONE_H


#include "listtool2.h"
#include "enum.h"

class IntrSone : public Num_element {
	private:
		int maxpris, minareal, antSov;
		eiendomstype type;
		tilsending sending_valg;
		salgstype salg_onske;

	public:
		IntrSone();
		IntrSone(int n); // : Num_element(n);  trengs ikke i deklarasjonen men bare i definasjonen
		~IntrSone();
		virtual void display();

};

#endif
