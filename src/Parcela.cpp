/*
 * Parcela.cpp
 *
 *  Created on: 28 oct. 2018
 *      Author: giu-altamirano
 */

#include "Parcela.h"


Parcela::Parcela(){
	this->celula = new Celula();
	this->portal = NULL;
	this->color = new Color(255, 255, 255);

}

void Parcela::setearColorDeParcela(ebmpBYTE rojo, ebmpBYTE verde, ebmpBYTE azul){
	this->color->asignarRojo(rojo);
	this->color->asignarVerde(verde);
	this->color->asignarAzul(azul);
}

void Parcela::setPortal(Portal* unPortal){
	this->portal = unPortal;
}

Color* Parcela::obtenerColor(){
	return this->color;
}

Celula* Parcela::obtenerCelula(){
	return this->celula;
}

Portal* Parcela::obtenerPortal(){
	return this->portal;
}

bool Parcela::contieneCelulaViva(){
	return (this->celula->estaViva());
}

Parcela::~Parcela() {
	delete this->celula;
	delete this->color;
	if(this->portal!=NULL){
		delete this->portal;
	}
}

