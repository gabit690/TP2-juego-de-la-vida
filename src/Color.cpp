#include "Color.h"

Color::Color(ebmpBYTE rojo, ebmpBYTE verde, ebmpBYTE azul){

	this->colores = new RGBApixel;
	this->colores->Red = rojo;
	this->colores->Green = verde;
	this->colores->Blue = azul;
}

Color::Color(Color* otroColor){

	this->colores = new RGBApixel;
	this->colores->Red = otroColor->colores->Red;
	this->colores->Green = otroColor->colores->Green;
	this->colores->Blue = otroColor->colores->Blue;
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

void Color::asignarColorAleatorio(){

	this->colores->Red = (unsigned char)(std::rand() % 255);
	this->colores->Green = (unsigned char)(std::rand() % 255);
	this->colores->Blue = (unsigned char)(std::rand() % 255);
}

bool Color::sonLosMismosColores(Color* unColor){
	bool sonIguales = (this->colores->Red==unColor->obtenerRojo())&&
			(this->colores->Green==unColor->obtenerVerde())&&
			(this->colores->Blue==unColor->obtenerAzul());
	return sonIguales;
}

Color::~Color(){

	delete this->colores;
}





