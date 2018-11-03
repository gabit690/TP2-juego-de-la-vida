#include <string>
#include "Celula.h"
using namespace std;

#import "Celula.h"

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

void Celula::cambiarNuevaEnergia(unsigned int nuevaEnergia){
	//Cambiar nivel de energia
}


Color* Celula::getColor(){
	return this->color;
}
void Celula::reiniciarCelula(){
	if(this->condicion==VIVA){
		this->condicion = MUERTA;
	}
	// reiniciar energia
	this->color->asignarRojo(255);
	this->color->asignarVerde(255);
	this->color->asignarAzul(255);
}

Celula::~Celula(){
	delete this->color;
	delete this->energia;
}
