#include <iostream>

using namespace std;

#include "const.h"
#include "funk.h"
#include "Soner.h"
#include "Kunder.h"

Kunder kundebase;
Soner sonebase;

int main() {
	
	char kommando;

	skrivMeny();

	kommando = les();

	while (kommando != 'Q') {
		switch(kommando) {
			case 'E': eiendomHandling(kommando);	break; 
			case 'S':			break;
			case 'K': kundeHandling(kommando);		break;
		}