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






Kunder::Kunder() {				// Parameterløs constructor:

	char * kxx;
	kxx = new char[STRLEN];
	strcpy (kxx, "K0000000.DTA");
	kunde = new List(Sorted);	// Oppretter ny liste (sortert)

	cout << "\nHei jeg er kunder";

	cout << "\nLeser fra " << siste_dta; // leser fra siste.dta
	ifstream inn_siste("SISTE.DTA");
	inn_siste >> forste >> forste >> siste; // lesser inn inter

	cout << "\nForste er: " << forste << "\nSiste er: " << siste;

	for (int i = forste; i <= siste; i++) { // for alle gyldige kunder
		cout << "\nPrøver å lese kunde nr: " << i;
		lag_navn(kxx, i ,1, 4); // lager fil navn
		cout << '\n' << kxx;

		ifstream inn_data(kxx); // åpner fil

		if (!inn_data) {
			cout << "\nTrue";
		}

		else { // leser ny kunde fra fil
			
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

void Kunder::add_kunde () { // legger til ny kunde
	Kunde * kunde_temp;
	kunde_temp = new Kunde(++siste); // lagger ny kunde
	kunde_temp -> finn_interesser(); // finner interesser til kunden
	kunde -> add(kunde_temp);		 // leger kunden til i listen
	// delete kunde_temp;
}

void Kunder::display_kunder () // Displayer Kunder
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
	if (tmpint) // hvis nr
	{cout <<"\nSoeker paa kundernr."<<tmpint<<endl;
			ok=kunde->display_element(tmpint); // display
			
	}

	else // else navn
	{
		cout <<"Du skrev et navn luring.";

		tmpint=kunde->no_of_elements();
		cout <<"\nElementer:"<<tmpint<<"\n";
		for (int j=1;j<=tmpint;j++) // for alle kundene
		{
			kunde_temp=(Kunde*)kunde->remove_no(j);
			cout <<endl;
			
			if (!strcmp(tmpstr,kunde_temp->get_navn())) // hvis navn er lik
			{
			kunde_temp->display();						// display kunde
			ok=true;
			}
			kunde->add(kunde_temp);
		}
		if (!ok) cout <<"Feil navn. Dette går ikke ann!";
	}

	
}

void Kunder::skrivTilFil() {	// Skriver kunder til fil:
	int i = 1;
	int ant = 0;
	Kunde* kun;
								// Oppretter filen
	ofstream utfil1("SISTE.DTA", ios::app);

	utfil1 << forste << '\n' << siste << '\n';
	
	if (!kunde->is_empty()) {	// Hvis lista ikke er tom
		ant = kunde->no_of_elements();
		for (i = 1; i <= ant; i++) { // Går gjennom lista
			kun = (Kunde*)kunde->remove_no(i);
			kun->skrivTilFil(); // Ber hver enkelt skrive seg til fil
			kunde->add(kun);	// Adder tilbake
		}
	}
	else cout << "\nLista er tom!"; // Lista er tom
}


void Kunder::kundeHandling(char k) 
		{
	     char kommando;
	     cout << "Kundebase";
	     kommando = les();

	
		switch (kommando) {
		case 'D': display_kunder();	// displayer en kunde
			break;
		case 'N': add_kunde();		// legger til ny kunde
			break;
		case 'S': slett_kunde();	// sletter kunden
			break;
		case 'E': endreKunde();		// endrer kunden
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
	tmpint=les("\nSkriv inn ett kundenr:",1,9999); // leser inn kunde nr
	
	cout <<"\nSoeker paa kundernr."<<tmpint<<endl;
			ok=kunde->display_element(tmpint); // ser om kunden finnes
			if (!ok) 
			{cout << "Feil kundenr."; return;} // retunerer ut om false

	cout << "\nSkriv kundenr en gang til for aa bekrefte sletting:";
	tmp=les("\nSkriv inn ett kundenr:",1,9999);
	if (tmpint==tmp)
	{
		cout<<"Sletter kunden";
		if (kunde->no_of_elements()<2) 
		{cout <<"\nForbudt å slette siste kunde!";
		return;}
		kunde_temp=(Kunde*)kunde->remove(tmpint); // fjerner fra liste
		kunde_temp->slettFil();					  // sletter filen
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

	// for alle kunder
	for (int i = 1; i <= kunde -> no_of_elements(); i++) {
		temp_kunde = (Kunde*)kunde -> remove_no(i);

		// finn interessen
		temp_kunde -> er_intresert_eindom(eiendomen, sone_nr);

		kunde -> add(temp_kunde);
	}

	// delete temp_kunde;
}

void Kunder::finn_ukentlig_interessee() {
		cout << "\nEtt hak dypere";
		Kunde* temp_kunde;

		// for alle kundene
		for (int i = 1; i <= kunde -> no_of_elements(); i++) {
			cout << "\nKunde " << i;
			temp_kunde = (Kunde*)kunde -> remove_no(i);

			temp_kunde -> finn_ukentlig_intersser(); // finn interessen

			kunde -> add(temp_kunde);
		}
		// delete temp_kunde;
}

void Kunder::endreKunde(){				// Funksjon som endrer kunde
		Kunde* kptr;
		char valg;
		int knr = les("\nKundenummer", forste, siste);

		if (!kunde->is_empty()) {			// Hvis lista ikke er tom
			if (kptr = (Kunde*)kunde->remove(knr)) {// Hvis den klarte å remove
				cout << "\nHva vil du endre på?";
				cout << "\n(K)unden eller en (I)nteressesone: ";
				valg = les();
				
				switch (valg) {
					case 'K': delete kptr;					// endrer kunden
							  kunde->add(new Kunde(knr));
							  break;
					case 'I': kptr->endreIntrsone();		// endrer interesen
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