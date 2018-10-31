#ifndef DIBUJANTE_H_
#define DIBUJANTE_H_

#include "Tablero.h"
#include "MapaDeBits.h"

class Dibujante {

	private:

		Tablero* tablero;
		unsigned int anchoDeImagen;
		unsigned int altoDeImagen;
		unsigned int anchoDeFicha;
		unsigned int altoDeFicha;
		unsigned int cantidadDeImagenesCreadas;

	public:
		/* POST: crea un dibujante listo para crear imagenes de 'tablero' de
		 * 		 dimension 'ancho' x 'alto'.
		 */
		Dibujante(Tablero *tablero, unsigned int ancho, unsigned int alto);

		/* POST: crea una imagen del tablero en el directorio donde fue ejecutado
		 * 		 el programa.
		 */
		void dibujarTablero();


	private:

		/* POST: dibuja las fichas de la columna en la imagen. */
		void dibujar(Columna* columna, MapaDeBits* imagen);

		/* POST: dibuja la ficha en la imagen */
		void dibujar(Ficha* ficha, MapaDeBits* imagen);

};

#endif /* DIBUJANTE_H_ */
