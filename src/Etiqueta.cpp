/*
 * Etiqueta.cpp
 *
 *  Created on: 29 nov. 2018
 *      Author: gabit
 */

#include "Etiqueta.h"

Etiqueta::Etiqueta(){
	this->acumulacion = 0;
	this->elementoAnterior = "";
	this->numeroDeOperacion = 0;
}

void Etiqueta::setAcumulacion(unsigned int valor){
	this->acumulacion = valor;
}

void Etiqueta::setAnterior(std::string identificador){
	this->elementoAnterior = identificador;
}

void Etiqueta::aumentarNumeroDeOperacion(){
	this->numeroDeOperacion++;
}

unsigned int Etiqueta::getNumeroDeOperacion(){
	return this->numeroDeOperacion;
}

unsigned int Etiqueta::getAcumulacion(){
	return this->acumulacion;
}

std::string Etiqueta::getAnterior(){
	return this->elementoAnterior;
}
