#include <string>
#include "Color.h"
#include "Energia.h"
#include "Celula.h"
using namespace std;


Celula::Celula(bool estadoInicial,Energia energiaInicial,Color colorInicial){
	energia=energiaInicial;
	estadoActual=estadoInicial;
	color=colorInicial;
}

void Celula::cambiarEstadoDeLaCelula(){
	if (estadoActual=="viva"){
		estadoActual="muerta";
	}else{
		estadoActual="viva";
	}
}

void Celula::cambiarColorDeLaCelula(Color nuevoColor){
	color=nuevoColor;
}

void Celula::cambiarEnergia(Energia nuevaEnergia){
	energia=nuevaEnergia;
}
void Celula::setProximoEstado(string estado){
	this->proximoEstado=estado;
}
void Celula::setEstadoActual(string estado){
	this->estadoActual=estado;
}
string Celula::getEstadoActual(){
	return estadoActual;
}
string Celula::getProximoEstado(){
	return proximoEstado;
}

Celula* Celula::crearCopiaDeLaCelula(Celula* celulaACopiar){
	Celula* nuevaCopia;
	nuevaCopia->color=celulaACopiar->color;
	nuevaCopia->energia=celulaACopiar->energia;
	nuevaCopia->estadoActual=celulaACopiar->estadoActual;
	return nuevaCopia;
}
Celula::~Celula();
