#ifndef MAPADEBITS_H_
#define MAPADEBITS_H_

#include "EasyBMP.h"
#include "Color.h"

class MapaDeBits {

	private:

		BMP* imagen;
		unsigned int alto;
		unsigned int ancho;

	public:

		/* PSOT: crea una imagen totalmente blanca de ancho x alto pixeles.
		 * 		 El origen de coordenadas se encuentra en el extremo inferior
		 * 		 izquierdo de la imagen.
		 */
		MapaDeBits(unsigned int ancho, unsigned int alto);

		/* POST: asigna al pixel ubicado en la (fila, columna) el color indicado.
		 */

		void asignar(unsigned int fila, unsigned int columna, Color* nuevoColor);

		/* POST: escribe la imagen con nombre 'nombreDeArchivo[version].bmp"
	 	 */
		void escribir(std::string nombreDeArchivo, unsigned int version);

		/* POST: libera los recursos utilizados.
		 */
		~MapaDeBits();

};

#endif /* MAPADEBITS_H_ */
