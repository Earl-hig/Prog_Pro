#include <iostream>

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