/*
 * Dibujante.cpp
 *
 *  Created on: 1 nov. 2018
 *      Author: gabit
 */

#include "Dibujante.h"

Dibujante::Dibujante(){

	this->cantidadDeImagenesCreadas = 1;

}

void Dibujante::dibujarTableros(Lista<Tablero*>* tablero, unsigned int medidaDeParcela){
/*
	MapaDeBits* imagen = new MapaDeBits(this->anchoDeImagen, this->altoDeImagen);

	for (unsigned int i = 1; i <= this->tablero->contarColumnas(); i++){

		Columna* unaColumna = this->tablero->obtenerColumna(i);
		if (!unaColumna->estaVacia()){

			this->dibujar(unaColumna, imagen);
		}
	}

	imagen->escribir("imagen_", this->cantidadDeImagenesCreadas);
	this->cantidadDeImagenesCreadas++;
	delete imagen;
	*/
}

void dibujarUnaParcela(Parcela* unaParcela, MapaDeBits* imagen){

}

void dibujarUnaCelula(Celula* unaCelula, MapaDeBits* imagen){

}

/*
void Dibujante::dibujar(Columna* columna, MapaDeBits* imagen){

	Lista<Ficha*>* fichas = columna->obtenerFichas();
	fichas->iniciarCursor();

	while(fichas->avanzarCursor()){

		this->dibujar(fichas->obtenerCursor(), imagen);
	}
}

void Dibujante::dibujar(Ficha* ficha, MapaDeBits* imagen){

	unsigned int numeroDeColumna = ficha->obtenerPosicion()->obtenerNumeroDeColumna();
	unsigned int numeroDeFila = ficha->obtenerPosicion()->obtenerNumeroDeFila();


	for (unsigned int i = this->anchoDeFicha * (numeroDeColumna - 1);
		 i < this->anchoDeFicha * numeroDeColumna;
		 i++){

		for (unsigned int j = this->altoDeFicha * (numeroDeFila - 1);
			 j < this->altoDeFicha * numeroDeFila;
			 j++){

			imagen->asignar(i, j, ficha->obtenerColor());
		}
	}
}
*/

Dibujante::~Dibujante() {
	// TODO Auto-generated destructor stub
}

