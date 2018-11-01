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
	Color color;
	Celula celula;
	Portal portal;

public:
	Parcela(Color color, Celula celula, Portal portal);
	virtual ~Parcela();

	void Parcela::cambiarColor(Color nuevoColor);

	void Parcela::cambiarPortal(Portal nuevoPortal);

	Color Parcela::obtenerColor();

	Celula Parcela::obtenerCelula();

	Portal Parcela::obtenerPortal();

	bool Parcela::contieneCelulaViva();


};

#endif /* PARCELA_H_ */
