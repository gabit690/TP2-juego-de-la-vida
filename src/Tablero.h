#ifndef TABLERO_H_
#define TABLERO_H_

#include "Parcela.h"

class Tablero {

	private:

		int cantidadDeFilas;
		int cantidadDeColumnas;
		Parcela** tablero;

	public:

		Tablero( int cantidadDeFilas, int cantidadDeColumnas);

		void cargarParcelaAlTablero(Parcela parcela, int x,int y);

		unsigned int contarColumnas();
		Parcela obtenerParcela(unsigned int numeroDeFila, unsigned int numeroDeColumna);
		unsigned int contarFilas();
		Lista<Parcela>* obtenerVecinas(unsigned int numeroDeFila, unsigned int numeroDeColumna);

		~Tablero();
};

#endif /* TABLERO_H_ */
