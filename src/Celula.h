/*
;
 * Celula.h
 *
 *  Created on: 1 nov. 2018
 *      Author: santicouce
 */

#ifndef CELULA_H_
#define CELULA_H_

#include "Color.h"
#include "Energia.h"

enum EstadoDeLaCelula {
	MUERTA,
	PORVIVIR,
	VIVA,
	PORMORIR,
};

/* Unidad basica que compone un organismo.
 * Su condicion esta representada por un tipo de dato enumerado
 * que puede variar entre:
 * 	 MUERTA: una celula sin vida.
 *	 PORVIVIR: una celula sin vida que esta apunto de revivir.
 *	 VIVA: una celula con vida.
 *	 PORMORIR: una celula con vida que esta apunto de morir.
 */
class Celula{

	private:
		EstadoDeLaCelula condicion;
		Energia* energia;
		Color* color;

	public:

		/* Pre: -.
		 * Post: Se inicializa una celula con la condicion MUERTA, 0% de energia
		 * cuyo color es blanco que representa una celula muerta.
		 */
		Celula();

		/* PRE: La condicion de la celula es MUERTA.
		 * POST: La celula esta PORVIVIR.
		 */
		void reanimarCelula();

		/* PRE: La condicion de la celula es PORVIVIR.
		 * POST: La celula esta VIVA.
		 */
		void revivirCelula();

		/* PRE: La condicion de la celula es VIVA.
		 * POST: La celula esta PORMORIR.
		 */
		void infectarCelula();

		/* PRE: La condicion de la celula es PORMORIR.
		 * POST: La celula esta MUERTA.
		 */
		void matarCelula();

		/* PRE: -.
		 * POST: Devuelve true si la celula esta muerta.
		 */
		bool estaMuerta();

		/* PRE: -.
		 * POST: Devuelve true si la celula esta por revivir.
		 */
		bool estaPorRevivir();

		/* PRE: -.
		 * POST: Devuelve true si la celula esta viva.
		 */
		bool estaViva();

		/* PRE: -.
		 * POST: Devuelve true si la celula esta por morir.
		 */
		bool estaPorMorir();

		/* PRE: rojo, verde y azul estan en el intervalo [0, 255].
		 * POST: asigna el nuevo color formado por la combinacion
		 * de rojo, verde y azul.
		 */
		void cambiarColorDeLaCelula(ebmpBYTE rojo, ebmpBYTE verde, ebmpBYTE azul);

		/* PRE: nuevaEnergia esta en el intervalo [0, 100].
		 * POST: setea el nuevo nivel de energia.
		 */
		void cambiarNuevaEnergia(unsigned int nuevaEnergia);

		/* PRE: -.
		 * POST: Devuelve de color de la celula.
		 */
		Color* getColor();

		/* PRE: La condicion de la celula es VIVA.
		 * POST: Se reinicia una celula con la condicion MUERTA.
		 */
		void reiniciarCelula();

		/* PRE: -.
		 * POST: Libera la memoria pedida.
		 */
		~Celula();
};


#endif /* CELULA_H_ */
