/*
 * Portal.h
 *
 *  Created on: 31 oct. 2018
 *      Author: santicouce
 */

#ifndef PORTAL_H_
#define PORTAL_H_

#include <string>

/*
 * Clasificacion de los diferentes tipos de portal que podran modificar las
 * celulas que se encuentran en el mismo ya sea que tengan que nacer o morir.
 * Los tipos son:
 * ACTIVO: su influencia es bidireccional de origen a destino y viceversa.
 * NORMAL: su influencia es unidireccional de origen a destino
 * PASIVO: solo influye en nacimientos de origen a destino.
 */
enum TipoDePortal{
	ACTIVO,
	NORMAL,
	PASIVO,
};

/*
 * Interconecta dos parcelas de tableros distintos
 * en las cuales podra modificar el estado de la celula
 */
class Portal{
	public:
		TipoDePortal tipo;
		std::string taberoOrigen;
		std::string taberoDestino;

	private:
		/* Pre: -.
		 * Post: un portal que conecta los tableros nombreTableroOrigen y nombreTableroDestino.
		 * Esta seteado como un portal del tipo NORMAL
		 */
		Portal(std::string nombreTableroOrigen, std::string nombreTableroDestino);

		/* Pre: -.
		 * Post: cambia el tipo de portal a ACTIVO.
		 */
		void cambiarAportalActivo();

		/* Pre: -.
		 * Post: cambia el tipo de portal a PASIVO.
		 */
		void cambiarAportalPasivo();

		/* Pre: -.
		 * Post: indica si el portal es del tipo ACTIVO.
		 */
		bool esPortalActivo();

		/* Pre: -.
		 * Post: indica si el portal es del tipo NORMAL.
		 */
		bool esPortalNormal();

		/* Pre: -.
		 * Post: indica si el portal es del tipo PASIVO.
		 */
		bool esPortalPasivo();

		/* Pre: -.
		 * Post: obtine el nombre del tablero origen que conecta.
		 */
		std::string getNombreTableroOrigen();

		/* Pre: -.
		 * Post: obtine el nombre del tablero destino que conecta.
		 */
		std::string getNombreTableroDestino();
};



#endif /* PORTAL_H_ */
