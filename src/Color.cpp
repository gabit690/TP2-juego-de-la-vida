#include "Color.h"

Color::Color(int red, int green, int blue) {
	this->red = red;
	this->green = green;
	this->blue = blue;
}

Color::~Color() {
	// TODO Auto-generated destructor stub
}

int Color::getBlue() const {
	return blue;
}

void Color::setBlue(int blue) {
	this->blue = blue;
}

int Color::getGreen() const {
	return green;
}

void Color::setGreen(int green) {
	this->green = green;
}

int Color::getRed() const {
	return red;
}

void Color::setRed(int red) {
	this->red = red;
}
