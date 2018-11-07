#include "Tablero.h"
using namespace std;

Tablero::Tablero(string  unNombre, unsigned int cantidadDeColumnas, unsigned int cantidadDeFilas){

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

string Tablero::obtenerNombre(){
	return this->nombre;
}

unsigned int Tablero::obtenerCantidadDeVecinasVivas(unsigned int numeroDeColumna, unsigned int numeroDeFila){
	unsigned int vecinasVivas = 0;

	unsigned int filaAnalizada = (numeroDeFila-1);
	unsigned int ultimaFilaAnalizada = (numeroDeFila+1);
	for(unsigned int i = filaAnalizada; i <= ultimaFilaAnalizada; i++){
		unsigned int columnaAnalizada = (numeroDeColumna-1);
		unsigned int ultimaColumnaAnalizada = (numeroDeColumna+1);
		for(unsigned int j = columnaAnalizada; j <= ultimaColumnaAnalizada; j++){
			bool esUnaPosicionDistinta = ((numeroDeFila!=i)||(numeroDeColumna!=j));
			if((existeLaParcela(j, i)&&(esUnaPosicionDistinta))){
				Celula* unaCelula;
				unaCelula = this->obtenerParcela(j, i)->obtenerCelula();
				if(unaCelula->estaViva()||unaCelula->estaPorMorir()){
					vecinasVivas++;
				}
			}
		}
	}
	return vecinasVivas;
}

bool Tablero::existeLaParcela(unsigned int numeroDeColumna, unsigned int numeroDeFila){
	bool filaValida = ((numeroDeFila<=this->cantidadDeFilas)&&(numeroDeFila>0));
	bool columnaValida = ((numeroDeColumna<=this->cantidadDeColumnas)&&(numeroDeColumna>0));
	return (filaValida&&columnaValida);
}

Tablero::~Tablero() {
	//Elimino las parcelas
	for(unsigned int i = 0; i<this->cantidadDeColumnas; i++){
		for(unsigned int j = 0; j<this->cantidadDeFilas; j++){
			delete this->casilleros[i][j];
		}
	}

	//Elimino las filas
	for(unsigned int i = 0; i<this->cantidadDeFilas; i++){
		delete[] this->casilleros[i];
	}

	//Elimino las colunas
	delete[] this->casilleros;

}
