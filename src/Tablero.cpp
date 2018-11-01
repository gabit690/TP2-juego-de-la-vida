#include "Tablero.h"
#include "Parcela.h"

Tablero::Tablero(int cantidadDeFilas, int cantidadDeColumnas){

	this->cantidadDeFilas = cantidadDeFilas;
	this->cantidadDeColumnas = cantidadDeColumnas;
	this->tablero = new Parcela[cantidadDeFilas];
	for (int i=0;i<cantidadDeFilas;i++){
		this->tablero[i]=new Parcela[cantidadDeColumnas];
	}
}
void Tablero::cargarParcelaAlTablero(Parcela parcela, int x,int y){

	this->tablero[x][y]=parcela;

}

Parcela Tablero::obtenerParcela(unsigned int numeroDeFila, unsigned int numeroDeColumna){
	return this->matriz[numeroDeColumna-1][numeroDeFila-1];
}

unsigned int Tablero::contarColumnas(){

	return this->cantidadDeColumnas;
}

unsigned int Tablero::contarFilas(){

	return this->cantidadDeFilas;
}

Lista<Parcela>* Tablero::obtenerVecinas(unsigned int numeroDeFila, unsigned int numeroDeColumna){
	// Codigo para obtener las filas vecinas y luego verificar su estado
	return NULL;
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
