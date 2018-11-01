/*
 * Jugador.cpp
 *
 *  Created on: 1 nov. 2018
 *      Author: santicouce
 */

#include "Tablero.h"
#include "Informe.h"
#include "Parcela.h"
#include "Jugador.h"
#include "Datos.h" //hay que hacerla, claro.

 Jugador::Jugador();

 void Jugador::IniciarPartida(){

	//Se toman los datos
	//Aca Datos deberia leer el archivo que le pasan y almacenar esos datos en algun lado dentro de la clase.
	DatosIniciales.getDatosIniciales();

	//Se crea el tablero diamico.
	Tablero tablero1(DatosIniciales.getCantidadFilas,DatosIniciales.getCantidadColumnas);

	//For que saque las parcelas de algun lugar y las cargue al tablero
	{
		tablero1.cargarParcelaAlTablero(parcela,x,y);
	}

	//Ya quedo el tablero dinamico creado, con las parcelas cargadas.

	//Ahora hay que actualizar los datos en Informe.

	DatosDeLaPartida.setCelulasVivas(DatosIniciales->celulasVivas);
	//setear todos los datos de DatosDeLaPartida con sus primitivas.

}

int Jugador::getCantidadAdyacentesVivos(Tablero* tablero, int columna,int fila, int cantidadFilas,int cantidadColumnas){


	int topeFila, inicioColumna,topeColumna,inicioFila,celulasVivas;

	inicioColumna=columna-1;
	inicioFila=fila-1;
	topeColumna=columna+2;
	topeFila=fila+2;

	for(inicioColumna;inicioColumna<topeColumna;inicioColumna++){
		for(inicioFila;inicioFila<topeFila;inicioFila++){
			if ((inicioFila>=0 && inicioFila<cantidadFilas) && (inicioColumna>=0 && inicioColumna<cantidadColumnas) && not(inicioColumna==columna && inicioFila==fila)){
				if (tablero[inicioFila][inicioColumna]->contieneCelulaViva()){
					celulasVivas++;
				}
			}
		}
		topeFila=fila+2;
		inicioFila=fila-1;
	}
	return celulasVivas;
}



