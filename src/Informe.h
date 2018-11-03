/*
 * Informe.h
 *
 *  Created on: 31 oct. 2018
 *      Author: gabit
 */

#ifndef INFORME_H_
#define INFORME_H_

/* Registro de las diferentes instancias del juego para
 * generar los informes por pantalla.
 */
class Informe {

private:
	unsigned int turno;
	unsigned int celulasVivas;
	unsigned int nacimientos;
	unsigned int nacimientosTotales;
	unsigned int muertes;
	unsigned int muertesTotales;
	unsigned int turnosSeguidosSinCambios;

public:

	//PRE: -.
	//POST: Se inicializa un informe.
	Informe();

	//PRE: informes inicializados.
	//POST: Se aumenta en una unidad el contador de turnos.
	void aumentarUnTurno();

	//PRE: valor es un numero positivo.
	//POST: se registran "valor" de celulas vivas.
	void setCelulasVivas(unsigned int  valor);

	//PRE: valor es un numero positivo.
	//POST: se registran "valor" de nacimientos.
	void setNacimientos(unsigned int  valor);

	//PRE: valor es un numero positivo.
	//POST: Aumenta el acumulador de nacimientos totales en "valor".
	void aumentarNacimientosTotales(unsigned int valor);

	//PRE: valor es un numero positivo.
	//POST: se registran "valor" de muertes.
	void setMuertes(unsigned int valor);

	//PRE: -.
	//POST: obtiene la cantidad de turnos registrada.
	unsigned int getTurno();

	//PRE: -.
	//POST: obtiene la cantidad de celulas vivas registrada.
	unsigned int getCelulasVivas();

	//PRE: -.
	//POST: obtiene la cantidad de nacimientos registrada.
	unsigned int getNacimientos();

	//PRE: -.
	//POST: obtiene la cantidad de nacimientos totales registrada.
	unsigned int getNacimientosTotales();

	//PRE: -.
	//POST: obtiene la cantidad de muertes registrada.
	unsigned int getMuertes();

	//PRE: -.
	//POST: obtiene la cantidad de muertes totales registrada.
	unsigned int getMuertesTotales();

	//PRE: valor es un numero positivo.
	//POST: Aumenta el acumulador de muertes totales en "valor".
	void aumentarMuertesTotales(unsigned int valor);

	//PRE: informes inicializados.
	//POST: controla si se produjeron cambios en el tablero.
	void actualizaCambios();

	//PRE: informes inicializados.
	//POST: Devuelve true si el juego no se modifico en dos turnos consecutivos.
	bool juegoCongelado();

};

#endif /* INFORME_H_ */
