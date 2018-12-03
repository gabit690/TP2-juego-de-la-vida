/*
 * JuegoDeLaVida.cpp
 *
 *  Created on: 2 nov. 2018
 *      Author: gabit
 */

#include "JuegoDeLaVida.h"
using namespace std;

JuegoDeLaVida::JuegoDeLaVida(){
	this->elEnfermero = new Enfermero();
	this->elDibujante = new Dibujante();
	this->losTableros = new Lista<Tablero*>();
	this->losPortales = new Lista<Portal*>();;
	this->laPantalla = new Interfaz;
	this->losInformes = new Informe();
	this->elGrafo = new Grafo();
}

void JuegoDeLaVida::jugar(){
	this->laPantalla->mostrarBienvenida();
	ifstream archivoInicial;
	ingresarRutaDelArchivo(archivoInicial);
	procesarArchivo(archivoInicial);
	this->configurarGrafo();
	unsigned int turno = 0;
	this->elDibujante->dibujarTableros(this->losTableros, turno);
	bool terminar = false;
	do{
		comenzarUnaPartida(terminar);
	}while(!terminar);
}

void JuegoDeLaVida::configurarGrafo(){
	this->ingresarVertices(this->losTableros);
	this->ingresarAristas(this->losPortales);
}

void JuegoDeLaVida::ingresarVertices(Lista<Tablero*>* tableros){
	tableros->iniciarCursor();
	while(tableros->avanzarCursor()){
		Tablero* unTablero;
		unTablero = tableros->obtenerCursor();
		this->elGrafo->agregarUnVertice(unTablero->obtenerNombre());
	}
}

void JuegoDeLaVida::ingresarAristas(Lista<Portal*>* portales){
	portales->iniciarCursor();
	while(portales->avanzarCursor()){
		Portal* unPortal;
		unPortal = portales->obtenerCursor();

		string inicioDeArista = unPortal->getNombreTableroOrigen();
		string finalDeArista = unPortal->getNombreTableroDestino();

		this->elGrafo->agregarUnaArista(inicioDeArista, finalDeArista, unPortal);

		if(unPortal->esPortalActivo()){
			this->elGrafo->agregarUnaArista(finalDeArista, inicioDeArista, unPortal);
		}

	}
}

void JuegoDeLaVida::ingresarRutaDelArchivo(ifstream& archivo){
	string nombreDeArchivo;
	bool salirDelBucle = false;
	do
	{
		this->laPantalla->pedirRutaDeUnArchivo();
		cin >> nombreDeArchivo;
		cin.ignore(256,'\n');

		archivo.open(nombreDeArchivo.c_str());

		salirDelBucle = archivo.is_open();
		if(!salirDelBucle)
		{
			this->laPantalla->mostrarQueElArchivoNoExiste();
		}

	}while(salirDelBucle == false);
}

void JuegoDeLaVida::procesarArchivo(ifstream& archivo){
	string tipoDeOperacion;
	unsigned int celulasVivas = 0 ;
	while(!archivo.eof()){
		archivo >> tipoDeOperacion;

		if(tipoDeOperacion.compare("Tablero") == 0){
			agregarUnTablero(archivo);
		}
		if(tipoDeOperacion.compare("Parcela") == 0){
			configurarUnaParcela(archivo);
		}
		if(tipoDeOperacion.compare("Portal") == 0){
			agregarUnPortal(archivo);
		}
		if(tipoDeOperacion.compare("CelulaViva") == 0){
			setearUnaCelulaViva(archivo);
			celulasVivas++;
		}
		// std::cin.ignore(); // Limpiar el buffer para los registro de celulas vivas!!!!!!!!
	}
	this->losInformes->setCelulasVivas(celulasVivas);
	archivo.close();
}

void JuegoDeLaVida::agregarUnTablero(ifstream& archivo){
	string nombreTablero;
	unsigned int ancho;
	unsigned int alto;
	archivo >> nombreTablero;
	archivo >> ancho;
	archivo >> alto;
	Tablero* unTablero;
	unTablero = new Tablero(nombreTablero, ancho, alto);
	this->losTableros->agregar(unTablero);
}

void JuegoDeLaVida::configurarUnaParcela(ifstream& archivo){
	string nombreTablero;
	unsigned int columna;
	unsigned int fila;
	unsigned int cantidadRojo;
	unsigned int cantidadVerde;
	unsigned int cantidadAzul;
	float tasaNatilidad;
	float tasaMortalidad;

	archivo >> nombreTablero;
	archivo >> columna;
	archivo >> fila;
	archivo >> cantidadRojo;
	archivo >> cantidadVerde;
	archivo >> cantidadAzul;
	archivo >> tasaNatilidad;
	archivo >> tasaMortalidad;

	Tablero* elTablero;
	elTablero = obtenerUnTableroCreado(nombreTablero);
	Parcela* laParcela;
	laParcela = elTablero->obtenerParcela(columna, fila);
	laParcela->setearColorDeParcela(cantidadRojo, cantidadVerde, cantidadAzul);
	laParcela->setTasaDeNatalidad(tasaNatilidad);
	laParcela->setTasaDeMortalidad(tasaMortalidad);
}

Tablero* JuegoDeLaVida::obtenerUnTableroCreado(string nombreTablero){
	bool encontrado = false;
	Tablero* unTablero;
	this->losTableros->iniciarCursor();
	while(this->losTableros->avanzarCursor()&&!encontrado){
		unTablero = this->losTableros->obtenerCursor();
		encontrado = (!unTablero->obtenerNombre().compare(nombreTablero));
	}
	return unTablero;
}

void JuegoDeLaVida::agregarUnPortal(ifstream& archivo){
	string tipo;

	string nombreTableroOrigen;
	unsigned int columnaOrigen;
	unsigned int filaOrigen;

	string nombreTableroDestino;
	unsigned int columnaDestino;
	unsigned int filaDestino;

	archivo >> tipo;
	archivo >> nombreTableroOrigen;
	archivo >> columnaOrigen;
	archivo >> filaOrigen;
	archivo >> nombreTableroDestino;
	archivo >> columnaDestino;
	archivo >> filaDestino;

	Tablero* tableroOrigen;
	tableroOrigen = obtenerUnTableroCreado(nombreTableroOrigen);
	Parcela* parcelaOrigen;
	parcelaOrigen = tableroOrigen->obtenerParcela(columnaOrigen, filaOrigen);

	Tablero* tableroDestino;
	tableroDestino = obtenerUnTableroCreado(nombreTableroDestino);
	Parcela* parcelaDestino;
	parcelaDestino = tableroDestino->obtenerParcela(columnaDestino, filaDestino);

	Portal* nuevoPortal;
	TipoDePortal elTipo;
	elTipo = determinarTipoDePortal(tipo);
	nuevoPortal = new Portal(nombreTableroOrigen, nombreTableroDestino, parcelaOrigen, parcelaDestino, elTipo);
	this->losPortales->agregar(nuevoPortal);
}

TipoDePortal JuegoDeLaVida::determinarTipoDePortal(std::string tipoDePortal){
	TipoDePortal tipoParaAsignar;
	if(tipoDePortal.compare("Activo")==0){
		tipoParaAsignar = ACTIVO;
	}
	else{
		if(tipoDePortal.compare("Normal")==0){
			tipoParaAsignar = NORMAL;
		}
		else{
			tipoParaAsignar = PASIVO;
		}
	}
	return tipoParaAsignar;
}

void JuegoDeLaVida::setearUnaCelulaViva(std::ifstream& archivo){
	string nombreTablero;
	unsigned int columna;
	unsigned int fila;

	archivo  >> nombreTablero;
	archivo  >> columna;
	archivo  >> fila;

	Tablero* elTablero;
	elTablero = obtenerUnTableroCreado(nombreTablero);
	Color* colorDeLaParcela;
	colorDeLaParcela = elTablero->obtenerParcela(columna, fila)->obtenerColor();
	Celula* laCelula;
	laCelula = elTablero->obtenerParcela(columna, fila)->obtenerCelula();
	laCelula->cambiarColorDeLaCelula(colorDeLaParcela->obtenerRojo(), colorDeLaParcela->obtenerVerde(), colorDeLaParcela->obtenerAzul());
	laCelula->revivirCelula();
}

void JuegoDeLaVida::comenzarUnaPartida(bool &terminar){
	bool reiniciar = false;
	do{
		unsigned int numeroElegido = elegirUnaAccionDelMenuDeJuego();
		reiniciar = (numeroElegido==2); // La accion 2 del menuDeJuego reinicia la partida.
		terminar = (numeroElegido==3); // La accion 3 del menuDeJuego finaliza la partida.
		realizarAccion(numeroElegido);
	}while((!terminar)&&(!reiniciar));
}

unsigned int JuegoDeLaVida::elegirUnaAccionDelMenuDeJuego(){
	unsigned int valorIngresado;
	bool valorValido = false;
	do{
		this->laPantalla->mostrarMenuDeJuego();
		this->laPantalla->pedirEleccionDelMenuDeJuego();
		cin >> valorIngresado;
		valorValido = !((valorIngresado<=0)||(valorIngresado>3));
		if(!valorValido){
			this->laPantalla->mostrarErrorDatoInvalido();
		}
	}while(!valorValido);
	return valorIngresado;
}

void JuegoDeLaVida::realizarAccion(unsigned int numeroElegido){
	switch(numeroElegido){
	case 1:
			if(!this->losInformes->juegoCongelado()){
				unsigned int turnosElegidos;
				this->laPantalla->pedirUnaCantidadDeTurnos();
				cin >> turnosElegidos;
				ejecutarTurnos(turnosElegidos);
			}
			else{
				this->laPantalla->mostrarQueElJuegoSeCongelo();
			}
			break;
	case 2: reiniciarJuego();
			this->elDibujante->dibujarTableros(this->losTableros, this->losInformes->getTurno());
			break;
	case 3: this->procesarGrafo();
			this->laPantalla->mostrarFinalizacionDelJuego();
			break;
	}
}

void JuegoDeLaVida::procesarGrafo(){
	unsigned int tableroOrigenElegido;
	unsigned int tableroDestinoElegido;
	bool valido = false;
	do{
		tableroOrigenElegido = elegirTableroOrigen(this->losTableros->contarElementos());
		tableroDestinoElegido = elegirTableroDestino(this->losTableros->contarElementos());
		valido = (tableroOrigenElegido!=tableroDestinoElegido);
		if(!valido){
			this->laPantalla->mostrarEleccionDelMismoTablero();
		}
	}while(!valido);

	string nombreDelTableroOrigen = this->losTableros->obtener(tableroOrigenElegido)->obtenerNombre();
	string nombreDelTablerodestino = this->losTableros->obtener(tableroDestinoElegido)->obtenerNombre();
	unsigned int transferenciasDeCelulas = 0;

	Pila<string>* elCaminoMinimo;
	elCaminoMinimo = this->elGrafo->obtenerElCaminoMinimo(nombreDelTableroOrigen, nombreDelTablerodestino, transferenciasDeCelulas);

	if(transferenciasDeCelulas>0){
		this->laPantalla->mostrarCaminoMinimo(elCaminoMinimo, transferenciasDeCelulas);
	}
	else{
		this->laPantalla->mostarInexistenciaDeAlgunCaminoMinimo();
	}

	delete elCaminoMinimo; // Borro la memoria pedida para la pila por el grafo en la su funcion para obtener el camino minimo.
}

unsigned int JuegoDeLaVida::elegirTableroOrigen(unsigned int cantidadDeTableros){
	unsigned int eleccion;
	bool valida = false;

	do{
		this->laPantalla->pedirEleccionDeUnTableroOrigen(cantidadDeTableros);
		cin >> eleccion;
		valida = ((eleccion>0)&&(eleccion<=cantidadDeTableros));
		if(!valida){
			this->laPantalla->mostrarErrorDatoInvalido();
		}
	}while(!valida);

	return eleccion;
}

unsigned int JuegoDeLaVida::elegirTableroDestino(unsigned int cantidadDeTableros){
	unsigned int eleccion;
	bool valida = false;

	do{
		this->laPantalla->pedirEleccionDeUnTableroDestino(cantidadDeTableros);
		cin >> eleccion;
		valida = ((eleccion>0)&&(eleccion<=cantidadDeTableros));
		if(!valida){
			this->laPantalla->mostrarErrorDatoInvalido();
		}
	}while(!valida);

	return eleccion;
}


void JuegoDeLaVida::reiniciarJuego(){
	this->losInformes->reiniciarInformes();
	liberarPortales();
	liberarTableros();
	ifstream nuevoArchivoInicial;
	ingresarRutaDelArchivo(nuevoArchivoInicial);
	procesarArchivo(nuevoArchivoInicial);
	this->elGrafo->reiniciarGrafo();
	this->configurarGrafo();
}

void JuegoDeLaVida::ejecutarTurnos(unsigned int turnos){
	unsigned int turnoAEjecutar = 1;
	while((turnoAEjecutar<=turnos)&&(!this->losInformes->juegoCongelado())){
		this->elEnfermero->evaluarCelulas(this->losTableros);
		this->elEnfermero->actualizarCelulas(this->losTableros, this->losPortales, this->losInformes, this->elGrafo);
		this->losInformes->aumentarUnTurno();
		this->elDibujante->dibujarTableros(this->losTableros, this->losInformes->getTurno());
		this->laPantalla->mostrarInformesDelJuego(this->losInformes);
		if(this->losInformes->juegoCongelado()){
			this->laPantalla->mostrarQueElJuegoSeCongelo();
		}
		turnoAEjecutar++;
	}
}

void JuegoDeLaVida::liberarPortales(){

	while(!this->losPortales->estaVacia()){
		Portal* unPortal;
		unPortal = this->losPortales->obtener(1);
		this->losPortales->remover(1);
		delete unPortal;
	}
}

void JuegoDeLaVida::liberarTableros(){
	while(!this->losTableros->estaVacia()){
		Tablero* unTablero;
		unTablero = this->losTableros->obtener(1);
		this->losTableros->remover(1);
		delete unTablero;
	}
}

JuegoDeLaVida::~JuegoDeLaVida() {
	delete this->elEnfermero;
	delete this->elDibujante;
	liberarTableros();
	delete this->losTableros;
	liberarPortales();
	delete this->losPortales;
	delete this->laPantalla;
	delete this->losInformes;
	delete this->elGrafo;
}

