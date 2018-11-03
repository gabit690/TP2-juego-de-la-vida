#ifndef TABLERO_H_
#define TABLERO_H_



#include "Parcela.h"
#include "Lista.h"


/*
 * Matriz bidimensional que sera la encargada de contener los elementos del juego.
 */
class Tablero {

	private:

		Parcela*** casilleros;
		std::string nombre;
		unsigned int cantidadDeFilas;
		unsigned int cantidadDeColumnas;

	public:

		/* Pre: cantidadDeFilas y cantidadDeColumnas son mayores a 0.
		 * POST: crea un tablero con el nombre y las dimensiones indicadas.
		 */
		Tablero(std::string  unNombre, unsigned int cantidadDeFilas, unsigned int cantidadDeColumnas);

		/* PRE: 'numeroDeColumna' pertenece al intervalo [1, contarColumnas()].
		 * 		'numeroDeFila' pertenece al intervalo [1, contarFichas(numeroDeColumna)].
		 * POST: devuelve la parcela de la posicion indicada.
		 */
		Parcela* obtenerParcela(unsigned int numeroDeColumna, unsigned numeroDeFila);

		/* POST: devuelve la cantidad de columnas del tablero */
		unsigned int contarColumnas();

		/* POST: devuelve la cantidad de filas del tablero */
		unsigned int contarFilas();

		/* pre: -.
		 * post: indica el nombre del tablero.
		 */
		std::string obtenerNombre();

		/* PRE: 'numeroDeColumna' pertenece al intervalo [1, contarColumnas()].
		 * 		'numeroDeFila' pertenece al intervalo [1, contarFichas(numeroDeColumna)].
		 * POST: Devuelve una lista con las celulas vecinas de la parcela solicitada.
		 */
		Lista<Parcela*>* obtenerVecinas(unsigned int numeroDeFila, unsigned int numeroDeColumna);

		/* POST: libera los recursos utilizados */
		~Tablero();

};

#endif /* TABLERO_H_ */
