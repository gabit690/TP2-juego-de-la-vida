#include "MapaDeBits.h"
#include <sstream>
#include <iomanip>

MapaDeBits::MapaDeBits(unsigned int ancho, unsigned int alto){
	this->imagen = new BMP;
	this->alto = alto;
	this->ancho = ancho;
	this->imagen->SetSize(ancho, alto);
}

void MapaDeBits::asignar(unsigned int columna, unsigned int fila, Color* nuevoColor){
	//this->imagen->SetPixel(columna, (this->alto - 1) - fila, nuevoColor->obtenerPixel());
}

void MapaDeBits::escribir(std::string nombreDeArchivo, unsigned int version){
	std::stringstream unNumero;
	unNumero << std::setfill('0') << std::setw(4) << version;
	std::string nombreDeArchivoConVersion = nombreDeArchivo + unNumero.str() +".bmp";
	this->imagen->WriteToFile(nombreDeArchivoConVersion.c_str());
}

MapaDeBits::~MapaDeBits() {
	delete this->imagen;
}
