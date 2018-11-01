#ifndef TABLERO_H_
#define TABLERO_H_

#include "Parcela.h"
#include "Lista.h"

class Tablero {

	private:

		Parcela** matriz;
		unsigned int cantidadDeFilas;
		unsigned int cantidadDeColumnas;

	public:

		/* POST: crea un tablero de las dimensiones indicadas*/
		Tablero(unsigned int cantidadDeFilas, unsigned int cantidadDeColumnas);

		/* PRE: 'numeroDeColumna' pertenece al intervalo [1, contarColumnas()].
		 * 		'numeroDeFila' pertenece al intervalo [1, contarFichas(numeroDeColumna)].
		 * POST: devuelve la parcela de la posicion indicada.
		 */
		Parcela* obtenerParcela(unsigned int numeroDeFila, unsigned int numeroDeColumna);

		/* POST: devuelve la cantidad de columnas del tablero */
		unsigned int contarColumnas();

		/* POST: devuelve la cantidad de filas del tablero */
		unsigned int contarFilas();

		/* PRE: 'numeroDeColumna' pertenece al intervalo [1, contarColumnas()].
		 * 		'numeroDeFila' pertenece al intervalo [1, contarFichas(numeroDeColumna)].
		 * POST: Devuelve una lista con las celulas vecinas de la parcela solicitada.
		 */
		Lista<Parcela*>* obtenerVecinas(unsigned int numeroDeFila, unsigned int numeroDeColumna);

		//PRE: el tablero esta inicializado.
		//POST: deja el tablero lleno solo de celulas muertas.
		void reiniciarTablero();

		/* POST: libera los recursos utilizados */
		~Tablero();

};

#endif /* TABLERO_H_ */
