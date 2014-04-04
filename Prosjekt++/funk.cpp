#include <iostream>

using namespace std;

#include "const.h"

void skrivMeny()
{
};

void eiendomHandling(char k)
{
};
void kundeHandling(char k)
{
};

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

inline void lag_navn(char* chrpkr,int number, int prot)
{
 for (int signs=strlen(chrpkr)-prot;number&&-1+signs--;number/=10)chrpkr[signs]=number%10+48;
}// Som under, men prot_first er ikke i bruk, og f�rste tegn i filnavnet er beskyttet som default.

inline void lag_navn(char* chrpkr,int number, int prot, int prot_first)
{
 for (int signs=strlen(chrpkr)-prot;number&&-prot_first+signs--;number/=10)chrpkr[signs]=number%10+48;
}// Prosedyren endrer filnavn.. FILNAVN0000000.DAT men en int, og beskytter et gitt antall tegn i slutt og start fra endring.
 // Man kan f.eks sette prot til 4 og prot_first til 7 om man �nsker � beskytte ".DAT" og "FILNAVN".