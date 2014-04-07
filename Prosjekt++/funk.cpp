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
	int n;
	do {
		cout << '\t' << t << " (" << MIN << '-' << MAX << "): ";
		cin >> n; cin.ignore();
	} while (n < MIN || n > MAX);
	return n;
}

void les(char t[], char s[], const int LEN) { // Leser tekst:
	do  {
		cout << '\t' << t << ": ";     //  Skriver ledetekst.
		cin.getline(s, LEN);           //  Leser inn tekst.
  } while (strlen(s) == 0);       //  Sjekker at tekstlengden er ulik 0.
}

void les (char txt[],char * *ptr , const int LEN) {
  cout << txt;
  char * buffer;
  buffer = new char [LEN+1];
  cin.getline(buffer, LEN);
  *ptr = new char [strlen(buffer)+1];
  strcpy(*ptr, buffer);
  delete [] buffer;
}

void skrivMeny() {

	cout << "\n\n\t\tMENYVALG:";
	cout << "\n\n\tFølgende kommandoer er tilgjengelig:";
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

void eiendomHandling(char k) {
	char kommando;
	int nr = 1; // Tester med sone 1
	kommando = les();

	while (kommando != 'Q') {
		switch (kommando) {
		case 'D':
			break;
		case 'N': nyEiendom(nr);
			break;
		case 'S':	
			break;
		case 'E':	
			break;
		default:
			break;
		}
		kommando = les();
	}

}

void kundeHandling(char k) {
	char kommando;
	cout << "Kundebase";
	kommando = les();

	
		switch (kommando) {
		case 'D': kundebase.display_kunder();
			break;
		case 'N': kundebase.add_kunde();
			break;
		case 'S':	
			break;
		case 'E':	
			break;
		default:
			break;
		}
		
	
}

void ukentlig(){

}

void olag_navn(char* chrpkr,int number, int prot)
{
 int signs,pos=0;
 signs=strlen(chrpkr);
 prot++;
 signs-=prot;
 while (signs>=pos)
 {
  if (number) chrpkr[(signs)-pos]=number%10+48;
  number/=10;    
  pos++;
 }
 chrpkr[signs+prot]='\0';
}


int postadresse2int(char* chrpkr)
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

void nyEiendom(int nr) {
	if (sonebase.finnesSone(nr)){
		sonebase.nyEiendom(nr);
	}
	else {
		sonebase.nySone(nr);
		sonebase.nyEiendom(nr);
	}
}


void skrivTilFil() {
	sonebase.skrivTilFil();
	kundebase.skrivTilFil();
}
