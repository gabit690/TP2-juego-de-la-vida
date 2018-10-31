/*
 * Celula.h
 *
 *  Created on: 6 sep. 2018
 *      Author: gabit
 */

#ifndef CELULA_H_
#define CELULA_H_

enum EstadoDeLaCelula {
	MUERTA,
	PORVIVIR,
	VIVA,
	PORMORIR,
};

/* Unidad basica que compone un organismo.
 * Su condicion esta representada por un tipo de dato enumerado
 * que puede variar entre:
 * 	 MUERTA: una celula sin vida.
 *	 PORVIVIR: una celula sin vida que esta apunto de revivir.
 *	 VIVA: una celula con vida.
 *	 PORMORIR: una celula con vida que esta apunto de morir.
 */
struct Celula{
	EstadoDeLaCelula condicion;
};

//PRE: -.
//POST: Se inicializa una celula con la condicion MUERTA.
void inicializarCelula(Celula &unaCelula);

//PRE: La condicion de la celula es MUERTA.
//POST: La celula esta PORVIVIR.
void reanimarCelula(Celula &unaCelula);

//PRE: La condicion de la celula es PORVIVIR.
//POST: La celula esta VIVA.
void revivirCelula(Celula &unaCelula);

//PRE: La condicion de la celula es VIVA.
//POST: La celula esta PORMORIR.
void infectarCelula(Celula &unaCelula);

//PRE: La condicion de la celula es PORMORIR.
//POST: La celula esta MUERTA.
void matarCelula(Celula &unaCelula);

//PRE: -.
//POST: Devuelve true si la celula esta muerta.
bool estaMuerta(Celula &unaCelula);

//PRE: -.
//POST: Devuelve true si la celula esta por revivir.
bool estaPorRevivir(Celula &unaCelula);

//PRE: -.
//POST: Devuelve true si la celula esta viva.
bool estaViva(Celula &unaCelula);

//PRE: -.
//POST: Devuelve true si la celula esta por morir.
bool estaPorMorir(Celula &unaCelula);

//PRE: La condicion de la celula es VIVA.
//POST: Se reinicia una celula con la condicion MUERTA.
void reiniciarCelula(Celula &unaCelula);

#endif /* CELULA_H_ */
