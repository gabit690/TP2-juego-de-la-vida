/*
 * Enfermero.h
 *
 *  Created on: 2 nov. 2018
 *      Author: gabit
 */

#ifndef ENFERMERO_H_
#define ENFERMERO_H_

#include "Lista.h"
#include "Tablero.h"
#include "Informe.h"
#include "Portal.h"

class Enfermero {

	public:

		/* PRE: Existen tableros para ser analizados.
		 * POST: cambia temporalmente el estado de la celulas de los tableros en base
		 * a sus vecinas que tiene alrededor y a los portales existentes.
		 */
		void evaluarCelulas(Lista<Tablero*>* losTableros, Lista<Portal*>* losPortales);

		/* PRE: unTablero existente en el juego.
		 * POST: modifica temporalmente el estado de las celulas del tablero que seran actualizadas.
		 */
		void evaluarUnTablero(Tablero* unTablero);

		/* PRE: Existen tableros para ser analizados.
		 * POST: modifica definitivamente el estado de las celulas de los tableros.
		 */
		void actualizarCelulas(Lista<Tablero*>* losTableros, Informe* losInformes);

		/* PRE: unTablero existente en el juego.
		 * POST: modifica definitivamente el estado de las celulas de un tablero
		 * y acumula los nacimientos y muertes en el mismo.
		 */
		void actualizarUnTablero(Tablero* unTablero, unsigned int &muertesEnElTurno, unsigned int &nacimientosEnElTurno);

		/* PRE: nacimientosEnELTurno y muertesEnELTurno >= 0.
		 * POST: realiza los cambios en losInformes de los nuevos valores obtenidos en un turno.
		 */
		void actualizarInformes(Informe* losInformes, unsigned int &muertesEnElTurno, unsigned int &nacimientosEnElTurno);

	private:

		/* PRE: unPortal es un portal existente en el juego.
		 * POST: aplica el efecto que genera unPortal en las celulas vinculadas por el
		 * mismo.
		 */
		void aplicarEfectoDelPortal(Portal* unPortal);

		/* PRE: celulaOrigen y celulaDestino son 2 celulas dentro de un tablero del juego.
		 * POST: aplica el efecto de un portal Activo a las celulas vinculadas.
		 */
		void aplicarEfectoActivo(Celula* celulaOrigen, Celula* celulaDestino);

		/* PRE: celulaOrigen y celulaDestino son 2 celulas dentro de un tablero del juego.
		 * POST: aplica el efecto de un portal Normal a las celulas vinculadas.
		 */
		void aplicarEfectoNormal(Celula* celulaOrigen, Celula* celulaDestino);

		/*PRE: celulaOrigen y celulaDestino son 2 celulas dentro de un tablero del juego.
		 * POST: aplica el efecto de un portal Pasivo a las celulas vinculadas.
		 */
		void aplicarEfectoPasivo(Celula* celulaOrigen, Celula* celulaDestino);

		/*PRE: celulaModelo y celulaAmodificar son 2 celulas dentro de un tablero del juego.
		 * POST: copia el estado de celulaModelo a celulaAmodificar.
		 */
		void copiarEstadoEntreCelulas(Celula* celulaModelo, Celula* celulaAmodificar);

		/* PRE: unTablero existente en el juego, columna y fila representa una posicion dentro del tablero y
		 * unaCelula es la celula ubicada en dicha posicion.
		 * POST: le asigna a unaCelula el color promedio de sus celulas vecinas en unTablero.
		 */
		void asignarColorPromedio(Tablero* unTablero,unsigned int columna, unsigned int  fila, Celula* unaCelula);
};

#endif /* ENFERMERO_H_ */
