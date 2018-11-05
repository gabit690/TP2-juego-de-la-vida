/*
 * main.cpp
 *
 *  Created on: 1 nov. 2018
 *      Author: santicouce
 */

#include "JuegoDeLaVida.h"

int main(){
	JuegoDeLaVida* elJuego;
	elJuego = new JuegoDeLaVida();
	elJuego->jugar();
	delete elJuego;
	return 0;
}
