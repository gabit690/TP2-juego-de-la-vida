/*
 * Interfaz.cpp
 *
 *  Created on: 31 oct. 2018
 *      Author: gabit
 */

#include "Interfaz.h"
#include <iostream>
using namespace std;

void mostrarBienvenida(){
	cout << "			";
	cout << "Bienvenido al 'Juego de la vida 2.0'." << endl << endl;
}

void pedirEleccionDeUnaFila(int &valorIngresado){
	cout << "Ingrese el numero de FILA donde quiere una celula viva o ingrese 0 para finalizar." << endl;
	cout << "Su respuesta: ";
	cin >> valorIngresado;
	cout << endl;
}

void pedirEleccionDeUnaColumna(int &valorIngresado){
	cout << "Ingrese el numero de COLUMNA donde quiere una celula viva o ingrese 0 para finalizar." << endl;
	cout << "Su respuesta: ";
	cin >> valorIngresado;
	cout << endl;
}

void mostrarErrorDatoInvalido(){
	cout << "El dato ingresado no es valido. ";
	cin.get();
	cout << endl << endl;
}

void mostrarErrorPosicionRepetida(){
	cout << "Ese casillero ya tiene una celula viva. ";
	cin.get();
	cout << endl;
}

void mostrarMenuDeJuego(){
	cout << "          ";
	cout << "MENU DE JUEGO." << endl;
	cout << "1. Ejecutar una cantidad de turnos a elegir." << endl;
	cout << "2. Reiniciar el juego." << endl;
	cout << "3. Terminar." << endl << endl;
}

void mostrarQueElJuegoSeCongelo(){
	cout << "El juego se ha congelado, es decir, no se modifico el tablero en dos turnos consecutivos";
	cin.get();
	cout << endl << endl;
}

void pedirEleccionDelMenuDeJuego(){
	cout << ">>> Elija una de las acciones." << endl;
	cout << "Su respuesta: ";
}

void pedirUnaCantidadDeTurnos(){
		cout << "Ingrese cuantos turnos quiere realizar." << endl;
		cout << "Su respuesta: ";
}

void mostrarInformesDelJuego(Informe* informes){
	cout << "INFORMES DEL TURNO NUMERO " << informes->getTurno() << endl;
	cout << "Celulas vivas: " << informes->getCelulasVivas() << endl;
	cout << "Nacimientos: " << informes->getNacimientos() << endl;
	float promedioDeNacimientos = ((float)informes->getNacimientosTotales()/(float)informes->getTurno());
	cout << "Promedio de nacimientos Totales: " << promedioDeNacimientos  << endl;
	cout << "Muertes: " << informes->getMuertes() << endl;
	float promedioDeMuertes = ((float)informes->getMuertesTotales()/(float)informes->getTurno());
	cout << "Promedio de muertes totales: " << promedioDeMuertes << endl << endl;
}

void mostrarCantidadDeCelulasVivas(Informe* informes){
	cout << "Celulas vivas: " << informes->getCelulasVivas()<< endl;
	cout << endl;
}

void mostrarFinalizacionDelJuego(){
	cout << "          ";
	cout << "Programa finalizado. Ciao";
	cin.get();
}
