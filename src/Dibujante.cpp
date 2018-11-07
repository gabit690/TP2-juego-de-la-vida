/*
 * Dibujante.cpp
 *
 *  Created on: 1 nov. 2018
 *      Author: gabit
 */

#include "Dibujante.h"
using namespace std;

Dibujante::Dibujante(){
	this->medidaDeUnaParcelaCuadrada = 30;	// 30x30 pixeles
}

void Dibujante::dibujarTableros(Lista<Tablero*>* tableros, unsigned int turnoDeJuego){

	tableros->iniciarCursor();
	while(tableros->avanzarCursor()){
		Tablero* unTablero;
		unTablero = tableros->obtenerCursor();
		dibujarUnTablero(unTablero, turnoDeJuego);
	}
}

void Dibujante::dibujarUnTablero(Tablero* unTablero, unsigned int tunoDeJuego){
	unsigned int ancho = (unTablero->contarFilas()*this->medidaDeUnaParcelaCuadrada);
	unsigned int alto = (unTablero->contarColumnas()*this->medidaDeUnaParcelaCuadrada);
	MapaDeBits* imagen = new MapaDeBits(ancho, alto);
	dibujarCuadricula(imagen, ancho, alto);
	dibujarContenidoDelTablero(unTablero, imagen);
	string nombre = unTablero->obtenerNombre()+"Turno"+to_string(tunoDeJuego);
	imagen->escribir(nombre);
	delete imagen;
}

void Dibujante::dibujarContenidoDelTablero(Tablero* unTablero, MapaDeBits* imagen){
	for(unsigned int columna = 1; columna<=unTablero->contarColumnas();columna++){
		for(unsigned int fila = 1; fila<=unTablero->contarFilas();fila++){
			//desdeX y desdeY seran los pixeles iniciales desde donde se dibujara la imagen.
			unsigned int desdeX = ((columna-1)*this->medidaDeUnaParcelaCuadrada);
			unsigned int desdeY = ((fila-1)*this->medidaDeUnaParcelaCuadrada);
			Color* colorDeUnaParcela;
			colorDeUnaParcela = unTablero->obtenerParcela(columna, fila)->obtenerColor();
			dibujarUnaParcela(colorDeUnaParcela, imagen, desdeX, desdeY);
			Color* colorDeUnaCelula;
			colorDeUnaCelula = unTablero->obtenerParcela(columna, fila)->obtenerCelula()->getColor();
			dibujarUnaCelula(colorDeUnaCelula, imagen, desdeX, desdeY);
		}
	}
}

void Dibujante::dibujarCuadricula(MapaDeBits* unaImagen, unsigned int ancho, unsigned int alto){

	Color* colorDeLineas = new Color(0, 0, 0);
	//Dibuja Lineas verticales.
	for(unsigned int x = (this->medidaDeUnaParcelaCuadrada-1); x<(ancho); x+=this->medidaDeUnaParcelaCuadrada){
		for(unsigned int y = 0; y<alto; y++){
			unaImagen->asignar(x, y, colorDeLineas);
		}
	}
	//Dibuja Lineas Hotizontales.
	for(unsigned int x = 0; x<ancho; x++){
		for(unsigned int y = (this->medidaDeUnaParcelaCuadrada-1); y<(alto); y+=this->medidaDeUnaParcelaCuadrada){
			unaImagen->asignar(x, y, colorDeLineas);
		}
	}
	delete colorDeLineas;
}

void Dibujante::dibujarUnaParcela(Color* colorDeParcela, MapaDeBits* imagen, unsigned int pixelX,
									unsigned int pixelY){
	unsigned int hastaX = (pixelX+this->medidaDeUnaParcelaCuadrada)-2;
	unsigned int hastaY = (pixelY+this->medidaDeUnaParcelaCuadrada)-2;
	dibujarEnAnchoYalto(colorDeParcela, imagen, pixelX, hastaX, pixelY, hastaY);
}

void Dibujante::dibujarUnaCelula(Color* colorDeCelula, MapaDeBits* imagen, unsigned int pixelX,
									unsigned int pixelY){
	unsigned int tamanioDelPixel = (this->medidaDeUnaParcelaCuadrada/6); //tamaño de la minima parta de un objeto en el dibujo.
	Color* borde;
	borde = new Color(0, 0, 0);
	dibujarParteSuperiorDeCelula(colorDeCelula, imagen, pixelX,pixelY, tamanioDelPixel, borde);
	dibujarParteMediaDeCelula(colorDeCelula, imagen, pixelX,pixelY, tamanioDelPixel, borde);
	dibujarParteInferiorDeCelula(colorDeCelula, imagen, pixelX,pixelY, tamanioDelPixel, borde);
	delete borde;
}

void Dibujante::dibujarParteSuperiorDeCelula(Color* colorDeCelula, MapaDeBits* imagen,
											unsigned int pixelX, unsigned int pixelY,
											unsigned int tamanioPixel, Color* borde){
	//Dibujo la parte superior de la celula
	unsigned int desdePixelX = pixelX+(tamanioPixel*2)-2;
	unsigned int hastaPixelX = pixelX+(tamanioPixel*4)-1;
	unsigned int desdePixelY = pixelY+(tamanioPixel)-2;
	unsigned int hastaPixelY = pixelY+(tamanioPixel*2)-1;
	dibujarEnAnchoYalto(colorDeCelula, imagen, desdePixelX, hastaPixelX, desdePixelY, hastaPixelY);
	//Dibuja los bordes
	dibujarEnAnchoYalto(borde, imagen, desdePixelX, hastaPixelX, desdePixelY, desdePixelY);
	dibujarEnAnchoYalto(borde, imagen, desdePixelX, desdePixelX, desdePixelY, hastaPixelY);
	dibujarEnAnchoYalto(borde, imagen, hastaPixelX, hastaPixelX, desdePixelY, hastaPixelY);
}

void Dibujante::dibujarParteMediaDeCelula(Color* colorDeCelula, MapaDeBits* imagen,
											unsigned int pixelX, unsigned int pixelY,
											unsigned int tamanioPixel, Color* borde){
	//Dibujo la parte del medio de la celula
	unsigned int desdePixelX = pixelX+(tamanioPixel)-1;
	unsigned int hastaPixelX = pixelX+(tamanioPixel*5)-1;
	unsigned int desdePixelY = pixelY+(tamanioPixel*2)-2;
	unsigned int hastaPixelY = pixelY+(tamanioPixel*4)-1;
	dibujarEnAnchoYalto(colorDeCelula, imagen, desdePixelX, hastaPixelX, desdePixelY, hastaPixelY);
	//Dibuja los bordes
	dibujarEnAnchoYalto(borde, imagen, desdePixelX, desdePixelX, desdePixelY, hastaPixelY);
	dibujarEnAnchoYalto(borde, imagen, hastaPixelX, hastaPixelX, desdePixelY, hastaPixelY);
	dibujarEnAnchoYalto(borde, imagen, desdePixelX, hastaPixelX-17, desdePixelY, desdePixelY);
	dibujarEnAnchoYalto(borde, imagen, hastaPixelX-4, hastaPixelX, desdePixelY, desdePixelY);
	dibujarEnAnchoYalto(borde, imagen, desdePixelX, hastaPixelX, hastaPixelY, hastaPixelY);
}

void Dibujante::dibujarParteInferiorDeCelula(Color* colorDeCelula, MapaDeBits* imagen,
												unsigned int pixelX, unsigned int pixelY,
												unsigned int tamanioPixel, Color* borde){
	//Dibujo la parte inferior de la celula
	unsigned int desdePixelX = pixelX+(tamanioPixel*2)-1;
	unsigned int hastaPixelX = pixelX+(tamanioPixel*4);
	unsigned int desdePixelY = pixelY+(tamanioPixel*4)-2;
	unsigned int hastaPixelY = pixelY+(tamanioPixel*5)-1;
	dibujarEnAnchoYalto(colorDeCelula, imagen, desdePixelX, hastaPixelX, desdePixelY, hastaPixelY);
	//Dibuja los bordes
	dibujarEnAnchoYalto(borde, imagen, desdePixelX, desdePixelX, desdePixelY+2, hastaPixelY);
	dibujarEnAnchoYalto(borde, imagen, hastaPixelX, hastaPixelX, desdePixelY+2, hastaPixelY);
	dibujarEnAnchoYalto(borde, imagen, desdePixelX, hastaPixelX, hastaPixelY, hastaPixelY);
}

void Dibujante::dibujarEnAnchoYalto(Color* unColor, MapaDeBits* imagen, unsigned int desdeX,
									unsigned int hastaX, unsigned int desdeY, unsigned int hastaY){
	for(unsigned int x = desdeX; x<=hastaX; x++){
		for(unsigned int y = desdeY; y<=hastaY; y++){
			imagen->asignar(x, y, unColor);
		}
	}
}
