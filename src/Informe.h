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
	int turno;
	int celulasVivas;
	int nacimientos;
	int nacimientosTotales;
	int muertes;
	int muertesTotales;
	int turnosSeguidosSinCambios;

public:

	//PRE: -.
	//POST: Se inicializa un informe.
	Informe();

	//PRE: informes inicializados.
	//POST: Se aumenta en una unidad el contador de turnos.
	void aumentarUnTurno();

	//PRE: valor es un numero positivo.
	//POST: se registran "valor" de celulas vivas.
	void setCelulasVivas(int valor);

	//PRE: valor es un numero positivo.
	//POST: se registran "valor" de nacimientos.
	void setNacimientos(int valor);

	//PRE: valor es un numero positivo.
	//POST: Aumenta el acumulador de nacimientos totales en "valor".
	void aumentarNacimientosTotales(int valor);

	//PRE: valor es un numero positivo.
	//POST: se registran "valor" de muertes.
	void setMuertes(int valor);

	//PRE: valor es un numero positivo.
	//POST: Aumenta el acumulador de muertes totales en "valor".
	void aumentarMuertesTotales(int valor);

	//PRE: informes inicializados.
	//POST: controla si se produjeron cambios en el tablero.
	void actualizaCambios();

	//PRE: informes inicializados.
	//POST: Devuelve true si el juego no se modifico en dos turnos consecutivos.
	bool juegoCongelado();

	//PRE: .
	//POST: No produce modificaciones.
	~Informe();
};

#endif /* INFORME_H_ */
