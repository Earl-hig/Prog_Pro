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

	while {