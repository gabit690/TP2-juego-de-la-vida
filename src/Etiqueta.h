/*
 * Etiqueta.h
 *
 *  Created on: 29 nov. 2018
 *      Author: gabit
 */

#ifndef ETIQUETA_H_
#define ETIQUETA_H_

#include <string>
#include "Nodo.h"

/* Una etiqueta es un registro que guarda la relacion entre dos vertices de un grafo.
 * Contiene una cantidad acumulada de un camino recorrido y un identificador del elemento
 * anterior al vertice dueño de la etiqueta.
 */
class Etiqueta {

private:
	unsigned int acumulacion;
	std::string elementoAnterior;
	unsigned int numeroDeOperacion;

public:

	/* Pre: -.
	 * Post: etiqueta con 0 como acumulacion, no tiene registrado un elemento anterior y su
	 * numero de operacion es 0.
	 */
	Etiqueta();

	/* Pre: valor >=0.
	 * Post: la etiqueta tiene 'valor' como su acumulacion.
	 */
	void setAcumulacion(unsigned int valor);


	/* Pre: -.
	 * Post: 'identificador' es el elemento anterior al vertice dueño de la etiqueta.
	 */
	void setAnterior(std::string identificador);

	/* Pre: -.
	 * Post: aumenta en una unidad el numero de operacion.
	 */
	void aumentarNumeroDeOperacion();

	/* Pre: -.
	 * Post: devuelve el numero de operacion
	 */
	unsigned int getNumeroDeOperacion();


	/* Pre: -.
	 * Post: devuelve el valor de acumulacion.
	 */
	unsigned int getAcumulacion();


	/* Pre: -.
	 * Post: devuelve el identificador del vertice anterior al dueño de la etiqueta.
	 */
	std::string getAnterior();


};

#endif /* ETIQUETA_H_ */
