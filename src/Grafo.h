/*
 * Grafo.h
 *
 *  Created on: 29 nov. 2018
 *      Author: gabit
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#include "Vertice.h"
#include "Arista.h"
#include "Pila.h"

class Grafo {

private:
	Lista<Vertice*>* vertices;
	Lista<Arista*>* aristas;

public:

	/* Pre: .
	 * Post: crea un grafo sin vertices ni aristas.
	 */
	Grafo();

	/* Pre: -.
	 * Post: crea un vertice con el nombre indicado y lo agrega a los vertices existentes en el grafo.
	 */
	void agregarUnVertice(std::string nombre);

	/* Pre: -.
	 * Post: crea una arista que va del origen hasta el destino indicado y la agrega a las aristas existentes en el grafo.
	 */
	void agregarUnaArista(std::string origen, std::string destino, Portal* unPortal);

	/* Pre: -.
	 * Post: devuelve los vertices del grafo.
	 */
	Lista<Vertice*>* obtenerVertices();

	/* Pre: -.
	 * Post: devuelve las aristas del grafo.
	 */
	Lista<Arista*>* obtenerAristas();

	/* Pre: 'origen' y 'destino' son los identificadores de dos vertices del grafo.
	 * Post:
	 */
	Pila<std::string>* obtenerElCaminoMinimo(std::string origen, std::string destino, unsigned int &transferenciaTotal);

	/* Pre: -.
	 * Post: vacia la lista de vertices y aristas que conforman el grafo.
	 */
	void reiniciarGrafo();

	/* Pre: -.
	 * Post: devuelve el vertice identificado por nombre.
	 */
	Vertice* buscarVertice(std::string nombre);

	/* Pre: -.
	 * Post: devuelve la arista que parte de origen y va a destino.
	 */
	Arista* buscarArista(std::string origen, std::string destino, Portal* unPortal);

	/* Pre: -;
	 * Post: libera los recursos de memoria pedidos.
	 */
	~Grafo();

private:
	/* Pre: El grafo tiene vertices y aristas.
	 * Post: los vertices tienen vinculadas las aristas que lo tienen como
	 * origen.
	 */
	void setearAristasAdyacentes();

	/* Pre: 'unVertice' esta inicializado.
	 * Post: el vertice tiene acceso a sus aristas adyacentes.
	 */
	void guardarAristasAdyacentes(Vertice* unVertice);

	/* Pre: 'origen' y 'destino' son los identificadores de dos vertices del grafo.
	 * Post: etiqueta todos los vertices del grafo.
	 */
	void etiquetarVertices(std::string origen, std::string destino);

	/* Pre: pesoDeLaArista >= 0.
	 * Post: etiqueta el vertice destino de una arista.
	 */
	void  etiquetarDestino(Vertice* inicio, Vertice* llegada, unsigned int pesoDeLaArista, std::string destino);

	/* Pre: -.
	 * Post: apila todas las aristas adyacentes al vertices duenio de la lista de aristas.
	 */
	void apilarAristasDelVertice(Pila<Arista*>* segmentosAnalizados, Lista<Arista*>* aristas);

	/* Pre: -.
	 * Post: vacia la lista de vertices liberando la memoria pedida para cada uno de ellos.
	 */
	void liberarVertices();

	/* Pre: -.
	 * Post: vacia la lista de aristas liberando la memoria pedida para cada una de ellas.
	 */
	void liberarAristas();

	/* Pre: 'origen' y 'destino' son los identificadores de dos vertices del grafo.
	 * Post: apila los vertices que permiten el camino minimo buscado previamente.
	 */
	void armarCaminoMinimo(Pila<std::string>* caminoMinimo, std::string origen, std::string destino, unsigned int &transferenciaTotal);
};

#endif /* GRAFO_H_ */
