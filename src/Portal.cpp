/*
 * Portal.cpp
 *
 *  Created on: 31 oct. 2018
 *      Author: santicouce
 */

#include "Portal.h"
using namespace std;

Portal::Portal(string nombreTableroOrigen, string nombreTableroDestino,
				Parcela* origen, Parcela* destino, TipoDePortal tipo){

	this->taberoOrigen = nombreTableroOrigen;
	this->taberoDestino = nombreTableroDestino;
	this->parcelaOrigen = origen;
	this->parcelaDestino = destino;
	this->tipo = tipo;
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

string Portal::getNombreTableroOrigen(){
	return this->taberoOrigen;
}

string Portal::getNombreTableroDestino(){
	return this->taberoDestino;
}

Parcela* Portal::getParcelaOrigen(){
	return this->parcelaOrigen;
}

Parcela* Portal::getParcelaDestino(){
	return this->parcelaDestino;
}
