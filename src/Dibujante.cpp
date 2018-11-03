/*
 * Dibujante.cpp
 *
 *  Created on: 1 nov. 2018
 *      Author: gabit
 */

#include "Dibujante.h"


Dibujante::Dibujante(){
	this->dibujos = new Lista<MapaDeBits*>();
	this->medidaDeUnaParcelaCuadrada = 30;	// 30x30 pixeles

}

void Dibujante::dibujarTableros(Lista<Tablero*>* tableros, unsigned int medidaDeParcela){

	tableros->iniciarCursor();
	while(tableros->avanzarCursor()){
		Tablero* unTablero;
		unTablero = tableros->obtenerCursor();
		dibujarUnTablero(unTablero, medidaDeParcela);
	}
}

void Dibujante::dibujarUnTablero(Tablero* unTablero,unsigned int medidaDeParcela){
	unsigned int ancho = (unTablero->contarFilas()*medidaDeParcela);
	unsigned int alto = (unTablero->contarColumnas()*medidaDeParcela);
	MapaDeBits* imagen = new MapaDeBits(ancho, alto);
	dibujarCuadricula(imagen, ancho, alto, medidaDeParcela);

	// Esta parte la use para dibujar un par de celulas con las pruebas del main
	// Lo dejo como comentario para que vean como los use pero esto no va en el metodo final

	/*
	unsigned int columna = 1;
	unsigned int fila = 1;
	unsigned int desdeX = ((columna-1)*medidaDeParcela);
	unsigned int desdeY = ((fila-1)*medidaDeParcela);
	Color* colorDeParcela;
	unTablero->obtenerParcela(columna, fila)->setearColorDeParcela(0,255,0);
	colorDeParcela = unTablero->obtenerParcela(columna, fila)->obtenerColor();
	dibujarUnaParcela(colorDeParcela, imagen, desdeX, desdeY, medidaDeParcela);


	columna = 2;
	fila = 1;
	desdeX = ((columna-1)*medidaDeParcela);
	desdeY = ((fila-1)*medidaDeParcela);
	unTablero->obtenerParcela(columna, fila)->setearColorDeParcela(0,255,0);
	colorDeParcela = unTablero->obtenerParcela(columna, fila)->obtenerColor();
	dibujarUnaParcela(colorDeParcela, imagen, desdeX, desdeY, medidaDeParcela);

	columna = 3;
	fila = 1;
	desdeX = ((columna-1)*medidaDeParcela);
	desdeY = ((fila-1)*medidaDeParcela);
	unTablero->obtenerParcela(columna, fila)->setearColorDeParcela(0,255,0);
	colorDeParcela = unTablero->obtenerParcela(columna, fila)->obtenerColor();
	dibujarUnaParcela(colorDeParcela, imagen, desdeX, desdeY, medidaDeParcela);

	columna = 1;
	fila = 2;
	desdeX = ((columna-1)*medidaDeParcela);
	desdeY = ((fila-1)*medidaDeParcela);
	unTablero->obtenerParcela(columna, fila)->setearColorDeParcela(255,255,0);
	colorDeParcela = unTablero->obtenerParcela(columna, fila)->obtenerColor();
	dibujarUnaParcela(colorDeParcela, imagen, desdeX, desdeY, medidaDeParcela);

	columna = 2;
	fila = 2;
	desdeX = ((columna-1)*medidaDeParcela);
	desdeY = ((fila-1)*medidaDeParcela);
	unTablero->obtenerParcela(columna, fila)->setearColorDeParcela(255,255,0);
	colorDeParcela = unTablero->obtenerParcela(columna, fila)->obtenerColor();
	dibujarUnaParcela(colorDeParcela, imagen, desdeX, desdeY, medidaDeParcela);

	columna = 3;
	fila = 2;
	desdeX = ((columna-1)*medidaDeParcela);
	desdeY = ((fila-1)*medidaDeParcela);
	unTablero->obtenerParcela(columna, fila)->setearColorDeParcela(255,255,0);
	colorDeParcela = unTablero->obtenerParcela(columna, fila)->obtenerColor();
	dibujarUnaParcela(colorDeParcela, imagen, desdeX, desdeY, medidaDeParcela);

	columna = 1;
	fila = 3;
	desdeX = ((columna-1)*medidaDeParcela);
	desdeY = ((fila-1)*medidaDeParcela);
	unTablero->obtenerParcela(columna, fila)->setearColorDeParcela(0,0,255);
	colorDeParcela = unTablero->obtenerParcela(columna, fila)->obtenerColor();
	dibujarUnaParcela(colorDeParcela, imagen, desdeX, desdeY, medidaDeParcela);

	columna = 2;
	fila = 3;
	desdeX = ((columna-1)*medidaDeParcela);
	desdeY = ((fila-1)*medidaDeParcela);
	unTablero->obtenerParcela(columna, fila)->setearColorDeParcela(0,0,255);
	colorDeParcela = unTablero->obtenerParcela(columna, fila)->obtenerColor();
	dibujarUnaParcela(colorDeParcela, imagen, desdeX, desdeY, medidaDeParcela);

	columna = 3;
	fila = 3;
	desdeX = ((columna-1)*medidaDeParcela);
	desdeY = ((fila-1)*medidaDeParcela);
	unTablero->obtenerParcela(columna, fila)->setearColorDeParcela(0,0,255);
	colorDeParcela = unTablero->obtenerParcela(columna, fila)->obtenerColor();
	dibujarUnaParcela(colorDeParcela, imagen, desdeX, desdeY, medidaDeParcela);


	//Dibujar Celulas
	columna = 3;
	fila = 3;
	desdeX = ((columna-1)*medidaDeParcela);
	desdeY = ((fila-1)*medidaDeParcela);
	unTablero->obtenerParcela(columna, fila)->obtenerCelula()->cambiarColorDeLaCelula(255, 0, 0);
	Color* colorDeCelula;
	colorDeCelula = unTablero->obtenerParcela(columna, fila)->obtenerCelula()->getColor();
	dibujarUnaCelula(colorDeCelula, imagen, desdeX, desdeY, medidaDeParcela);

	columna = 1;
	fila = 1;
	desdeX = ((columna-1)*medidaDeParcela);
	desdeY = ((fila-1)*medidaDeParcela);
	unTablero->obtenerParcela(columna, fila)->obtenerCelula()->cambiarColorDeLaCelula(255, 0, 0);
	colorDeCelula = unTablero->obtenerParcela(columna, fila)->obtenerCelula()->getColor();
	dibujarUnaCelula(colorDeCelula, imagen, desdeX, desdeY, medidaDeParcela);

	columna = 3;
	fila = 1;
	desdeX = ((columna-1)*medidaDeParcela);
	desdeY = ((fila-1)*medidaDeParcela);
	unTablero->obtenerParcela(columna, fila)->obtenerCelula()->cambiarColorDeLaCelula(255, 0, 0);
	colorDeCelula = unTablero->obtenerParcela(columna, fila)->obtenerCelula()->getColor();
	dibujarUnaCelula(colorDeCelula, imagen, desdeX, desdeY, medidaDeParcela);
	*/
	dibujarContenidoDelTablero(unTablero, imagen, medidaDeParcela);
	std::string nombre = unTablero->obtenerNombre();
	imagen->escribir(nombre);
	this->dibujos->agregar(imagen);
	delete imagen;
}

void Dibujante::dibujarContenidoDelTablero(Tablero* unTablero, MapaDeBits* imagen,unsigned int medidaDeParcela){
	for(unsigned int columna = 1; columna<unTablero->contarColumnas();columna++){
		for(unsigned int fila = 1; fila<unTablero->contarFilas();fila++){
			//desdeX y desdeY seran los pixeles iniciales desde donde se dibujara dentro de la imagen
			unsigned int desdeX = ((columna-1)*medidaDeParcela);
			unsigned int desdeY = ((fila-1)*medidaDeParcela);
			Color* colorDeUnaParcela;
			colorDeUnaParcela = unTablero->obtenerParcela(columna, fila)->obtenerColor();
			dibujarUnaParcela(colorDeUnaParcela, imagen, desdeX, desdeY, medidaDeParcela);
			Color* colorDeUnaCelula;
			colorDeUnaCelula = unTablero->obtenerParcela(columna, fila)->obtenerCelula()->getColor();
			dibujarUnaCelula(colorDeUnaCelula, imagen, desdeX, desdeY, medidaDeParcela);
		}
	}
}

void Dibujante::dibujarCuadricula(MapaDeBits* unaImagen, unsigned int ancho, unsigned int alto, unsigned int medidaDeParcela){

	Color* colorDeLineas = new Color(0, 0, 0);
	//Dibuja Lineas verticales.
	for(unsigned int x = (medidaDeParcela-1); x<(ancho); x+=medidaDeParcela){
		for(unsigned int y = 0; y<alto; y++){
			unaImagen->asignar(x, y, colorDeLineas);
		}
	}
	//Dibuja Lineas Hotizontales.
	for(unsigned int x = 0; x<ancho; x++){
		for(unsigned int y = (medidaDeParcela-1); y<(alto); y+=medidaDeParcela){
			unaImagen->asignar(x, y, colorDeLineas);
		}
	}
	delete colorDeLineas;
}

void Dibujante::dibujarUnaParcela(Color* colorDeParcela, MapaDeBits* imagen, unsigned int pixelX, unsigned int pixelY, unsigned int medidaDeParcela){
	unsigned int hastaX = (pixelX+medidaDeParcela)-2;
	unsigned int hastaY = (pixelY+medidaDeParcela)-2;
	dibujarEnAnchoYalto(colorDeParcela, imagen, pixelX, hastaX, pixelY, hastaY);
}

void Dibujante::dibujarUnaCelula(Color* colorDeCelula, MapaDeBits* imagen, unsigned int pixelX, unsigned int pixelY, unsigned int medidaDeParcela){
	unsigned int tamanioDelPixel = (medidaDeParcela/6); //tamaño de la minima parta de un objeto en el dibujo.

	//Dibujo la parte superior de la celula
	unsigned int desdePixelX = pixelX+(tamanioDelPixel*2)-2;
	unsigned int hastaPixelX = pixelX+(tamanioDelPixel*4)-1;
	unsigned int desdePixelY = pixelY+(tamanioDelPixel)-2;
	unsigned int hastaPixelY = pixelY+(tamanioDelPixel*2)-1;
	dibujarEnAnchoYalto(colorDeCelula, imagen, desdePixelX, hastaPixelX, desdePixelY, hastaPixelY);
	//Dibujo la parte del medio de la celula
	desdePixelX = pixelX+(tamanioDelPixel)-1;
	hastaPixelX = pixelX+(tamanioDelPixel*5)-1;
	desdePixelY = pixelY+(tamanioDelPixel*2)-2;
	hastaPixelY = pixelY+(tamanioDelPixel*4)-1;
	dibujarEnAnchoYalto(colorDeCelula, imagen, desdePixelX, hastaPixelX, desdePixelY, hastaPixelY);
	//Dibujo la parte inferior de la celula
	desdePixelX = pixelX+(tamanioDelPixel*2)-1;
	hastaPixelX = pixelX+(tamanioDelPixel*4);
	desdePixelY = pixelY+(tamanioDelPixel*4)-2;
	hastaPixelY = pixelY+(tamanioDelPixel*5)-1;
	dibujarEnAnchoYalto(colorDeCelula, imagen, desdePixelX, hastaPixelX, desdePixelY, hastaPixelY);
}

void Dibujante::dibujarEnAnchoYalto(Color* unColor, MapaDeBits* imagen, unsigned int desdeX,
									unsigned int hastaX, unsigned int desdeY, unsigned int hastaY){
	for(unsigned int x = desdeX; x<=hastaX; x++){
		for(unsigned int y = desdeY; y<=hastaY; y++){
			imagen->asignar(x, y, unColor);
		}
	}
}

void Dibujante::reiniciarDibujante(){
	while(!this->dibujos->estaVacia()){
		this->dibujos->remover(1);
	}
}

Dibujante::~Dibujante() {
	delete this->dibujos;
}

