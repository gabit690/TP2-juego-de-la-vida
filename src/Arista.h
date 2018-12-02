/*
 * Arista.h
 *
 *  Created on: 29 nov. 2018
 *      Author: gabit
 */

#ifndef ARISTA_H_
#define ARISTA_H_

#include <string>
#include "Portal.h"

/* Seccion que vincula dos vertices.
 * Tiene un sentido determinado por el vertice de origen hacia el vertice destino
 * y guarda el peso de las transacciones entre ambos vertices.
 */
class Arista {
private:

	Portal* portalVinculado;
	std::string origen;
	std::string destino;
	unsigned int peso;

public:
	/* Pre: -.
	 * Post: una arista sin origen y destino con peso 0.
	 */
	Arista();

	/* Pre: -.
	 * Post: la arista tiene a 'nombre' como origen.
	 */
	void setOrigen(std::string nombre);

	/* Pre: -.
	 * Post: la arista tiene a 'nombre' como destino.
	 */
	void setDestino(std::string nombre);

	/* Pre: -.
	 * Post: la arista se vincula con unPortal.
	 */
	void setPortalVinculado(Portal* unPortal);

	/* Pre: -.
	 * Post: devuelve el portal al cual esta vinculada.
	 */
	Portal* getPortalVinculado();

	/* Pre: -.
	 * Post: el peso aumenta una unidad.
	 */
	void aumentarUnidadApeso();

	/* Pre: -.
	 * Post: devuelve el identificador del origen de la arista.
	 */
	std::string getOrigen();

	/* Pre: -.
	 * Post: devuelve el identificador del destino de la arista.
	 */
	std::string getDestino();

	/* Pre: -.
	 * Post: devuelve el ipeso de la arista.
	 */
	unsigned int getPeso();
};

#endif /* ARISTA_H_ */
