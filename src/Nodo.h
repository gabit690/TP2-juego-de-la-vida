#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif

template<class T> class Nodo {

    private:

        T dato;
        Nodo<T>* siguiente;

    public:

        /*
         * POST: el Nodo resulta inicializado con el dato dado
         *       y sin un Nodo siguiente.
         */
        Nodo(T dato) {
            this->dato = dato;
            this->siguiente = NULL;
        }

        /*
         * POST: devuelve el valor del dato.
         */
        T obtenerDato() {
            return this->dato;
        }

        /*
         * POST: cambia el valor del dato.
         */
        void cambiarDato(T nuevoDato) {
            this->dato = nuevoDato;
        }

        /*
         * POST: devuelve el siguiente Nodo.
         */
        Nodo<T>* obtenerSiguiente() {
            return this->siguiente;
        }

        /*
         * POST: cambia el siguiente Nodo por nuevoSiguiente.
         */
        void cambiarSiguiente(Nodo<T>* nuevoSiguiente) {
            this->siguiente = nuevoSiguiente;
        }
};

#endif /* NODO_H_ */
