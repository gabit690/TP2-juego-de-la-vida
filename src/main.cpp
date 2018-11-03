/*
 * main.cpp
 *
 *  Created on: 1 nov. 2018
 *      Author: santicouce
 */
#include "Dibujante.h"
#include <iostream>

int main(){

	Dibujante* pinkcasso;
	pinkcasso = new Dibujante();
	Tablero* elTablero;
	elTablero = new Tablero("Principal", 3, 3);
	Lista<Tablero*>* cuaderno;
	cuaderno = new Lista<Tablero*>();
	cuaderno->agregar(elTablero);

	pinkcasso->dibujarUnTablero(elTablero, 30);


	delete pinkcasso;
	delete cuaderno;
	delete elTablero;

	return 0;
}



