
#include "JuegoDeLaVida.h"

int main(){
	JuegoDeLaVida* elJuego;
	elJuego = new JuegoDeLaVida();
	elJuego->jugar();
	delete elJuego;
	return 0;
}
