/*
 * Interfaz.h
 *
 *  Created on: 31 oct. 2018
 *      Author: gabit
 */

#ifndef INTERFAZ_H_
#define INTERFAZ_H_

#include "Informe.h"

/*
 * La 'Interfaz' se encarga de mostrar mensajes determinados por consola.
 */
class Interfaz {

	public:

		//PRE: -.
		//POST: Muestra un mensaje de bienvenida al usuario.
		void mostrarBienvenida();

		//PRE: -.
		//POST: pide una eleccion de una fila del tablero y la guarda.
		void pedirEleccionDeUnaFila(int valorIngresado);

		//PRE: -.
		//POST: pide una eleccion de una columna del tablero y la guarda.
		void pedirEleccionDeUnaColumna(int valorIngresado);

		//PRE: -.
		//POST: Muestra que el dato ingresado es invalido.
		void mostrarErrorDatoInvalido();

		//PRE: -.
		//POST: Muestra que la posicion ya fue ingresada con anterioridad.
		void mostrarErrorPosicionRepetida();

		//PRE: -.
		//POST: Muestra el menu de las acciones que el usuario puede realizar en el juego.
		void mostrarMenuDeJuego();

		//PRE: -.
		//POST: Muestra un mensaje diciendo que el juego se congelo.
		void mostrarQueElJuegoSeCongelo();

		//PRE: -.
		//POST: Pide la eleccion de una de las tareas del menu de juego.
		void pedirEleccionDelMenuDeJuego();

		//PRE: -.
		//POST: Pide una cantidad de turnos para jugar.
		void pedirUnaCantidadDeTurnos();

		//PRE: informes inicializado.
		//POST: Muestra el informe de los datos recolectados en el juego.
		void mostrarInformesDelJuego(Informe* informes);

		//PRE: informes inicializado.
		//POST: Muestra la cantidad de celulas vivas.
		void mostrarCantidadDeCelulasVivas(Informe* informes);

		//PRE: -.
		//POST: Muestra por pantalla un mensaje que indica la terminacion del juego.
		void mostrarFinalizacionDelJuego();

};

#endif /* INTERFAZ_H_ */
