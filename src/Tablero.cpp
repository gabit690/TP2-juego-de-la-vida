#include "Tablero.h"

Tablero::Tablero(std::string  unNombre, unsigned int cantidadDeFilas, unsigned int cantidadDeColumnas){

	this->nombre = unNombre;
	//Creaccion del tablero con punteros a parcelas
	this->casilleros = new Parcela**[cantidadDeColumnas];
	for(unsigned int i = 0; i<cantidadDeColumnas; i++){
		this->casilleros[i] = new Parcela*[cantidadDeFilas];
	}

	//Craeacion y asignacion de las parcelas del tablero.
	for(unsigned int i = 0; i<cantidadDeColumnas; i++){
		for(unsigned int j = 0; j<cantidadDeFilas; j++){
			Parcela* parcelaNueva = new Parcela();
			this->casilleros[i][j] = parcelaNueva;
		}
	}
	this->cantidadDeFilas = cantidadDeFilas;
	this->cantidadDeColumnas = cantidadDeColumnas;
}

Parcela* Tablero::obtenerParcela(unsigned int numeroDeColumna, unsigned numeroDeFila){
	return this->casilleros[numeroDeColumna-1][numeroDeFila-1];
}

unsigned int Tablero::contarColumnas(){

	return this->cantidadDeColumnas;
}

unsigned int Tablero::contarFilas(){

	return this->cantidadDeFilas;
}

std::string Tablero::obtenerNombre(){
	return this->nombre;
}

Lista<Parcela*>* Tablero::obtenerVecinas(unsigned int numeroDeFila, unsigned int numeroDeColumna){
	// Codigo para obtener las filas vecinas y luego verificar su estado
	return NULL;
}

Tablero::~Tablero() {
	//Elimino las parcelas
	for(unsigned int i = 0; i<cantidadDeColumnas; i++){
		for(unsigned int j = 0; j<cantidadDeFilas; j++){
			delete this->casilleros[i][j];
		}
	}

	//Elimino las filas
	for(unsigned int i = 0; i<cantidadDeFilas; i++){
		delete[] this->casilleros[i];
	}

	//Elimino las colunas
	delete[] this->casilleros;

}
