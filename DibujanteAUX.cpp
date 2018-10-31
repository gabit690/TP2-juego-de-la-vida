#include "Dibujante.h"

Dibujante::Dibujante(Tablero *tablero, unsigned int ancho, unsigned int alto){

	this->tablero = tablero;
	this->anchoDeImagen = ancho;
	this->altoDeImagen = alto;
	this->anchoDeFicha = this->anchoDeImagen / tablero->contarColumnas();
	this->altoDeFicha = this->altoDeImagen / tablero->contarFilas();
	this->cantidadDeImagenesCreadas = 1;

}

void Dibujante::dibujarTablero(){

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
}

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
