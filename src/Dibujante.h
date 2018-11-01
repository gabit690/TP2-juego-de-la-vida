/*
 * Dibujante.h
 *
 *  Created on: 1 nov. 2018
 *      Author: gabit
 */

#ifndef DIBUJANTE_H_
#define DIBUJANTE_H_

#include "Lista.h"
#include "Tablero.h"
#include "MapaDeBits.h"

/*
 * Se encarga de generar un archivo .BMP que representa un tablero con los elementos
 * que lo componen durante una partida del Juego de la Vida
 */
class Dibujante {

	private:

		Lista<MapaDeBits*>* dibujos;
		unsigned int medidaDeUnaParcelaCuadrada;
		unsigned int cantidadDeImagenesCreadas;

	public:
		/* PRE: medidaDeParcela mayor a 0.
		 * POST: crea un dibujante listo para crear imagenes de una lista de
		 * tableros;
		 */
		Dibujante();

		/* PRE: medidaDeParcela mayor a 0.
		 * POST: crea imagenes de la lista de tableros;
		 */
		void dibujarTableros(Lista<Tablero*>* tablero, unsigned int medidaDeParcela);


	private:

		/* POST: dibuja las fichas de la columna en la imagen. */
		void dibujarUnaParcela(Parcela* unaParcela, MapaDeBits* imagen);

		/* POST: dibuja la ficha en la imagen */
		void dibujarUnaCelula(Celula* unaCelula, MapaDeBits* imagen);

		~Dibujante();
};

#endif /* DIBUJANTE_H_ */
