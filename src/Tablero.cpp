#include "Tablero.h"

Tablero::Tablero(unsigned int cantidadDeFilas, unsigned int cantidadDeColumnas){

	this->cantidadDeFilas = cantidadDeFilas;
	this->cantidadDeColumnas = cantidadDeColumnas;
	this->cantidadDeFichas = 0;
	this->columnas = this->crearColumnas(cantidadDeFilas, cantidadDeColumnas);
}

void Tablero::acomodarFichasCaidas(unsigned int fila, unsigned int columna){

	unsigned int cantidadDeFilas = this->contarFichas(columna);
	for(unsigned int i = fila; i <= cantidadDeFilas; i++){
		Ficha* ficha = this->obtenerFicha(i, columna);
		ficha->obtenerPosicion()->asignarNumeroDeFila(i);
	}
}

unsigned int Tablero::contarFilas(){
	return this->cantidadDeFilas;
}

Columna** Tablero::crearColumnas(unsigned int cantidadDeFilas,
								 unsigned int cantidadDeColumnas){

	Columna** columnas;
	columnas = new Columna*[cantidadDeColumnas];

	for (unsigned int i = 1; i <= cantidadDeColumnas; i++){
		columnas[i - 1] = new Columna(cantidadDeFilas);
	}
	return columnas;
}

void Tablero::agregar(Ficha* nuevaFicha){

	int numeroDeColumna = nuevaFicha->obtenerPosicion()->obtenerNumeroDeColumna();
	this->columnas[numeroDeColumna - 1]->agregar(nuevaFicha);
	this->cantidadDeFichas++;

}

void Tablero::remover(Ficha* ficha){

	unsigned int numeroDeColumna = ficha->obtenerPosicion()->obtenerNumeroDeColumna();
	unsigned int numeroDeFila = ficha->obtenerPosicion()->obtenerNumeroDeFila();

	this->columnas[numeroDeColumna - 1]->remover(numeroDeFila);
	this->cantidadDeFichas--;
	this->acomodarFichasCaidas(numeroDeFila, numeroDeColumna);
}

Ficha* Tablero::obtenerFicha(unsigned numeroDeFila, unsigned int numeroDeColumna){

	return this->columnas[numeroDeColumna - 1]->obtenerFicha(numeroDeFila);
}

unsigned int Tablero::contarColumnas(){

	return this->cantidadDeColumnas;
}

unsigned int Tablero::contarFichas(unsigned int numeroDeColumna){

	return this->columnas[numeroDeColumna - 1]->contarFichas();
}

bool Tablero::estaLleno(){

	return this->cantidadDeFichas == (this->cantidadDeColumnas * this->cantidadDeFilas);
}

bool Tablero::estaVacio(){

	return this->cantidadDeFichas == 0;
}

Columna* Tablero::obtenerColumna(unsigned int numeroDeColumna){

	return this->columnas[numeroDeColumna - 1];
}

bool Tablero::existeFichaEn(Vector* posicion){

	return (posicion->obtenerNumeroDeColumna() >= 1 &&
		posicion->obtenerNumeroDeColumna() <= this->contarColumnas() &&
		posicion->obtenerNumeroDeFila() >= 1 &&
		posicion->obtenerNumeroDeFila() <= this->contarFichas(posicion->obtenerNumeroDeColumna())
	);
}

Ficha* Tablero::obtenerFicha(Vector* posicion){

	return this->columnas[posicion->obtenerNumeroDeColumna() - 1]->obtenerFicha(
			posicion->obtenerNumeroDeFila()
	);
}


void Tablero::obtenerVecinas(Ficha* ficha,
							 Lista<Ficha*>* fichasVecinas){

	unsigned int desdeColumna;
	unsigned int hastaColumna;
	unsigned int desdeFila;
	unsigned int hastaFila;
	Columna* unaColumna;
	Ficha* unaFicha;
	Lista<Ficha*>* fichas;
	Vector* posicion = ficha->obtenerPosicion();

	this->ajustarRango(posicion->obtenerNumeroDeColumna(), desdeColumna,
					   hastaColumna, 1, this->contarColumnas(), 1);

	for (unsigned int i = desdeColumna; i <= hastaColumna; i++){

		unaColumna = this->columnas[i - 1];
		this->ajustarRango(posicion->obtenerNumeroDeFila(), desdeFila,
						   hastaFila, 1, unaColumna->contarFichas(), 1);

		if (hastaFila >= desdeFila){
			fichas = unaColumna->obtenerFichas();
			fichas->iniciarCursor();
			for (unsigned int j = 1; j < desdeFila; j++){
				fichas->avanzarCursor();
			}
			for (unsigned int k = desdeFila; k <= hastaFila; k++){

				fichas->avanzarCursor();
				unaFicha = fichas->obtenerCursor();

				if (unaFicha != ficha){

					fichasVecinas->agregar(unaFicha);
				}
			}
		}
	}
}

void Tablero::ajustarRango(unsigned int valor, unsigned int &desde,
		    			   unsigned int &hasta, unsigned int limiteInferior,
						   unsigned int limiteSuperior, unsigned int rango){

	if ((int)(valor - rango) < (int)(limiteInferior)){
		desde = limiteInferior;
	} else {
		desde = valor - rango;
	}

	if (valor + rango > limiteSuperior){
		hasta = limiteSuperior;
	} else {
		hasta = valor + rango;
	}
}

Tablero::~Tablero() {

	for (unsigned int i = 1; i <= this->cantidadDeColumnas; i++){
		Columna* unaColumna = this->columnas[i - 1];
		delete unaColumna;
	}
	delete[] this->columnas;
}

