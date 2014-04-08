#if !defined(__KUNDER_H)
#define __KUNDER_H

#include "const.h"
#include "Kunde.h"
#include "listtool2.h"
#include "funk.h"


class Kunder {
	private:
		int forste, siste;
		List* kunde;

	public:
		Kunder();
		~Kunder();
		void add_kunde();
		void display_kunder();
		void skrivTilFil();
		void kundeHandling(char k);
		void slett_kunde () 
{
	char tmpstr[STRLEN+1];
	int tmpint,tmp;
	bool ok=false;
	Kunde * kunde_temp;
	cout << "\n*** Slett kunde ***";
	tmpint=les("\nSkriv inn ett kundenr:",1,9999);
	

	
	if (tmpint) 
	{cout <<"\nSoeker paa kundernr."<<tmpint<<endl;
			ok=kunde->display_element(tmpint);
			if (!ok) 
			{cout << "Feil kundenr."; return;}

	cout << "\nSkriv kundenr en gang til for aa bekrefte sletting:";
	tmp=les("\nSkriv inn ett kundenr:",1,9999);
	if (tmpint==tmp)
	{
		cout<<"Sletter kunden";
		kunde->remove_no(tmpint);
	}
	else
	{cout << "Du feiget ut.";}

	}
	
}

};

#endif


