/*
 * Celula.cpp
 *
 *  Created on: 6 sep. 2018
 *      Author: gabit
 */

#import "Celula.h"

void inicializarCelula(Celula &unaCelula){
	unaCelula.condicion = MUERTA;
}

void reanimarCelula(Celula &unaCelula){
	unaCelula.condicion = PORVIVIR;
}

void revivirCelula(Celula &unaCelula){
	unaCelula.condicion = VIVA;
}

void infectarCelula(Celula &unaCelula){
	unaCelula.condicion = PORMORIR;
}

void matarCelula(Celula &unaCelula){
	unaCelula.condicion = MUERTA;
}

bool estaMuerta(Celula &unaCelula){
	return (unaCelula.condicion==MUERTA);
}

bool estaPorRevivir(Celula &unaCelula){
	return (unaCelula.condicion==PORVIVIR);
}

bool estaViva(Celula &unaCelula){
	return (unaCelula.condicion==VIVA);
}

bool estaPorMorir(Celula &unaCelula){
	return (unaCelula.condicion==PORMORIR);
}

void reiniciarCelula(Celula &unaCelula){
	if(unaCelula.condicion==VIVA){
		unaCelula.condicion = MUERTA;
	}
}
