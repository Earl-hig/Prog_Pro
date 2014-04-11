#include <iostream>
#include <fstream>
#include <cstring>

#include "Kunder.h"
#include "const.h"
#include "funk.h"
#include "listtool2.h"
#include "extern.h"
#include "Eiendom.h"

using namespace std;






Kunder::Kunder() {

	char * kxx;
	kxx = new char[STRLEN];
	strcpy (kxx, "K0000000.DTA");
	kunde = new List(Sorted);

	cout << "\nHei jeg er kunder";

	cout << "\nLeser fra " << siste_dta;
	ifstream inn_siste("SISTE.DTA");
	inn_siste >> forste >> forste >> siste;

	cout << "\nForste er: " << forste << "\nSiste er: " << siste;

	for (int i = forste; i <= siste; i++) {
		cout << "\nPrøver å lese kunde nr: " << i;
		lag_navn(kxx, i ,1, 4);
		cout << '\n' << kxx;

		ifstream inn_data(kxx);

		if (!inn_data) {
			cout << "\nTrue";
		}

		else {
			
			Kunde * kunde_temp;

			kunde_temp = new Kunde(inn_data, i);

			kunde -> add(kunde_temp);

			// delete kunde_temp;
		}
	}
	delete []kxx;
}

Kunder::~Kunder() {

}

void Kunder::add_kunde () {
	Kunde * kunde_temp;
	kunde_temp = new Kunde(++siste);
	kunde_temp -> finn_interesser();
	kunde -> add(kunde_temp);	
	// delete kunde_temp;
}

void Kunder::display_kunder () 
{
	char tmpstr[STRLEN+1];
	int tmpint,tmp;
	bool ok=false;
	Kunde * kunde_temp;
	cout << "\n*** Viser kunder ***";
	//tmpint=les("\nSkriv inn ett kundenr:",1,9999);
	les("\nSkriv inn kundenr eller navn",tmpstr,STRLEN);
	tmpint=postadresse2int(tmpstr);
	//bruker funksjonen for å trekke nr ut av adresse
	if (tmpint) 
	{cout <<"\nSoeker paa kundernr."<<tmpint<<endl;
			ok=kunde->display_element(tmpint);
			
	}

	else 
	{
		cout <<"Du skrev et navn luring.";

		tmpint=kunde->no_of_elements();
		cout <<"\nElementer:"<<tmpint<<"\n";
		for (int j=1;j<=tmpint;j++)
		{
			kunde_temp=(Kunde*)kunde->remove_no(j);
			cout <<endl;
			
			if (!strcmp(tmpstr,kunde_temp->get_navn()))
			{
			kunde_temp->display();
			ok=true;
			}
			kunde->add(kunde_temp);
		}
		if (!ok) cout <<"Feil navn. Dette går ikke ann!";
	}

	
}

void Kunder::skrivTilFil() {
	int i = 1;
	int ant = 0;
	Kunde* kun;

	ofstream utfil1("SISTE.DT2", ios::app);

	utfil1 << forste << '\n' << siste << '\n';

	if (!kunde->is_empty()) {
		ant = kunde->no_of_elements();
		for (i = 1; i <= ant; i++) {
			kun = (Kunde*)kunde->remove_no(i);
			kun->skrivTilFil();
			kunde->add(kun);
		}
	}
	else cout << "\nLista er tom!";
}


void Kunder::kundeHandling(char k) 
		{
	     char kommando;
	     cout << "Kundebase";
	     kommando = les();

	
		switch (kommando) {
		case 'D': display_kunder();
			break;
		case 'N': add_kunde();
			break;
		case 'S': slett_kunde();	
			break;
		case 'E': endreKunde();
			break;
		default:
			break;
		}
		}


void Kunder::slett_kunde () 
{
	char tmpstr[STRLEN+1];
	int tmpint,tmp;
	
	bool ok=false;
	Kunde * kunde_temp;
	cout << "\n*** Slett kunde ***";
	tmpint=les("\nSkriv inn ett kundenr:",1,9999);
	
	cout <<"\nSoeker paa kundernr."<<tmpint<<endl;
			ok=kunde->display_element(tmpint);
			if (!ok) 
			{cout << "Feil kundenr."; return;}

	cout << "\nSkriv kundenr en gang til for aa bekrefte sletting:";
	tmp=les("\nSkriv inn ett kundenr:",1,9999);
	if (tmpint==tmp)
	{
		cout<<"Sletter kunden";
		if (kunde->no_of_elements()<2) 
		{cout <<"\nForbudt å slette siste kunde!";
		return;}
		kunde_temp=(Kunde*)kunde->remove(tmpint);
		kunde_temp->slettFil();
		// her trengs filskriving

		if (tmpint==forste)
		{// Oppdatering av SISTE.DTA
		//cout << "\nDu slettet foerste kunde";
		  kunde_temp=(Kunde*)kunde->remove_no(1);
		  forste=kunde_temp->get_number();
		  kunde->add(kunde_temp);
		  ofstream tmputfil(siste_dta);
		  tmputfil << sonebase.getsisteOppdrag() << '\n';
	      tmputfil << forste<<endl<<siste<<endl;
		}

	}
	else cout << "Du feiget ut.";
}

void Kunder::finn_interesser_for_eindom(Eiendom* eiendomen, int sone_nr) {
	cout << "\n\nVi skal finne om noen har lyst på denne nye eindomen";

	Kunde* temp_kunde;

	for (int i = 1; i <= kunde -> no_of_elements(); i++) {
		temp_kunde = (Kunde*)kunde -> remove_no(i);

		temp_kunde -> er_intresert_eindom(eiendomen, sone_nr);

		kunde -> add(temp_kunde);
	}

	// delete temp_kunde;
}

void Kunder::finn_ukentlig_interessee() {
		cout << "\nEtt hak dypere";
		Kunde* temp_kunde;

		for (int i = 1; i <= kunde -> no_of_elements(); i++) {
			cout << "\nKunde " << i;
			temp_kunde = (Kunde*)kunde -> remove_no(i);

			temp_kunde -> finn_ukentlig_intersser();

			kunde -> add(temp_kunde);
		}
		// delete temp_kunde;
}

void Kunder::endreKunde(){				// Funksjon som endrer kunde
		Kunde* kptr;
		char valg;
		int knr = les("\nKundenummer", forste, siste);

		if (!kunde->is_empty()) {			// Hvis lista ikke er tom
			if (kptr = (Kunde*)kunde->remove(knr)) { // Hvis den klarte å remove
				cout << "\nHva vil du endre på?";
				cout << "\n(K)unden eller en (I)nteressesone: ";
				valg = les();
				
				switch (valg) {
					case 'K': delete kptr; 
							  kunde->add(new Kunde(knr));
							  break;
					case 'I': kptr->endreIntrsone(); 
							  kunde->add(kptr);
							  break;
					default:  cout << "\nUgyldig kommando!";
				}
			}
			else							// Klarte ikke å remove
				cout << "\nFinner ingen kunde med nummer " << knr;
		}
		else								// Lista er tom
			cout << "\nLista er tom!";
}