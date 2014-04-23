#include <iostream>
#include <cctype>
#include <cstring>


using namespace std;

#include "const.h"
#include "extern.h"
#include "Sone.h"

char les() {
	char ch;
	cout << "\n\nKommando:  ";   cin >> ch;   cin.ignore();
	return (toupper(ch));			   // Returnerer upcased tegn
}

int les(char t[], const int MIN, const int MAX) { // Leser tall:
	int n;					// hjelpe variabeler
	char tmpstr[STRLEN];

	do {					// loop for å lese in tall n
		cout << '\t' << t << " (" << MIN << '-' << MAX << "): ";
		cin >> tmpstr; 
		n=postadresse2int(tmpstr);
		cin.ignore();
	} while (n < MIN || n > MAX);
	return n;				// retunerer tallet
}

void les(char t[], char s[], const int LEN) { // Leser tekst:
	do  {
		cout << '\t' << t << ": ";     //  Skriver ledetekst.
		cin.getline(s, LEN);           //  Leser inn tekst.
  } while (strlen(s) == 0);       //  Sjekker at tekstlengden er ulik 0.
}

void les (char txt[],char * *ptr , const int LEN) { // leser tekst
  cout << txt;							// Skriver ledetekst
  char * buffer;						// hjelpe variabel
  buffer = new char [LEN+1];			//
  cin.getline(buffer, LEN);				// leser inn i hjelpe variabel 
  *ptr = new char [strlen(buffer)+1];	// adresser minne
  strcpy(*ptr, buffer);					// overfører til ptr
  delete [] buffer;						// sleter hjelpe variabel
}

void skrivMeny() {					   // Oversikt over gjeldende menyvalg:

	cout << "\n\n\t\tMENYVALG:";
	cout << "\n\n\tFoelgende kommandoer er tilgjengelig:";
	cout << "\n\n\tE D <oppdnr> | <pnr> - Eiendom Display <oppdragsnr> "
		 << "eller <postnr>";
	cout << "\n\tE N <sonenr> - Eiendom Ny <sonenummer>";
	cout << "\n\tE S <oppdnr> - Eiendom Slett <oppdragsnummer>";
	cout << "\n\tE E <oppdnr> - Eiendom Endre <oppdragsnummer>";
	cout << "\n\tS D <sonenr> - Sone Display <sonenummer>";
	cout << "\n\n\tK D <knr> | <knavn> - Kunde Display <kundenr> "
		 << "eller <kundenavn>";
	cout << "\n\tK N - Kunde Ny";
	cout << "\n\tK S <knr> - Kunde Slett <kundenr>";
	cout << "\n\tK E <knr> - Kunde Endre <kundenr>";
	cout << "\n\n\t U - Ukentlig utskrift/status/sending";

}


void ukentlig(){ // finner ukenlig intereser
	cout << "\nDu er naa i komando u delen....";
	kundebase.finn_ukentlig_interessee();	// kaller kunder sin funksjon
}




int postadresse2int(char* chrpkr) // konvertere char til int
{
	int j=0;
	int tmpint=0;
	while (chrpkr[j]>=48&&chrpkr[j]<58 )
	{
		tmpint*=10;
		tmpint+=chrpkr[j]-48;
		j++;
	}
	return tmpint;
}




void skrivTilFil() {				   // Skriver til fil:
	sonebase.skrivTilFil();		// sone skriv til fil
	kundebase.skrivTilFil();	// kunde skriv til fil
}