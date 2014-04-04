#if !defined(__FUNK_H)
#define _FUNK_H

//			DEKLARASJON AV FUNKSJONSHEADINGER


char les();
int les(char t[], const int MIN, const int MAX);
void les(char t[], char s[], const int LEN);
void eiendomHandling(char k);
void kundeHandling(char k);
void skrivMeny();
void nyEiendom(int nr);
void displayEiendom(int nr);
void slettEiendom(int nr);
void endreEiendom(int nr);
void displaySone(int nr);
void displayKunde(int nr);
void displayKunde(char* nvn);
void nyKunde();
void slettKunde(int nr);
void endreKunde(int nr);
void ukentlig();



#endif
