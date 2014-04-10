#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#include "Soner.h"
#include "const.h"
#include "funk.h"
#include "Sone.h"


Soner::Soner() {
	cout << "\nHei jeg er soner";

	char * sonexx;
	sonexx = new char[STRLEN];
	strcpy (sonexx, "sone000.DTA");

	cout << "\nLeser fra " << siste_dta;
	ifstream inn_siste("SISTE.DTA");
	inn_siste >> sisteOppdrag;

	for (int i = 1; i < MAXSONE; i ++) {
		
		lag_navn(sonexx, i,1, 4);

		cout << "\nFilnavn: " << sonexx;

		ifstream inn_data(sonexx);

		if (!inn_data){
			cout << "\tFant ikke";
			sonene[i] = NULL;
		}

		else {
			cout << "\t�pner opp....";
			sonene[i] = new Sone(inn_data);

		}

	}
	delete []sonexx;
}

Soner::~Soner() {

}

Sone* Soner::return_sone_nr(int nr) {
	if (nr < 1 || 100 < nr) {
		return NULL;
	}

	Sone* return_ptr = sonene[nr];

	return return_ptr;
}

void Soner::skrivTilFil() {
	char* filnavn;

	filnavn = new char[NVNLEN / 2];
	strcpy(filnavn, "SONE000.DT2");

	ofstream utfil1("SISTE.DT2");

	utfil1 << sisteOppdrag << '\n';

	for (int i = 1; i <= MAXSONE; i++) {
		if (sonene[i] != 0) {
			lag_navn(filnavn, i,1,4);
			ofstream utfil2(filnavn);
			
			sonene[i]->skrivTilFil(utfil2);
		}
		else cout << "\nIngen soner registrert!";
	}
}

void Soner::skrivTilEnFil(int i) {
	char* filnavn;

	filnavn = new char[NVNLEN / 2];
	strcpy(filnavn, "SONE000.DT2");

		
		//if (sonene[i] != 0) 
		{
			lag_navn(filnavn, i,1,4);
			ofstream utfil2(filnavn);
			
			sonene[i]->skrivTilFil(utfil2);
		}
		//else cout << "\nIngen soner registrert!";
	
}





bool Soner::finnesSone(int nr) 
      {return sonene[nr];}


void Soner::nyEiendom(int nr) {
	sisteOppdrag++;
	sonene[nr]->nyEiendom(sisteOppdrag);
}

void Soner::nySone(int nr) {
	sonene[nr] = new Sone();
	sonene[nr]->nySone();
}


int Soner::display(char k)
		{
			int tmpint;
			tmpint=les("Velg sone:",1,MAXSONE-1);
			//for (int j=0; j<MAXSONE;j++)
			{
				if (sonene[tmpint]==NULL)
				{
					cout << "Neinei, denne finnes ikke.";
				}
				else sonene[tmpint]->display();
			}

			return 0;
		};


int Soner::display_more(char k)
		{

			int tmpint,postnr;
			bool ok=false;
			cout<<"Eiendom Display";
			//tmpint=les("Velg sone:",1,MAXSONE-1);

						
		    postnr=les("Postnr eller oppdragsnr:",1000,999999);


			for (int j=0; j<MAXSONE;j++)
			{
				if (sonene[j]==NULL)
				{
					//cout << "Neinei, denne finnes ikke.";
				}
				else 
				{
					//cout << "Display some";
					sonene[j]->display_some(postnr);
					ok=true;
				}
				
			}
			if (!ok) cout << "\nSoeket fant ingen poster.";
			return 0;
		};

int Soner::kommando_e(char k)
		{
	char kommando;

	cout << "\nSonebase - Eiendom";
	kommando = les();

	
		switch (kommando) {
		case 'D':   display_more(kommando);
			break;
		case 'N':	nyEiendom_v();
			break;
		case 'S':	slettEiendom();
			break;
		case 'E':	endreEiendom();
			break;
		default:	;
			break;
		}

	
	

	return 0;

};

int Soner::kommando(char k)
		{
	char kommando;

	cout << "\nSonebase";
	kommando = les();

	
		switch (kommando) {
		case 'D':   display(kommando);
			break;
		case 'S':	;
			break;
		case 'K':	;
			break;
		case 'U':	;
			break;
		default:	;
			break;
		}

	
	

	return 0;

};

void Soner::endreEiendom(){ // Endrer alt om en eiendom
	int oppdnr = les("\nOppdragsnummer", MAXPOST, sisteOppdrag);
	for (int i = 1; i <= MAXSONE; i++)
	
	{if (sonene[i]==NULL)
				{
					//cout << "Neinei, denne finnes ikke.";
				}
				else 
		if (sonene[i]->slett(oppdnr)){
			sonene[i]->nyEiendom(oppdnr);
			
		}
	
	}

}

void Soner::slettEiendom()
		{
			
			int tmpint;
			tmpint=les("Velg oppdragsnummer:",10000,999999);
			for (int j=0; j<MAXSONE;j++)
			{
				if (sonene[j]==NULL)
				{
					//cout << "Neinei, denne finnes ikke.";
				}
				else 
					if (sonene[j]->slett(tmpint))skrivTilEnFil(j);

				


			}

			//skrivTilFil();
			// skriver alle soner til fil, mulig det er litt overkill;
			
		
		};


void Soner::nyEiendom_v() 
		{
			int nr;
			nr=les("Velg sone:",1,100);
 	      if (finnesSone(nr))
		  {
		   nyEiendom(nr);
	      }
	else 
	{
		nySone(nr);
		nyEiendom(nr);
	}
};