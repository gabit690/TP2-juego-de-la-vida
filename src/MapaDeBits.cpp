#include "MapaDeBits.h"
using namespace std;

MapaDeBits::MapaDeBits(unsigned int ancho, unsigned int alto){
	this->imagen = new BMP;
	this->alto = alto;
	this->ancho = ancho;
	this->imagen->SetSize(ancho, alto);
	this->imagen->SetBitDepth(24);
}

void MapaDeBits::asignar(unsigned int pixelX, unsigned int pixelY, Color* nuevoColor){
	this->imagen->SetPixel(pixelX, pixelY, nuevoColor->obtenerPixel());
}

void MapaDeBits::escribir(string nombreDeArchivo){
	string nombre = (nombreDeArchivo+".BMP");
	this->imagen->WriteToFile(nombre.c_str());
}

MapaDeBits::~MapaDeBits() {
	delete this->imagen;
}
