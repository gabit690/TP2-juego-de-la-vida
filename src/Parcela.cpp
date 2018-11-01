/*
 * Parcela.cpp
 *
 *  Created on: 28 oct. 2018
 *      Author: giu-altamirano
 */

#include "Parcela.h"
#include "Portal.h"
#include "Celula.h"

Parcela::Parcela(Celula celula, Portal portal, Color color) {
	this->celula = celula;
	this->portal = portal;
	this->color = color;

}

void Parcela::cambiarColor(Color nuevoColor){
	this->color = nuevoColor;
}

void Parcela::cambiarPortal(Portal nuevoPortal){
	this->portal = nuevoPortal;
}

Color Parcela::obtenerColor(){
	return color;
}

Celula Parcela::obtenerCelula(){
	return celula;
}

Portal Parcela::obtenerPortal(){
	return Portal;
}

Parcela::~Parcela() {
	// TODO Auto-generated destructor stub
}
