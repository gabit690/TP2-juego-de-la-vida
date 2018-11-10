#include "Energia.h"

Energia::Energia(){
	this->energiaTotal = 0;
}

void Energia::sumarEnergia(float valor){
	float nuevaEnergia = this->energiaTotal+valor;
	if(nuevaEnergia>100){
		this->energiaTotal = 100;
	}
	else{
		this->energiaTotal = nuevaEnergia;
	}
}

void Energia::restarEnergia(float valor){
	float nuevaEnergia = this->energiaTotal-valor;
	if(nuevaEnergia<0){
		this->energiaTotal = 0;
	}
	else{
		this->energiaTotal = nuevaEnergia;
	}
}
