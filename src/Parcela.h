/*
 * Parcela.h
 *
 *  Created on: 28 oct. 2018
 *      Author: giu-altamirano
 */
#include "Celula.h"
#include "Color.h"
#include "Portal.h"

#ifndef PARCELA_H_
#define PARCELA_H_

class Parcela {

private:

	Color* color;
	Celula* celula;
	Portal* portal;

public:

	/* PRE: -.
	 * POST: una parcela que contiene una celula muerta, ningun portal
	 * y tiene como color blanco por defecto.
	 */
	Parcela();

	/* PRE: rojo, verde y azul estan en el intervalo [0, 255].
	 * POST: se cambiar el color de la parcela.
	 */
	void setearColorDeParcela(ebmpBYTE rojo, ebmpBYTE verde, ebmpBYTE azul);

	/* pre: unPortal es un dato de tipo portal inicializado como ACTIVO, PASIVO
	 * o NORMAL.
	 * post: asigna a la parcela el portal unPortal.
	 */
	void setPortal(Portal* unPortal);

	/* PRE: rojo, verde y azul estan en el intervalo [0, 255].
	 * POST: asigna el nuevo color formado por la combinacion de rojo, verde
	 * y azul.
	 */
	Color* obtenerColor();

	/* PRE: rojo, verde y azul estan en el intervalo [0, 255].
	 * POST: asigna el nuevo color formado por la combinacion de rojo, verde
	 * y azul.
	 */
	Celula* obtenerCelula();

	/* PRE: rojo, verde y azul estan en el intervalo [0, 255].
	 * POST: asigna el nuevo color formado por la combinacion de rojo, verde
	 * y azul.
	 */
	Portal* obtenerPortal();

	/* PRE: -.
	 * POST: indica si la celula contenida en la parcela se encuentra viva.
	 */
	bool contieneCelulaViva();

	/* PRE: -.
	 * POST: libera la memoria solicitada.
	 */
	~Parcela();
};

#endif /* PARCELA_H_ */
