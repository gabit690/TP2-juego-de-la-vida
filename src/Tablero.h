#ifndef TABLERO_H_
#define TABLERO_H_

#include "Parcela.h"
#include <string>

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
		Tablero(std::string  unNombre, unsigned int cantidadDeColumnas, unsigned int cantidadDeFilas);

		/* PRE: 'numeroDeColumna' pertenece al intervalo [1, contarColumnas()].
		 * 		'numeroDeFila' pertenece al intervalo [1, contarFilas()].
		 * POST: devuelve la parcela de la posicion indicada.
		 */
		Parcela* obtenerParcela(unsigned int numeroDeColumna, unsigned numeroDeFila);

		/* POST: devuelve la cantidad de columnas del tablero */
		unsigned int contarColumnas();

		/* POST: devuelve la cantidad de filas del tablero */
		unsigned int contarFilas();

		/* pre: -.
		 * post: devuelve el nombre del tablero.
		 */
		std::string obtenerNombre();

		/* PRE: 'numeroDeColumna' pertenece al intervalo (0, contarColumnas()]
		 * y 'numeroDeFila' pertenece al intervalo (0, contarFilas()]
		 * POST: Devuelve la cantidad de vecinas vivas de la parcela ubicada en ( numeroDeColumna, numeroDeFila)
		 */
		unsigned int obtenerCantidadDeVecinasVivas(unsigned int numeroDeColumna, unsigned int numeroDeFila);

		/* PRE: numeroDeColumna' pertenece al intervalo (0, contarColumnas()]
		 * y 'numeroDeFila' pertenece al intervalo (0, contarFilas()]
		 * POST: Indica si existe la parcela cuya posicion es (numeroDeColumna, numeroDeFila).
		 */
		bool existeLaParcela(unsigned int numeroDeColumna, unsigned int numeroDeFila);

		/* POST: libera los recursos utilizados */
		~Tablero();
};

#endif /* TABLERO_H_ */
