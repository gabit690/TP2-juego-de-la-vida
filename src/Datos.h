/*
 * Datos.h
 *
 *  Created on: 1 nov. 2018
 *      Author: santicouce
 */

#ifndef DATOS_H_
#define DATOS_H_

#include <string>

class Datos{

private:
	std::string nombre,tipoPortal;
	int red,green,blue,x1,y1,x2,y2,cantidadFilas,cantidadColumnas,totalCelulasVivas;

public:
	Datos();
	Lista<algo> /*(o donde sea que guarde los daos)*/ getDatosIniciales(string ruta);
	int getCantidadFilas();
	int getCantidadColumnas();
	int getTotalCelulasVivas();


};


#endif /* DATOS_H_ */
