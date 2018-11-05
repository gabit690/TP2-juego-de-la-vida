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
 * que lo componen durante una partida del Juego de la Vida.
 */
class Dibujante {

	private:
		unsigned int medidaDeUnaParcelaCuadrada;

	public:
		/* PRE: -.
		 * POST: crea un dibujante listo para crear imagenes de una lista de
		 * tableros.
		 */
		Dibujante();

		/* PRE: tunoDeJuego >0;.
		 * POST: crea imagenes de la lista de tableros;
		 */
		void dibujarTableros(Lista<Tablero*>* tableros, unsigned int turnoDeJuego);

		/* Pre: unTablero es un tablero inicializado y tunoDeJuego >0;
		 * Post: Crea una imagen de unTablero y la guarda como formato .BMP.
		 */
		void dibujarUnTablero(Tablero* unTablero, unsigned int tunoDeJuego);

	private:

		/* Pre: unTablero es un tablero inicializado;
		 * Post: Dibuja dentro de imagen todos los elementos que conforman el tablero.
		 */
		void dibujarContenidoDelTablero(Tablero* unTablero, MapaDeBits* imagen);

		/* Pre: unaImagen es un mapa de bits inicializado, ancho>0, alto>0.
		 * Post: dibuja en unaImagen una cuadricula.
		 */
		void dibujarCuadricula(MapaDeBits* unaImagen, unsigned int ancho, unsigned int alto);

		/* Pre: pixelX y pixelY representan un pixel de imagen.
		 * POST: dibuja la parcela ubicada en (pixelX, pixelY).
		 */
		void dibujarUnaParcela(Color* colorDeParcela, MapaDeBits* imagen, unsigned int pixelX, unsigned int pixelY);

		/* Pre: pixelX y pixelY representan un pixel de imagen.
		 * POST: dibuja la Celula ubicada en (pixelX, pixelY).
		 */
		void dibujarUnaCelula(Color* colorDeCelula, MapaDeBits* imagen, unsigned int pixelX, unsigned int pixelY);

		/* Pre: pixelX y pixelY representan un pixel de imagen. tamanioPixel>0.
		 * Post: dibuja la parte superior de la celula con un borde negro.
		 */
		void dibujarParteSuperiorDeCelula(Color* colorDeCelula, MapaDeBits* imagen, unsigned int pixelX,
										unsigned int pixelY, unsigned int tamanioPixel, Color* borde);

		/* Pre: pixelX y pixelY representan un pixel de imagen. tamanioPixel>0..
		 * Post: dibuja la parte del medio de la celula con un borde negro.
		 */
		void dibujarParteMediaDeCelula(Color* colorDeCelula, MapaDeBits* imagen, unsigned int pixelX,
										unsigned int pixelY, unsigned int tamanioPixel, Color* borde);

		/* Pre: pixelX y pixelY representan un pixel de imagen. tamanioPixel>0..
		 * Post: dibuja la parte inferior de la celula con un borde negro.
		 */
		void dibujarParteInferiorDeCelula(Color* colorDeCelula, MapaDeBits* imagen, unsigned int pixelX,
										unsigned int pixelY, unsigned int tamanioPixel, Color* borde);

		/* pre: desdeX>=0, hastaX>=0,  desdeY>=0, hastaY>=0.
		 * post: Dibuja una seccion rectangular en la imagen determinada.
		 */
		void dibujarEnAnchoYalto(Color* unColor, MapaDeBits* imagen, unsigned int desdeX,
									unsigned int hastaX, unsigned int desdeY, unsigned int hastaY);

};

#endif /* DIBUJANTE_H_ */
