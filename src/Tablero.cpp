#include "Tablero.h"

Tablero::Tablero(unsigned int cantidadDeFilas, unsigned int cantidadDeColumnas){

	this->matriz = new Parcela*[cantidadDeColumnas];
	for(unsigned int i = 0; i<cantidadDeColumnas; i++){
		this->matriz[i] = new Parcela*();
	}

	for(unsigned int i = 0; i<cantidadDeColumnas; i++){
		for(unsigned int j = 0; i<cantidadDeFilas; i++){
			this->matriz[i][j] = new Parcela;
		}
	}
	this->cantidadDeFilas = cantidadDeFilas;
	this->cantidadDeColumnas = cantidadDeColumnas;
}

Parcela* Tablero::obtenerParcela(unsigned numeroDeFila, unsigned int numeroDeColumna){
	return this->matriz[numeroDeColumna-1][numeroDeFila-1];
}

unsigned int Tablero::contarColumnas(){

	return this->cantidadDeColumnas;
}

unsigned int Tablero::contarFilas(){

	return this->cantidadDeFilas;
}

Lista<Parcela*>* Tablero::obtenerVecinas(unsigned int numeroDeFila, unsigned int numeroDeColumna){
	// Codigo para obtener las filas vecinas y luego verificar su estado
	return NULL;
}

void Tablero::reiniciarTablero(){
	for(unsigned int i = 0; i<cantidadDeColumnas; i++){
		for(unsigned int j = 0; i<cantidadDeFilas; i++){
			//this->matriz[i][j]->reiniciarParcela();
		}
	}
}

Tablero::~Tablero() {
	for(unsigned int i = 0; i<cantidadDeColumnas; i++){
		for(unsigned int j = 0; i<cantidadDeFilas; i++){
			delete this->matriz[i][j];
		}
	}

	for(unsigned int i = 0; i<cantidadDeColumnas; i++){
		delete this->matriz[i];
	}

	delete[] this->matriz;
}
