/*
 * Informe.cpp
 *
 *  Created on: 31 oct. 2018
 *      Author: gabit
 */

#include "Informe.h"

Informe::Informe() {
	this->turno = 0;
	this->celulasVivas = 0;
	this->nacimientos = 0;
	this->nacimientosTotales = 0;
	this->muertes = 0;
	this->muertesTotales = 0;
	this->turnosSeguidosSinCambios = 0;
}

void Informe::aumentarUnTurno(){
	this->turno++;
}

void Informe::setCelulasVivas(int valor){
	this->celulasVivas = valor;
}

void Informe::setNacimientos(int valor){
	this->nacimientos = valor;
}

void Informe::aumentarNacimientosTotales(int valor){
	this->nacimientosTotales+=valor;
}

void Informe::setMuertes(int valor){
	this->muertes = valor;
}

void Informe::aumentarMuertesTotales(int valor){
	this->muertesTotales+=valor;
}

void Informe::actualizaCambios(){
	bool hayCambios = (this->nacimientos!=0)||(this->muertes!=0);
	if(!hayCambios){
		this->turnosSeguidosSinCambios++;
	}else{
		this->turnosSeguidosSinCambios = 0;
	}
}

bool Informe::juegoCongelado(){
	return (this->turnosSeguidosSinCambios==2);
}
Informe::~Informe() {
	// No hace falta ya que no se pidieron recursos.
}

