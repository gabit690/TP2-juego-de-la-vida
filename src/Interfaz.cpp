
#include "Interfaz.h"
#include <iostream>
using namespace std;

Interfaz::Interfaz(){

}

void Interfaz::mostrarBienvenida(){
	cout << "			";
	cout << "Bienvenido al 'Juego de la vida 2.5'." << endl;
}

void Interfaz::pedirRutaDeUnArchivo(){
	cout << endl;
	cout << ">>> Ingrese la ruta del archivo de texto con su extension para procesar." << endl;
	cout << "Su respuesta: ";
}

void Interfaz::mostrarQueElArchivoNoExiste(){
	cout << endl;
	cout << "¡¡¡ El nombre del archivo ingresado no existe. !!!" << endl << endl;
}

void Interfaz::mostrarErrorDatoInvalido(){
	cout << endl;
	cout << "El dato ingresado es invalido.";
	cout << endl;
}

void Interfaz::mostrarMenuDeJuego(){
	cout << endl;
	cout << "          ";
	cout << "MENU DE JUEGO." << endl;
	cout << "1. Ejecutar una cantidad de turnos a elegir." << endl;
	cout << "2. Reiniciar el juego." << endl;
	cout << "3. Terminar." << endl << endl;
}

void Interfaz::mostrarQueElJuegoSeCongelo(){
	cout << endl;
	cout << "El juego se ha congelado, es decir, no se modifico el tablero ";
	cout <<	"en dos turnos consecutivos." << endl;
	cout << "NO PUEDE EJECUTAR MAS TURNOS.!!!";
	cout << endl;
}

void Interfaz::pedirEleccionDelMenuDeJuego(){
	cout << ">>> Elija una de las acciones." << endl;
	cout << "Su respuesta: ";
}

void Interfaz::pedirUnaCantidadDeTurnos(){
	cout << endl;
	cout << "Ingrese cuantos turnos quiere realizar." << endl;
	cout << "Su respuesta: ";
}

void Interfaz::pedirEleccionDeUnTableroOrigen(unsigned int cantidadDeTableros){
	cout << endl;
	cout << ">>> Elija uno de los " << cantidadDeTableros << " tableros disponibles que sera el ORIGEN ingresando un numero." <<  endl;
	cout << "Su respuesta: ";
}

void Interfaz::pedirEleccionDeUnTableroDestino(unsigned int cantidadDeTableros){
	cout << endl;
	cout << ">>> Elija uno de los " << cantidadDeTableros << " tableros disponibles que sera el DESTINO ingresando un numero." <<  endl;
	cout << "Su respuesta: ";
}

void Interfaz::mostrarEleccionDelMismoTablero(){
	cout << endl;
	cout << ">>> Ingreso dos veces la posicion del mismo tablero. No se puede hacer eso." << endl;
}

void Interfaz::mostrarInformesDelJuego(Informe* informes){
	cout << endl;
	cout << "INFORMES DEL TURNO NUMERO " << informes->getTurno() << endl;
	cout << "Celulas vivas: " << informes->getCelulasVivas() << endl;
	cout << "Nacimientos: " << informes->getNacimientos() << endl;
	float promedioDeNacimientos = ((float)informes->getNacimientosTotales()/(float)informes->getTurno());
	cout << "Promedio de nacimientos Totales: " << promedioDeNacimientos  << endl;
	cout << "Muertes: " << informes->getMuertes() << endl;
	float promedioDeMuertes = ((float)informes->getMuertesTotales()/(float)informes->getTurno());
	cout << "Promedio de muertes totales: " << promedioDeMuertes << endl;
}

void Interfaz::mostrarCantidadDeCelulasVivas(Informe* informes){
	cout << "Celulas vivas: " << informes->getCelulasVivas()<< endl;
	cout << endl;
}

void Interfaz::mostrarCaminoMinimo(Pila<std::string>* elCaminoMinimo, unsigned int transferenciasDeCelulas){
	cout << endl;
	cout << "***** Camino minimo entre los tableros escogidos. *****" << endl << endl;
	while(!elCaminoMinimo->estaVacia()){
		cout << elCaminoMinimo->desapilar();

		if(!elCaminoMinimo->estaVacia()){
			cout << " ---> ";
		}
	}
	cout << endl << endl;
	cout << "La transferencia acumulada en el camino es: " << transferenciasDeCelulas << endl;
}

void Interfaz::mostarInexistenciaDeAlgunCaminoMinimo(){
	cout << endl;
	cout <<  "No existe camino minimo donde se hayan producido transferencias entre los tableros escogidos" << endl;
}

void Interfaz::mostrarFinalizacionDelJuego(){
	cout << endl;
	cout << "          ";
	cout << "Programa finalizado. Ciao";
}

