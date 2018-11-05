/*
 * Portal.h
 *
 *  Created on: 31 oct. 2018
 *      Author: santicouce
 */

#ifndef PORTAL_H_
#define PORTAL_H_

#include <string>
#include "Parcela.h"

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
	private:
		TipoDePortal tipo;
		std::string taberoOrigen;
		std::string taberoDestino;
		Parcela* parcelaOrigen;
		Parcela* parcelaDestino;

	public:
		/* Pre: -.
		 * Post: un portal que conecta los tableros nombreTableroOrigen y nombreTableroDestino.
		 */
		Portal(std::string nombreTableroOrigen, std::string nombreTableroDestino,
				Parcela* origen, Parcela* destino, TipoDePortal tipo);

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
		 * Post: obtiene el nombre del tablero origen que conecta.
		 */
		std::string getNombreTableroOrigen();

		/* Pre: -.
		 * Post: obtiene el nombre del tablero destino que conecta.
		 */
		std::string getNombreTableroDestino();

		/* Pre: -.
		 * Post: obtiene la parcela origen del portal.
		 */
		Parcela* getParcelaOrigen();

		/* Pre: -.
		 * Post: obtiene la parcela destino del portal.
		 */
		Parcela* getParcelaDestino();
};



#endif /* PORTAL_H_ */
