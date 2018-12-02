/*
 * Arista.cpp
 *
 *  Created on: 29 nov. 2018
 *      Author: gabit
 */

#include "Arista.h"
using namespace std;

Arista::Arista(){
	this->portalVinculado = NULL;
	this->origen = "";
	this->destino = "";
	this->peso = 0;
}

void Arista::setOrigen(string nombre){
	this->origen = nombre;
}

void Arista::setDestino(string nombre){
	this->destino = nombre;
}

void Arista::setPortalVinculado(Portal* unPortal){
	this->portalVinculado = unPortal;
}

Portal* Arista::getPortalVinculado(){
	return this->portalVinculado;
}

void Arista::aumentarUnidadApeso(){
	this->peso++;
}

string Arista::getOrigen(){
	return this->origen;
}

string Arista::getDestino(){
	return this->destino;
}

unsigned int Arista::getPeso(){
	return this->peso;
}
