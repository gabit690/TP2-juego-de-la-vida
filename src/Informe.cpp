
#include "Informe.h"

Informe::Informe() {
	this->turno = 0;
	this->celulasVivas = 0;
	this->nacimientos = 0;
	this->nacimientosTotales = 0;
	this->muertes = 0;
	this->muertesTotales = 0;
	this->turnosSeguidosSinCambios = 0;
}

void Informe::aumentarUnTurno(){
	this->turno++;
}

void Informe::setCelulasVivas(unsigned int valor){
	this->celulasVivas = valor;
}

void Informe::setNacimientos(unsigned int valor){
	this->nacimientos = valor;
}

void Informe::aumentarNacimientosTotales(unsigned int valor){
	this->nacimientosTotales+=valor;
}

void Informe::setMuertes(unsigned int valor){
	this->muertes = valor;
}

unsigned int Informe::getTurno(){
	return this->turno;
}

unsigned int Informe::getCelulasVivas(){
	return this->celulasVivas;
}

unsigned int Informe::getNacimientos(){
	return this->nacimientos;
}

unsigned int Informe::getNacimientosTotales(){
	return this->nacimientosTotales;
}

unsigned int Informe::getMuertes(){
	return this->muertes;
}

unsigned int Informe::getMuertesTotales(){
	return this->muertesTotales;
}

void Informe::aumentarMuertesTotales(unsigned int valor){
	this->muertesTotales+=valor;
}

void Informe::reiniciarInformes(){
	this->turno = 0;
	this->celulasVivas = 0;
	this->nacimientos = 0;
	this->nacimientosTotales = 0;
	this->muertes = 0;
	this->muertesTotales = 0;
	this->turnosSeguidosSinCambios = 0;
}

void Informe::verificarCambios(){
	bool hayCambios = (this->nacimientos!=0)||(this->muertes!=0);
	if(!hayCambios){
		this->turnosSeguidosSinCambios++;
	}else{
		this->turnosSeguidosSinCambios = 0;
	}
}

bool Informe::juegoCongelado(){
	return (this->turnosSeguidosSinCambios==2);
}

