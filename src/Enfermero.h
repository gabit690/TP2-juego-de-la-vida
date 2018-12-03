
#ifndef ENFERMERO_H_
#define ENFERMERO_H_

#include "Lista.h"
#include "Tablero.h"
#include "Informe.h"
#include "Portal.h"
#include "Grafo.h"

class Enfermero {

	public:

		/* PRE: Existen tableros para ser analizados.
		 * POST: cambia temporalmente el estado de la celulas de los tableros en base
		 * a sus vecinas que tiene alrededor.
		 */
		void evaluarCelulas(Lista<Tablero*>* losTableros);

		/* PRE: unTablero existente en el juego.
		 * POST: modifica temporalmente el estado de las celulas del tablero que seran actualizadas.
		 */
		void evaluarUnTablero(Tablero* unTablero);

		/* PRE: Existen tableros para ser analizados.
		 * POST: modifica definitivamente el estado de las celulas de los tableros.
		 */
		void actualizarCelulas(Lista<Tablero*>* losTableros, Lista<Portal*>* losPortales, Informe* losInformes, Grafo* elGrafo);

		/* PRE: Existen tableros para ser analizados.
		 * POST: modifica el color de las celulas en los tableros con el promedio de sus vecinas y aplica el efecto de los
		 * portales existentes contando las muertes y nacimientos que estas producen.
		 */
		void establecerColoresDeLasCelulas(Lista<Tablero*>* losTableros, Lista<Portal*>* losPortales, Grafo* elGrafo, unsigned int &muertesEnElTurno, unsigned int &nacimientosEnElTurno);

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
		void aplicarEfectoDelPortal(Portal* unPortal, Grafo* elGrafo, unsigned int &muertesEnElTurno, unsigned int &nacimientosEnElTurno);

		/* PRE: celulaOrigen y celulaDestino son 2 celulas dentro de un tablero del juego.
		 * POST: aplica el efecto de un portal Activo a las celulas vinculadas.
		 */
		void aplicarEfectoActivo(Celula* celulaOrigen, Celula* celulaDestino, Arista* aristaDeIda, Arista* aristaDeVuelta, unsigned int &muertesEnElTurno, unsigned int &nacimientosEnElTurno);

		/* PRE: celulaOrigen y celulaDestino son 2 celulas dentro de un tablero del juego.
		 * POST: aplica el efecto de un portal Normal a las celulas vinculadas.
		 */
		void aplicarEfectoNormal(Celula* celulaOrigen, Celula* celulaDestino, Arista* aristaDeIda, unsigned int &muertesEnElTurno, unsigned int &nacimientosEnElTurno);

		/*PRE: celulaOrigen y celulaDestino son 2 celulas dentro de un tablero del juego.
		 * POST: aplica el efecto de un portal Pasivo a las celulas vinculadas.
		 */
		void aplicarEfectoPasivo(Celula* celulaOrigen, Celula* celulaDestino, Arista* aristaDeIda, unsigned int &nacimientosEnElTurno);

		/*PRE: celulaModelo y celulaAmodificar son 2 celulas dentro de un tablero del juego.
		 * POST: aplica el efecto producida por la accion de un portal hacia la celula receptora de ese efecto.
		 */
		void modificarCelulaAfectada(Celula* celulaModelo, Celula* celulaAmodificar, unsigned int &muertesEnElTurno, unsigned int &nacimientosEnElTurno);

		/*PRE: unTablero es un tablero del juego.
		 * POST: le asigna un color a las celulas que naceran el siguiente turno.
		 */
		void setearColoresEnUnTablero(Tablero* unTablero);

		/* PRE: unTablero existente en el juego, columna y fila representa una posicion dentro del tablero y
		 * unaCelula es la celula ubicada en dicha posicion.
		 * POST: le asigna a unaCelula el color promedio de sus celulas vecinas en unTablero.
		 */
		void asignarColorPromedio(Tablero* unTablero,unsigned int columna, unsigned int  fila, Celula* unaCelula);
};

#endif /* ENFERMERO_H_ */
