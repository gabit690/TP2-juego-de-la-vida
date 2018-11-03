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

	public:
		/* PRE: -.
		 * POST: crea un dibujante listo para crear imagenes de una lista de
		 * tableros.
		 */
		Dibujante();

		/* PRE: medidaDeParcela mayor a 0.
		 * POST: crea imagenes de la lista de tableros;
		 */
		void dibujarTableros(Lista<Tablero*>* tableros, unsigned int medidaDeParcela);

		/* pre:-.
		 * post: elimina la informacion de todos los dibujos creados.
		 */
		void reiniciarDibujante();

//	private:

		/* Pre: unTablero es un tablero inicializado y medidaDeParcela >0;
		 * Post: Crea una imagen de unTablero y la guarda como formato .BMP.
		 */
		void dibujarUnTablero(Tablero* unTablero,unsigned int medidaDeParcela);

		/* Pre: unTablero es un tablero inicializado y medidaDeParcela >0;
		 * Post: Dibuja dentro de imagen todos los elementos que conforman el tablero.
		 */
		void dibujarContenidoDelTablero(Tablero* unTablero, MapaDeBits* imagen,unsigned int medidaDeParcela);

		/* Pre: unaImagen es un mapa de bits inicializado, ancho>0, alto>0 y medidaDeParcela >0.
		 * Post: dibuja en unaImagen una cuadricula.
		 */
		void dibujarCuadricula(MapaDeBits* unaImagen, unsigned int ancho, unsigned int alto, unsigned int medidaDeParcela);

		/* POST: dibuja las fichas de la columna en la imagen. */
		void dibujarUnaParcela(Color* colorDeParcela, MapaDeBits* imagen, unsigned int pixelX, unsigned int pixelY, unsigned int medidaDeParcela);

		/* POST: dibuja la ficha en la imagen */
		void dibujarUnaCelula(Color* colorDeCelula, MapaDeBits* imagen, unsigned int pixelX, unsigned int pixelY, unsigned int medidaDeParcela);

		/* pre:
		 * post:
		 */
		void dibujarEnAnchoYalto(Color* unColor, MapaDeBits* imagen, unsigned int desdeX,
									unsigned int hastaX, unsigned int desdeY, unsigned int hastaY);

		~Dibujante();
};

#endif /* DIBUJANTE_H_ */
