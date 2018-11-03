/*
 * Jugador.h
 *
 *  Created on: 1 nov. 2018
 *      Author: santicouce
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

class Jugador{
private:
	Informe InformeDeLaPartida;
//	Datos DatosIniciales;
	Tablero tablero;

public:
	Jugador();
	void IniciarPartida();
	void JugarUnTurno();
	int getCantidadAdyacentesVivos(Tablero* tablero, int columna,int fila, int cantidadFilas,int cantidadColumnas);
};



#endif /* JUGADOR_H_ */
