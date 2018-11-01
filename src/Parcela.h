/*
 * Parcela.h
 *
 *  Created on: 28 oct. 2018
 *      Author: giu-altamirano
 */
//#include "Celula.h"
#include "Color.h"


#include "Portal.h"

#ifndef PARCELA_H_
#define PARCELA_H_

class Parcela {
private:
	Color color;
	Celula celula;
	std::string portal;

public:
	Parcela();
	Parcela(Color color, Celula celula, std::string portal);

	virtual ~Parcela();

	void Parcela::cambiarColor(Color nuevoColor);

	void Parcela::cambiarPortal(std::string nuevoPortal);

	Color Parcela::obtenerColor();

	Celula Parcela::obtenerCelula();

	std::string Parcela::obtenerPortal();


};

#endif /* PARCELA_H_ */
