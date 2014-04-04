#if !defined(__FUNK_H)
#define __FUNK_H

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
void olag_navn(char* chrpkr,int number, int prot);


inline void lag_navn(char* chrpkr,int number, int prot_first, int prot)
{
 for (int signs=strlen(chrpkr)-prot;number&&-prot_first+signs--;number/=10)chrpkr[signs]=number%10+48;
}// Prosedyren endrer filnavn.. FILNAVN0000000.DAT men en int, og beskytter et gitt antall tegn i slutt og start fra endring.
 // Man kan f.eks sette prot til 4 og prot_first til 7 om man ønsker å beskytte ".DAT" og "FILNAVN".

inline void lag_navn(char* chrpkr,int number, int prot)
{
 for (int signs=strlen(chrpkr)-prot;number&&-1+signs--;number/=10)chrpkr[signs]=number%10+48;
}// Som under, men prot_first er ikke i bruk, og første tegn i filnavnet er beskyttet som default.



#endif
