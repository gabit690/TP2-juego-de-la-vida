/*
 * Jugador.cpp
 *
 *  Created on: 1 nov. 2018
 *      Author: santicouce
 */

/*
#include "Tablero.h"
#include "Informe.h"
#include "Parcela.h"
#include "Jugador.h"
#include "Datos.h" //hay que hacerla, claro.
#include "Celula.h"

 Jugador::Jugador();

 void Jugador::IniciarPartida(){

	//Se toman los datos
	//Aca Datos deberia leer el archivo que le pasan y almacenar esos datos en algun lado dentro de la clase.
	DatosIniciales.getDatosIniciales();

	//Se crea el tablero diamico.
	tablero(DatosIniciales.getCantidadFilas,DatosIniciales.getCantidadColumnas);

	//For que saque las parcelas de algun lugar y las cargue al tablero
	{
		tablero.cargarParcelaAlTablero(parcela,x,y);
	}

	//Ya quedo el tablero dinamico creado, con las parcelas cargadas.

	//Ahora hay que actualizar los datos en Informe.

	InformeDeLaPartida.setCelulasVivas(DatosIniciales->totalCelulasVivas);
	//setear todos los datos de InformeDeLaPartida con sus primitivas.

}

 void Jugador::JugarUnTurno(){

	 int cantidadColumnas=DatosIniciales.getCantidadColumnas();
	 int cantidadFilas=DatosIniciales.getCantidadColumnas();

	 for (int i=0;i<cantidadColumnas;i++){
		for (int j=0;j<cantidadColumnas;j++){
			int vecinosVivos=getCantidadAdyacentesVivos(&tablero,i,j,cantidadColumnas,cantidadFilas);
			if ((tablero[i][j]->obtenerCelula()->getEstadoActual=="viva" && (vecinosVivos==2 or vecinosVivos==3)) or (tablero[i][j]->obtenerCelula()->estadoActual=="muerta" && vecinosVivos==3)){
				tablero[i][j]->obtenerCelula()->setProximoEstado("viva");
				if (tablero[i][j]->obtenerCelula()->estado=="muerta" and tablero[i][j]->obtenerCelula()->proximoEstado="viva"){
					InformeDelJuego->nacimientosEnUltimoTurno++;
					InformeDelJuego->cantidadCelulasVivas++;
				}
			}else{

				tablero[i][j]->obtenerCelula()->proximoEstado="muerta";

				if (tablero[i][j]->obtenerCelula()->estado=="viva"){
					InformeDelJuego->muertesEnUltimoTurno++;
					InformeDelJuego->cantidadCelulasVivas--;
				}

			}
		}
	}

	//actualizarEstadoDeCelulas(); tablero[i][j]->estadoActual=tablero[i][j]->proximoEstado;
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
*/


