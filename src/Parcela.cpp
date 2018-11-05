/*
 * Parcela.cpp
 *
 *  Created on: 28 oct. 2018
 *      Author: giu-altamirano
 */

#include "Parcela.h"

Parcela::Parcela(){
	this->celula = new Celula();
	this->color = new Color(255, 255, 255);
	this->tasaDeNatalidad = 0;
	this->tasaDeMortalidad = 0;
}

void Parcela::setearColorDeParcela(ebmpBYTE rojo, ebmpBYTE verde, ebmpBYTE azul){
	this->color->asignarRojo(rojo);
	this->color->asignarVerde(verde);
	this->color->asignarAzul(azul);
}

Color* Parcela::obtenerColor(){
	return this->color;
}

Celula* Parcela::obtenerCelula(){
	return this->celula;
}

bool Parcela::contieneCelulaViva(){
	return (this->celula->estaViva());
}

void Parcela::setTasaDeNatalidad(float tasaDeNatalidad){
	this->tasaDeNatalidad = tasaDeNatalidad;
}

float Parcela::getTasaDeNatalidad(){
	return tasaDeNatalidad;
}

void Parcela::setTasaDeMortalidad(float tasaDeMortalidad){
	this->tasaDeMortalidad = tasaDeMortalidad;
}

float Parcela::getTasaDeMortalidad(){
	return tasaDeMortalidad;
}

Parcela::~Parcela() {
	delete this->celula;
	delete this->color;
}
