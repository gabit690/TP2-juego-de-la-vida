#ifndef COLOR_H_
#define COLOR_H_

#include "EasyBMP.h"
#include <cstdlib>

class Color {

	private:

		RGBApixel* colores;

	public:

		/* PRE: rojo, verde y azul son enteros entre 0 y 255, siendo
		 * 		0 ausencia de color y 255 color completo.
		 */
		Color(ebmpBYTE rojo, ebmpBYTE verde, ebmpBYTE azul);

		/* POST: crea un color en base a otro existente. */
		Color(Color* otroColor);

		/* POST: devuelve la cantidad de rojo*/
		ebmpBYTE obtenerRojo();

		/* POST: devuelve la cantidad de verde */
		ebmpBYTE obtenerVerde();

		/* POST: devuelve la cantida de azul */
		ebmpBYTE obtenerAzul();

		/* PRE: 'nuevoRojo' es un entero entre 0 y 255.
		 * POST: asigna el 'nuevoRojo' al color de la ficha.
		 */
		void asignarRojo(ebmpBYTE nuevoRojo);

		/* PRE: 'nuevoVerde' es un entero entre 0 y 255.
		 * POST: asigna el 'nuevoVerde' al color de la ficha.
		 */
		void asignarVerde(ebmpBYTE nuevoVerde);

		/* PRE: 'nuevoAzul' es un entero entre 0 y 255.
		 * POST: asigna el 'nuevoAzul' al color de la ficha.
		 */
		void asignarAzul(ebmpBYTE nuevoAzul);

		/* POST: devuelve un RGBApixel con los colores asociados */
		RGBApixel obtenerPixel();

		/* POST: asigna a sus colores un color aleatorio */
		void asignarColorAleatorio();

		/* Pre: unColor es un color de la escala RGB;
		 * Post: indica si se trata de los mismos colores
		 */
		bool sonLosMismosColores(Color* unColor);

		/* POST: libera los recursos utilizados */
		~Color();

};

#endif /* COLOR_H_ */
