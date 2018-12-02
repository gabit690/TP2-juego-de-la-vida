
#ifndef INTERFAZ_H_
#define INTERFAZ_H_

#include "Informe.h"
#include "Pila.h"
#include <string>

/*
 * La 'Interfaz' se encarga de mostrar mensajes determinados por consola.
 */
class Interfaz {

	public:

		Interfaz();

		/* PRE: -.
		 * POST:Muestra un mensaje de bienvenida al usuario.
		 */
		void mostrarBienvenida();

		/* PRE: -.
		 * POST: Muestra el pedido de ingreso de la ruta de un archivo.
		 */
		void pedirRutaDeUnArchivo();

		/* PRE: -.
		 * POST: Muestra que el archivo no existe.
		 */
		void mostrarQueElArchivoNoExiste();

		/* PRE: -.
		 * POST: Muestra que el dato ingresado es invalido.
		 */
		void mostrarErrorDatoInvalido();

		/* PRE: -.
		 * POST: Muestra el menu de las acciones que el usuario puede realizar en el juego.
		 */
		void mostrarMenuDeJuego();

		/* PRE: -.
		 * POST: Muestra un mensaje diciendo que el juego se congelo.
		 */
		void mostrarQueElJuegoSeCongelo();

		/* PRE: -.
		 * POST: Pide la eleccion de una de las tareas del menu de juego.
		 */
		void pedirEleccionDelMenuDeJuego();

		/* PRE: -.
		 * POST: Pide una cantidad de turnos para jugar.
		 */
		void pedirUnaCantidadDeTurnos();

		/* PRE: cantidadDeTableros es la cantidad de tableros en el juego.
		 * POST: Pide una posicion que corresponde a uno de los tableros del juego.
		 */
		void pedirEleccionDeUnTablero(unsigned int cantidadDeTableros);

		/* PRE: -.
		 * POST: muestra por pantalla que se escogio dos veces el mismo tablero.
		 */
		void mostrarEleccionDelMismoTablero();

		/* PRE: informes inicializado.
		 * POST: Muestra el informe de los datos recolectados en el juego.
		 */
		void mostrarInformesDelJuego(Informe* informes);

		/* PRE: informes inicializado.
		 * Post: Muestra la cantidad de celulas vivas.
		 */
		void mostrarCantidadDeCelulasVivas(Informe* informes);

		/* PRE: -.
		 * POST: Muestra por pantalla un mensaje que indica la terminacion del juego.
		 */
		void mostrarFinalizacionDelJuego();

		/* PRE: -.
		 * POST: Muestra por pantalla el camino minimo entre dos tableros escogidos.
		 */
		void mostrarCaminoMinimo(Pila<std::string>* elCaminoMinimo, unsigned int transferenciasDeCelulas);

		/* PRE: -.
		 * POST: Muestra por pantalla que no existen un camino minimo entre dos tableros.
		 */
		void mostarInexistenciaDeAlgunCaminoMinimo();

};

#endif /* INTERFAZ_H_ */
