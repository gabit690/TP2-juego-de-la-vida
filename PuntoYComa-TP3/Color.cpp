#include "Color.h"

Color::Color(ebmpBYTE rojo, ebmpBYTE verde, ebmpBYTE azul){
	this->colores = new RGBApixel;
	this->colores->Red = rojo;
	this->colores->Green = verde;
	this->colores->Blue = azul;
}

ebmpBYTE Color::obtenerRojo(){

	return this->colores->Red;
}

ebmpBYTE Color::obtenerVerde(){

	return this->colores->Green;
}

ebmpBYTE Color::obtenerAzul(){

	return this->colores->Blue;
}

void Color::asignarRojo(ebmpBYTE nuevoRojo){

	this->colores->Red = nuevoRojo;
}

void Color::asignarVerde(ebmpBYTE nuevoVerde){

	this->colores->Green = nuevoVerde;
}

void Color::asignarAzul(ebmpBYTE nuevoAzul){

	this->colores->Blue = nuevoAzul;
}

RGBApixel Color::obtenerPixel(){

	return *(this->colores);
}


Color::~Color(){
	delete this->colores;
}
