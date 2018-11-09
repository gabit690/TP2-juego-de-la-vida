
#ifndef CELULA_H_
#define CELULA_H_

#include "Color.h"
#include "Energia.h"

enum EstadoDeLaCelula {
	MUERTA,
	PORVIVIR,
	VIVA,
	PORMORIR,
};

/* Unidad basica que compone un organismo.
 * Su condicion esta representada por un tipo de dato enumerado
 * que puede variar entre:
 * 	 MUERTA: una celula sin vida.
 *	 PORVIVIR: una celula sin vida que esta apunto de revivir.
 *	 VIVA: una celula con vida.
 *	 PORMORIR: una celula con vida que esta apunto de morir.
 */
class Celula{

	private:
		EstadoDeLaCelula condicion;
		Energia* energia;
		Color* color;

	public:

		/* Pre: -.
		 * Post: Se inicializa una celula con la condicion MUERTA, 0% de energia
		 * cuyo color es blanco que representa una celula muerta.
		 */
		Celula();

		/* PRE: La condicion de la celula es MUERTA.
		 * POST: La celula esta PORVIVIR.
		 */
		void reanimarCelula();

		/* PRE: La condicion de la celula es PORVIVIR.
		 * POST: La celula esta VIVA.
		 */
		void revivirCelula();

		/* PRE: La condicion de la celula es VIVA.
		 * POST: La celula esta PORMORIR.
		 */
		void infectarCelula();

		/* PRE: La condicion de la celula es PORMORIR.
		 * POST: La celula esta MUERTA.
		 */
		void matarCelula();

		/* PRE: -.
		 * POST: Indica si la celula esta muerta.
		 */
		bool estaMuerta();

		/* PRE: -.
		 * POST: Indica si la celula esta por revivir.
		 */
		bool estaPorRevivir();

		/* PRE: -.
		 * POST: Indica si la celula esta viva.
		 */
		bool estaViva();

		/* PRE: -.
		 * POST: Indica si la celula esta por morir.
		 */
		bool estaPorMorir();

		/* PRE: rojo, verde y azul estan en el intervalo [0, 255].
		 * POST: asigna el nuevo color formado por la combinacion
		 * de rojo, verde y azul.
		 */
		void cambiarColorDeLaCelula(ebmpBYTE rojo, ebmpBYTE verde, ebmpBYTE azul);

		/* PRE: nuevaEnergia >0 .
		 * POST: aumenta el nivel de energia segun nuevaEnergia pero nunca mas de 100.
		 */
		void aumentarEnergia(float nuevaEnergia);

		/* PRE: nuevaEnergia >0 .
		 * POST: reduce el nivel de energia segun nuevaEnergia pero nunca menos de 0.
		 */
		void reducirEnergia(float nuevaEnergia);

		/* PRE: -.
		 * POST: Devuelve el color de la celula.
		 */
		Color* getColor();

		/* PRE: -.
		 * POST: Libera la memoria pedida.
		 */
		~Celula();
};


#endif /* CELULA_H_ */
