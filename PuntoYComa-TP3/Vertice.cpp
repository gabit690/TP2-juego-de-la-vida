/*
 * Vertice.cpp
 *
 *  Created on: 29 nov. 2018
 *      Author: gabit
 */

#include "Vertice.h"
using namespace std;

Vertice::Vertice(std::string nombre){
	this->identificador = nombre;
	this->suEtiqueta = new Etiqueta();
	this->aristasAdyacentes = new Lista<Arista*>();
}

void Vertice::compararEtiqueta(unsigned int nuevaDistanciaAcumulada, string elementoAnterior){

	Etiqueta* etiquetaDelVertice;
	etiquetaDelVertice = this->getEtiqueta();
	unsigned int acumulacionDeEtiquetaDelVertice = this->suEtiqueta->getAcumulacion();
	bool cambiar = (acumulacionDeEtiquetaDelVertice > nuevaDistanciaAcumulada )||(!this->estaEtiquetada());

	if(cambiar){

		etiquetaDelVertice->setAcumulacion(nuevaDistanciaAcumulada);
		etiquetaDelVertice->setAnterior(elementoAnterior);
		etiquetaDelVertice->aumentarNumeroDeOperacion();
	}
}

void Vertice::agregarAristaAdyacente(Arista* unaArista){
	this->aristasAdyacentes->agregar(unaArista, this->aristasAdyacentes->contarElementos()+1);
}

bool Vertice::tieneAristasAdayacentes(){
	return (!this->getAdyacentes()->estaVacia());
}

Etiqueta* Vertice::getEtiqueta(){
	return this->suEtiqueta;
}

Lista<Arista*>* Vertice::getAdyacentes(){
	return this->aristasAdyacentes;
}

string Vertice::getIdentificador(){
	return this->identificador;
}

bool Vertice::estaEtiquetada(){
	return (this->suEtiqueta->getAnterior().compare("")!=0);
}

Vertice::~Vertice(){
	delete this->suEtiqueta;
	delete this->aristasAdyacentes;
}
