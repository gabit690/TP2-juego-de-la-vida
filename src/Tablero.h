#ifndef TABLERO_H_
#define TABLERO_H_

#include "Columna.h"
#include "Ficha.h"

class Tablero {

	private:

		unsigned int cantidadDeFilas;
		unsigned int cantidadDeColumnas;
		unsigned int cantidadDeFichas;
		Columna** columnas;

	public:

		/* POST: crea un tablero sin fichas de las dimensiones indicadas*/
		Tablero(unsigned int cantidadDeFilas, unsigned int cantidadDeColumnas);

		/* PRE: el tablero no esta lleno.
		 * POST: agrega la ficha al tablero.
		 */
		void agregar(Ficha* nuevaFicha);

		/* PRE: 'ficha' existe en el tablero.
		 * POST: elimina del tablero la ficha de ubicada en el numero de fila
		 * 		 y numero de columna indicados.
		 */
		void remover(Ficha* ficha);

		/* PRE: 'numeroDeColumna' pertenece al intervalo [1, contarColumnas()].
		 * 		'numeroDeFila' pertenece al intervalo [1, contarFichas(numeroDeColumna)].
		 * POST: devuelve la ficha de la posicion indicada.
		 */
		Ficha* obtenerFicha(unsigned int numeroDeFila, unsigned int numeroDeColumna);

		/* POST: devuelve la cantidad de columnas del tablero */
		unsigned int contarColumnas();

		/* POST: devuelve la cantidad de filas del tablero */
		unsigned int contarFilas();

		/* POST: devuelve la cantidad de fichas de la columna indicada */
		unsigned int contarFichas(unsigned int numeroDeColumna);

		/* POST: indica si se completaron con fichas todas las columnas del
		 * 		 tablero.
		 */
		bool estaLleno();

		/* POST: indica si el tablero se encuentra sin ninguna ficha. */
		bool estaVacio();

		/* PRE: numero de columna es un entero entre 1 y contarColumnas().
		 * POST: devuelva la columna indicada.
		 */
		Columna* obtenerColumna(unsigned int numeroDeColumna);

		/* POST: indica si existe una ficha ubicada en la posicion ingresada */
		bool existeFichaEn(Vector* posicion);

		/* PRE: existe una ficha en dicha posicion.
		 * POST: devuelve la ficha de la posicion.
		 */
		Ficha* obtenerFicha(Vector* posicion);

		/* PRE: 'ficha' existe en el tablero.
		 * POST: agrega a 'fichasVecinas' las fichas vecinas encontradas.
		 */
		void obtenerVecinas(Ficha* ficha, Lista<Ficha*>* fichasVecinas);

		/* POST: libera los recursos utilizados */
		~Tablero();


	private:

		/* POST: Devuelve un puntero a un vector de punteros de columnas vacias.
		 * 		 El tamanio del vector es de cantidadDeColumnas y la altura
		 * 		 maxima de las columnas es de cantidadDeFilas.
		 */
		Columna** crearColumnas(unsigned int cantidadDeFilas,
								unsigned int cantidadDeColumnas);

		void acomodarFichasCaidas(unsigned int fila, unsigned int columna);

		/* PRE: desde y hasta no son constantes.
		 * POST: desde y hasta toman los valores valor - rango y valor + rango
		 * 		 siempre que dados valores no sobrepasen los limites
		 * 		 limiteInferior y limiteSuperior respectivamente.
		 * 		 En tal caso adoptan el valor del limite.
		 */
		void ajustarRango(unsigned int valor, unsigned int &desde,
						  unsigned int &hasta, unsigned int limiteInferior,
						  unsigned int limiteSuperior, unsigned int rango);

};

#endif /* TABLERO_H_ */
