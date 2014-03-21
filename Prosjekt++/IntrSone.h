#if !defined(__INTRSONE_H)
#define __INTRSONE_H


#include "listtool2.h"
#include "enum.h"

class IntrSone : public Num_element {
	private:
		int maxpris, minareal, antSov;
		enum eiendomstype, tilsending, salgstype;

	public:
		IntrSone();
		IntrSone(int n) : Num_element(n);
		~IntrSone();
		virtual void display();

};

#endif
