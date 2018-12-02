
#ifndef JUEGODELAVIDA_H_
#define JUEGODELAVIDA_H_

#include "Enfermero.h"
#include "Dibujante.h"
#include "Tablero.h"
#include "Interfaz.h"
#include "Informe.h"
#include "Grafo.h"
#include <fstream>

class JuegoDeLaVida {

	private:
		Enfermero* elEnfermero;
		Dibujante* elDibujante;
		Lista<Tablero*>* losTableros;
		Lista<Portal*>* losPortales;
		Interfaz* laPantalla;
		Informe* losInformes;
		Grafo* elGrafo;

	public:

		/* PRE: -.
		 * POST: pide los recursos necesarios para generar los elementos de los componentes
		 * del juego.
		 */
		JuegoDeLaVida();

		/* PRE: -.
		 * POST: Inicia una partida del juego.
		 */
		void jugar();

		/* PRE: -.
		 * POST: le asigna a 'archivo' la ruta de un archivo de texto para leer.
		 */
		void ingresarRutaDelArchivo(std::ifstream& archivo);

		/* PRE: archivo abierto y cuyos datos este bien organizados.
		 * POST: procesa la informacion contenida en el archivo para generar
		 * la configuracion inicial del juego.
		 */
		void procesarArchivo(std::ifstream& archivo);

		/* PRE: -.
		 * POST: Se realiza una partida del juego.
		 */
		void comenzarUnaPartida(bool &terminar);

		/* Pre: -.
		 * Post: Libera los recursos de memoria pedidos.
		 */
		~JuegoDeLaVida();

	private:

		/* Pre: archivo esta abierto.
		 * Post: Crea un tablero y lo agrega al juego.
		 */
		void agregarUnTablero(std::ifstream& archivo);

		/* Pre: archivo esta abierto.
		 * Post: configura una parcela en base a un registro leido del archivo de texto.
		 */
		void configurarUnaParcela(std::ifstream& archivo);

		/* Pre: nombreTablero es el nombre de un tablero existente en el juego.
		 * Post: devuelve el tablero buscado.
		 */
		Tablero* obtenerUnTableroCreado(std::string nombreTablero);

		/* Pre: archivo esta abierto.
		 * Post: Crea un portal que vincula dos parcelas de dos tableros distintos.
		 */
		void agregarUnPortal(std::ifstream& archivo);

		/* Pre: tipoDePortal es "Activo", "Pasivo" o "Normal".
		 * Post: devuelve el tipo de de portal que sera asignado.
		 */
		TipoDePortal determinarTipoDePortal(std::string tipoDePortal);

		/* Pre: archivo esta abierto.
		 * Post: cambia a viva una de las celulas de un tablero segun un
		 * registro leido del archivo.
		 */
		void setearUnaCelulaViva(std::ifstream& archivo);

		/* PRE: -.
		 * POST: obtiene la eleccion de una tarea a realizar de un menu por parte del usuario.
		 */
		unsigned int elegirUnaAccionDelMenuDeJuego();

		/* Pre: numeroElegido pertenece al intervalo [1, 3].
		 * Post: realiza la accion asignada a numeroElegido.
		 */
		void realizarAccion(unsigned int numeroElegido);

		/* Pre: -.
		 * Post: reinicia los elementos del juego para comenzar una nueva partida.
		 */
		void reiniciarJuego();

		/* Pre: turnos>0.
		 * Post: realiza la cantidad de turnos ingresada o hasta que todos los
		 * tableros no sufran modificaciones en dos turnos seguidos.
		 */
		void ejecutarTurnos(unsigned int turnos);

		/* Pre: -.
		 * Post: Libera la memoria pedida por la lista de portales.
		 */
		void liberarPortales();

		/* Pre: -.
		 * Post: Libera la memoria pedida por la lista de Tableros.
		 */
		void liberarTableros();

		/* Pre: -.
		 * Post: ingresa los identificadores de los tableros como vertices y los portales como aristas que
		 * conforman el grafo.
		 */
		void configurarGrafo();

		/* Pre: -.
		 * Post: arma los vertices del grafo usando los identificadores de los tableros.
		 */
		void ingresarVertices(Lista<Tablero*>* tableros);

		/* Pre: -.
		 * Post: arma las aristas del grafo usando los portales del juego.
		 */
		void ingresarAristas(Lista<Portal*>* portales);

		/* Pre: -.
		 * Post: pide al usuario un tablero de origen y destino para saber el camino minimo con
		 * menor cantidad de tranferencias de celulas entre ambos tableros y muestra la informacion por pantalla.
		 */
		void procesarGrafo();

		/* Pre: cantidadDeTableros > 0.
		 * Post: obtiene por parte del usuario la eleccion de un tablero de la lista de tableros.
		 */
		unsigned int elegirUnTablero(unsigned int cantidadDeTableros);
};

#endif /* JUEGODELAVIDA_H_ */
