#ifndef ENERGIA_H_
#define ENERGIA_H_

const int ENERGIA = 100;
const int SIN_ENERGIA = 0;

/*
 * La energía es aquella que se manifiesta a la hora de nacer o morir una célula.
 * Se mide la cantidad en el intervalor [0,100].
 */

class Energia{

	private:

		float energiaTotal;

	public:

		/* Pre: -.
		 * Post: energia esta seteada con 0 de cantidad.
		 */
		Energia();

		/* pre: valor>0;
		 * post: aumenta el nivel de energia segun valor pero no supera la cantidad 100.
		 */
		void sumarEnergia(float valor);

		/* pre: valor>0;
		 * post: disminuye el nivel de energia segun valor pero no baja de la cantidad 0.
		 */
		void restarEnergia(float valor);


		/* pre: -.
		 * post: devuelve la cantidad de energia.
		 */
		float obtenerCantidadDeEnergia();
};

#endif /* ENERGIA_H_ */
