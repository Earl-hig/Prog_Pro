#include <iostream>
#include <cctype>
#include <cstring>


using namespace std;

#include "const.h"

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

}

void kundeHandling(char k) {

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

void lag_navn(char* chrpkr,int number, int prot)
{
 for (int signs=strlen(chrpkr)-prot;number&&-1+signs--;number/=10)chrpkr[signs]=number%10+48;
}// Som under, men prot_first er ikke i bruk, og første tegn i filnavnet er beskyttet som default.

inline void lag_navn(char* chrpkr,int number, int prot, int prot_first)
{
 for (int signs=strlen(chrpkr)-prot;number&&-prot_first+signs--;number/=10)chrpkr[signs]=number%10+48;
}// Prosedyren endrer filnavn.. FILNAVN0000000.DAT men en int, og beskytter et gitt antall tegn i slutt og start fra endring.
 // Man kan f.eks sette prot til 4 og prot_first til 7 om man ønsker å beskytte ".DAT" og "FILNAVN".