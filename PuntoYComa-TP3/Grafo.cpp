/*
 * Grafo.cpp
 *
 *  Created on: 29 nov. 2018
 *      Author: gabit
 */

#include "Grafo.h"
using namespace std;

Grafo::Grafo() {
	this->vertices = new Lista<Vertice*>();
	this->aristas = new Lista<Arista*>();
}

void Grafo::agregarUnVertice(std::string nombre){
	Vertice* nuevoVertice = new Vertice(nombre);
	this->vertices->agregar(nuevoVertice, this->vertices->contarElementos()+1);
}

void Grafo::agregarUnaArista(string origen, string destino, Portal* unPortal){
	Arista* nuevaArista = new Arista();
	nuevaArista->setOrigen(origen);
	nuevaArista->setDestino(destino);
	nuevaArista->setPortalVinculado(unPortal);
	this->aristas->agregar(nuevaArista, this->aristas->contarElementos()+1);
}

Lista<Vertice*>* Grafo::obtenerVertices(){
	return this->vertices;
}

Lista<Arista*>* Grafo::obtenerAristas(){
	return this->aristas;
}


Pila<string>* Grafo::obtenerElCaminoMinimo(string origen, string destino, unsigned int &transferenciaTotal){

	Pila<string>* caminoMinimo = new Pila<string>();

	this->setearAristasAdyacentes();

	this->etiquetarVertices(origen, destino);

	this->armarCaminoMinimo(caminoMinimo, origen, destino, transferenciaTotal);

	return caminoMinimo;
}

void Grafo::etiquetarVertices(string origen, string destino){

	Vertice* unVertice;
	Pila<Arista*>* segmentosAnalizados = new Pila<Arista*>();

	unVertice = this->buscarVertice(origen);
	unVertice->getEtiqueta()->setAnterior("Ninguna"); // etiqueto el origen para diferenciarlo de un vertice no etiquetado.

	if(unVertice->tieneAristasAdayacentes()){
		this->apilarAristasDelVertice(segmentosAnalizados, unVertice->getAdyacentes());
	}

	while(!segmentosAnalizados->estaVacia()){
		Arista* unaArista;
		unaArista = segmentosAnalizados->desapilar();
		unsigned int pesoDeLaArista = unaArista->getPeso();
		Vertice* inicio;
		inicio = this->buscarVertice(unaArista->getOrigen());
		Vertice* llegada;
		llegada = this->buscarVertice(unaArista->getDestino());

		if(llegada->tieneAristasAdayacentes() && !llegada->estaEtiquetada()){
			this->apilarAristasDelVertice(segmentosAnalizados, llegada->getAdyacentes());
		}

		etiquetarDestino(inicio, llegada, pesoDeLaArista,destino);
	}
	delete segmentosAnalizados;
}

void Grafo::etiquetarDestino(Vertice* inicio, Vertice* llegada, unsigned int pesoDeLaArista, string destino){
	unsigned int distanciaAcumulada = (inicio->getEtiqueta()->getAcumulacion()+pesoDeLaArista);


	string elementoAnterior = inicio->getIdentificador();

	bool etiquetar = !((distanciaAcumulada==0)&&(llegada->getIdentificador().compare(destino)==0));

	if(etiquetar){
		llegada->compararEtiqueta(distanciaAcumulada, elementoAnterior);
	}
}

void Grafo::apilarAristasDelVertice(Pila<Arista*>* segmentosAnalizados, Lista<Arista*>* aristas){
	aristas->iniciarCursor();
	while(aristas->avanzarCursor()){
		Arista* unaArista;
		unaArista = aristas->obtenerCursor();
		segmentosAnalizados->apilar(unaArista);
	}
}

void Grafo::armarCaminoMinimo(Pila<string>* caminoMinimo, string origen , string destino, unsigned int &transferenciaTotal){

	Vertice* unVertice;
	unVertice = buscarVertice(destino);
	Etiqueta* etiquetaDelVertice;

	etiquetaDelVertice = unVertice->getEtiqueta();
	transferenciaTotal = etiquetaDelVertice->getAcumulacion();

	bool terminar = false;

	while(!terminar){

		string elementoAnterior = etiquetaDelVertice->getAnterior();

		terminar = (elementoAnterior.compare("")==0)||(unVertice->getIdentificador().compare(origen)==0);

		if(!terminar){
			caminoMinimo->apilar(unVertice->getIdentificador());
			unVertice = buscarVertice(elementoAnterior);
			etiquetaDelVertice = unVertice->getEtiqueta();
		}
	}

	if(!caminoMinimo->estaVacia()){
		caminoMinimo->apilar(origen);
	}
}

Vertice* Grafo::buscarVertice(string nombre){
	Vertice* buscado;
	bool encontrado = false;

	this->vertices->iniciarCursor();
	while(this->vertices->avanzarCursor()&&!encontrado){
		Vertice* unVertice;
		unVertice = this->vertices->obtenerCursor();
		encontrado = (unVertice->getIdentificador().compare(nombre)==0);
		if(encontrado){
			buscado = unVertice;
		}
	}
	return buscado;
}

Arista* Grafo::buscarArista(string origen, string destino, Portal* unPortal){
	Arista* buscada;
	bool encontrado = false;

	this->aristas->iniciarCursor();
	while(this->aristas->avanzarCursor()&&!encontrado){
		Arista* unaArista;
		unaArista = this->aristas->obtenerCursor();
		encontrado = ((unaArista->getOrigen().compare(origen)==0)&&(unaArista->getDestino().compare(destino)==0))&&(unPortal == unaArista->getPortalVinculado());
		if(encontrado){
			buscada = unaArista;
		}
	}
	return buscada;
}

void Grafo::liberarVertices(){
	while(!this->vertices->estaVacia()){
		Vertice* removido;
		removido = this->vertices->obtener(1);
		this->vertices->remover(1);
		delete removido;
	}
}

void Grafo::liberarAristas(){

	while(!this->aristas->estaVacia()){
		Arista* removido;
		removido = this->aristas->obtener(1);
		this->aristas->remover(1);
		delete removido;
	}

}

void Grafo::setearAristasAdyacentes(){

	this->vertices->iniciarCursor();
	while(this->vertices->avanzarCursor()){
		Vertice* unVertice;
		unVertice = this->vertices->obtenerCursor();
		guardarAristasAdyacentes(unVertice);
	}
}

void Grafo::guardarAristasAdyacentes(Vertice* unVertice){
	string nombreDelVertice = unVertice->getIdentificador();
	this->aristas->iniciarCursor();
	while(this->aristas->avanzarCursor()){
		Arista* unaArista;
		unaArista = this->aristas->obtenerCursor();
		string nombreOrigen = unaArista->getOrigen();
		if(nombreOrigen.compare(nombreDelVertice) == 0){
			unVertice->agregarAristaAdyacente(unaArista);
		}
	}
}

void Grafo::reiniciarGrafo(){
	this->liberarAristas();
	this->liberarVertices();
}

Grafo::~Grafo(){
	this->liberarAristas();
	delete this->aristas;
	this->liberarVertices();
	delete this->vertices;
}
