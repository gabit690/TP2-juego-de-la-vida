/*
 * Portal.cpp
 *
 *  Created on: 31 oct. 2018
 *      Author: santicouce
 */

#include "Portal.h"

Portal::Portal(std::string nombreTableroOrigen, std::string nombreTableroDestino){
	this->tipo = NORMAL;
	this->taberoOrigen = nombreTableroOrigen;
	this->taberoDestino = nombreTableroDestino;
}

void Portal::cambiarAportalActivo(){
	this->tipo = ACTIVO;
}

void Portal::cambiarAportalPasivo(){
	this->tipo = PASIVO;
}

bool Portal::esPortalActivo(){
	return (this->tipo==ACTIVO);
}

bool Portal::esPortalNormal(){
	return (this->tipo==NORMAL);
}

bool Portal::esPortalPasivo(){
	return (this->tipo==PASIVO);
}

std::string Portal::getNombreTableroOrigen(){
	return this->taberoOrigen;
}

std::string Portal::getNombreTableroDestino(){
	return this->taberoDestino;
}
