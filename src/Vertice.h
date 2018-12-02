/*
 * Vertice.h
 *
 *  Created on: 29 nov. 2018
 *      Author: gabit
 */

#ifndef VERTICE_H_
#define VERTICE_H_

#include "Lista.h"
#include "Etiqueta.h"
#include "Arista.h"

class Vertice {

private:
	std::string identificador;
	Etiqueta* suEtiqueta;
	Lista<Arista*>* aristasAdyacentes;

public:
	/* Pre: -.
	 * Post: crea un vertice identificado por 'nombre' con las listas de etiquetas y aristas adyacentes vacias.
	 */
	Vertice(std::string nombre);

	/* Pre: nuevaDistanciaAcumulada >= 0.
	 * Post: compara la etiqueta del vertice con los datos de una nueva etiqueta y la cambia si la nueva
	 * etiqueta tiene una menor distancia acumulada.
	 */
	void compararEtiqueta(unsigned int nuevaDistanciaAcumulada, std::string elementoAnterior);

	/* Pre: 'unaArista' esta inicialiazda y tiene como origen al identificador del vertice.
	 * Post: agrega una arista que es adyacente al vertice.
	 */
	void agregarAristaAdyacente(Arista* unaArista);

	/* Pre: -.
	 * Post: indica si tiene aristas adyacentes.
	 */
	bool tieneAristasAdayacentes();

	/* Pre: -.
	 * Post: devuelve su etiqueta.
	 */
	Etiqueta* getEtiqueta();

	/* Pre: -.
	 * Post: devuelve la lista de aristas adyacentes.
	 */
	Lista<Arista*>* getAdyacentes();

	/* Pre: -.
	 * Post: devuelve el identificador del vertice.
	 */
	std::string getIdentificador();

	/* Pre: -.
	 * Post: Indica si el vertice esta estiquetado.
	 */
	bool estaEtiquetada();

	/* Pre: -.
	 * Post: libera los recursos de memoria pedidos.
	 */
	~Vertice();
};

#endif /* VERTICE_H_ */
