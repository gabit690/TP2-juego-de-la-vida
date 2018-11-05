#include "Celula.h"

Celula::Celula(){
	this->condicion = MUERTA;
	this->color = new Color(255, 255, 255);
	this->energia = new Energia();
}

void Celula::reanimarCelula(){
	this->condicion = PORVIVIR;
}

void Celula::revivirCelula(){
	this->condicion = VIVA;
}

void Celula::infectarCelula(){
	this->condicion = PORMORIR;
}

void Celula::matarCelula(){
	this->condicion = MUERTA;
}

bool Celula::estaMuerta(){
	return (this->condicion==MUERTA);
}

bool Celula::estaPorRevivir(){
	return (this->condicion==PORVIVIR);
}

bool Celula::estaViva(){
	return (this->condicion==VIVA);
}

bool Celula::estaPorMorir(){
	return (this->condicion==PORMORIR);
}

void Celula::cambiarColorDeLaCelula(ebmpBYTE rojo, ebmpBYTE verde, ebmpBYTE azul){
	this->color->asignarRojo(rojo);
	this->color->asignarVerde(verde);
	this->color->asignarAzul(azul);
}

void Celula::aumentarEnergia(float nuevaEnergia){
	this->energia->sumarEnergia(nuevaEnergia);
}

void Celula::reducirEnergia(float nuevaEnergia){
	this->energia->restarEnergia(nuevaEnergia);
}

Color* Celula::getColor(){
	return this->color;
}

Celula::~Celula(){
	delete this->color;
	delete this->energia;
}
