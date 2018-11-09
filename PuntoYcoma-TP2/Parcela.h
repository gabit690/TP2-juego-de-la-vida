

#include "Celula.h"
#include "Color.h"
#include "Portal.h"

#ifndef PARCELA_H_
#define PARCELA_H_

class Parcela {

	private:

		Color* color;
		Celula* celula;
		float tasaDeNatalidad;
		float tasaDeMortalidad;

	public:

		/* PRE: -.
		 * POST: una parcela que contiene una celula muerta, ningun portal
		 * y tiene como color blanco por defecto.
		 */
		Parcela();

		/* PRE: rojo, verde y azul estan en el intervalo [0, 255].
		 * POST: se cambia el color de la parcela.
		 */
		void setearColorDeParcela(ebmpBYTE rojo, ebmpBYTE verde, ebmpBYTE azul);

		/* PRE: -.
		 * POST: obtiene el color de la parcela.
		 */
		Color* obtenerColor();

		/* PRE: -.
		 * POST: obtiene la celula dentro de la parcela.
		 * y azul.
		 */
		Celula* obtenerCelula();

		/* PRE: -.
		 * POST: indica si la celula contenida en la parcela se encuentra viva.
		 */
		bool contieneCelulaViva();

		/* PRE: tasaDeNatalidad un entero del intervalo [0, 100].
		 * POST: establece la tasa de natalidad de la parcela.
		 */
		void setTasaDeNatalidad(float tasaDeNatalidad);

		/* PRE: -.
		 * POST: obtiene la tasa de natalidad.
		 */
		float getTasaDeNatalidad();

		/* PRE: tasaDeMortalidad un entero del intervalo [0, 100].
		 * POST: establece la tasa de mortalidad de la parcela.
		 */
		void setTasaDeMortalidad(float tasaDeMortalidad);

		/* PRE: -.
		 * POST: obtiene la tasa de mortalidad.
		 */
		float getTasaDeMortalidad();

		/* PRE: -.
		 * POST: libera la memoria solicitada.
		 */
		~Parcela();
};

#endif /* PARCELA_H_ */
