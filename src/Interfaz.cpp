/*
 * Interfaz.cpp
 *
 *  Created on: 31 oct. 2018
 *      Author: gabit
 */

#include "Interfaz.h"
#include <iostream>
using namespace std;

Interfaz::Interfaz(){

}

void Interfaz::mostrarBienvenida(){
	cout << "			";
	cout << "Bienvenido al 'Juego de la vida 2.0'." << endl << endl;
}

void Interfaz::mostrarErrorDatoInvalido(){
	cout << "El dato ingresado no es valido (igual que Michetti).";
	cin.get();
	cout << endl << endl;
}

void Interfaz::mostrarMenuDeJuego(){
	cout << "          ";
	cout << "MENU DE JUEGO." << endl;
	cout << "1. Ejecutar una cantidad de turnos a elegir." << endl;
	cout << "2. Reiniciar el juego." << endl;
	cout << "3. Terminar." << endl << endl;
}

void Interfaz::mostrarQueElJuegoSeCongelo(){
	cout << "El juego se ha congelado, es decir, no se modifico el tablero en dos turnos consecutivos";
	cout << endl << endl;
}

void Interfaz::pedirEleccionDelMenuDeJuego(){
	cout << ">>> Elija una de las acciones." << endl;
	cout << "Su respuesta: ";
}

void Interfaz::pedirUnaCantidadDeTurnos(){
		cout << "Ingrese cuantos turnos quiere realizar." << endl;
		cout << "Su respuesta: ";
}

void Interfaz::mostrarInformesDelJuego(Informe* informes){
	cout << "INFORMES DEL TURNO NUMERO " << informes->getTurno() << endl;
	cout << "Celulas vivas: " << informes->getCelulasVivas() << endl;
	cout << "Nacimientos: " << informes->getNacimientos() << endl;
	float promedioDeNacimientos = ((float)informes->getNacimientosTotales()/(float)informes->getTurno());
	cout << "Promedio de nacimientos Totales: " << promedioDeNacimientos  << endl;
	cout << "Muertes: " << informes->getMuertes() << endl;
	float promedioDeMuertes = ((float)informes->getMuertesTotales()/(float)informes->getTurno());
	cout << "Promedio de muertes totales: " << promedioDeMuertes << endl << endl;
}

void Interfaz::mostrarCantidadDeCelulasVivas(Informe* informes){
	cout << "Celulas vivas: " << informes->getCelulasVivas()<< endl;
	cout << endl;
}

void Interfaz::mostrarFinalizacionDelJuego(){
	cout << "          ";
	cout << "Programa finalizado. Ciao";
	cin.get();
}
