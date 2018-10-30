#ifndef ENERGIA_H_
#define ENERGIA_H_

const int ENERGIA = 100;
const int SIN_ENERGIA = 0;

/*
 *La energía es aquella que se manifiesta a la hora de nacer o morir una célula en conjunto con el
 *factor de nacimiento o de muerte, respectivamente, que tenga la parcela en la que se encuentra la célula.
 */

class Energia{
	private:
		float energiaTotal;
		float factorNacimiento;
		float factorMuerte;

	public:
		/*
		 * pre: El constructor recibe el factor de nacimiento y el factor de muerte de la parcela en la
		 * que se encuentra la célula.
		 * post: la energía queda seteada de acuerdo a los factores de macimiento y de muerte de la parcela.
		 */
		Energia(float factorNacimientoParcela, float factorMuerteParcela);
		/*
		 * post: devuelve la cantidad de energía que se le va a sumar a la célula al momento de nacer
		 */
		float nacimientoCelular();
		/*
		 * post: devuelve la cantidad de energía que se le va a restar a la célula al momento de morir
		 */
		float muerteCelular();
		/*
		 * post: actualiza la energía de la célula al momento de nacer
		 */
		void sumarEnergia();
		/*
		 * post:  actualiza la energía de la célula al momento de morir
		 */
		void restarEnergia();

		~Energia();
};

#endif /* ENERGIA_H_ */
