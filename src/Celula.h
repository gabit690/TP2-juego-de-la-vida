/*
;
 * Celula.h
 *
 *  Created on: 1 nov. 2018
 *      Author: santicouce
 */

#ifndef CELULA_H_
#define CELULA_H_

#include <string>
#include "Color.h"
#include "Energia.h"
#include "Celula.h"
using namespace std;

class Celula{

private:

	Energia energia;
	string estadoActual;
	string proximoEstado;
	Color color;

public:

	Celula(bool estadoInicial,Energia energiaInicial,Color colorInicial);
	void cambiarEstadoDeLaCelula();
	void cambiarColorDeLaCelula(Color nuevoColor);
	void cambiarEnergia(Energia nuevaEnergia);
	void setProximoEstado(string estado);
	void setEstadoActual(string estado);
	string getEstadoActual();
	string getProximoEstado();
	Celula* crearCopiaDeLaCelula(Celula* celulaACopiar);
	~Celula();

};


#endif /* CELULA_H_ */
