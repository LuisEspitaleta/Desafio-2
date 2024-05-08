#include <string>
#include <iostream>
#include "RedMetro.h"
#include "LineaMetro.h"

using namespace std;

    // Constructor que crea una red de metro con una línea predeterminada
    RedMetro::RedMetro(const string& nombreRed) : nombreRed(nombreRed), numLineas(1) {
        lineas = new LineaMetro*[1];
        lineas[0] = new LineaMetro("Linea A");
    }

    // Constructor que crea una red de metro con el nombre y una cantidad inicial de líneas
    RedMetro::RedMetro(const string& nombreRed, unsigned short int  numLineas) : nombreRed(nombreRed), numLineas(numLineas) {
        lineas = new LineaMetro*[numLineas];
        char nombre = 'A';
        for (int i = 0; i < numLineas; i++) {
            lineas[i] = new LineaMetro("Linea " + string(1, nombre++));
        }
    }

    const string RedMetro::getNombre(){
        return nombreRed;
    }

    void RedMetro::setNombreRed(const string& nuevoNombre) {
        nombreRed = nuevoNombre;
    }

    void RedMetro::setNumLineas(const unsigned short int& nuevoNumLineas) {
        numLineas = nuevoNumLineas;
    }

    // Método para obtener una línea por índice
    const string RedMetro::getNombreLinea(int index){
        string nombreLinea = lineas[index]->getNombre();
        return nombreLinea;
    }

    // Método para agregar una línea al final del arreglo líneas
    void RedMetro::agregarLinea(const string& nombreLinea) {
        int numLineasNuevo = numLineas+1;
        LineaMetro** nuevoArreglo = new LineaMetro*[numLineasNuevo];
        for (int i = 0; i < numLineas; i++) {
            nuevoArreglo[i] = lineas[i];
        }
        delete[] lineas;
        nuevoArreglo[numLineas] = new LineaMetro(nombreLinea);
        lineas = nuevoArreglo;

        setNumLineas(numLineasNuevo);
    }


    // Método para agregar una línea en la posición x del arreglo líneas
    void RedMetro::agregarLinea(const string& nombreLinea, int posicion) {
        if (posicion < 0 || posicion > numLineas) {
            cout << "Posición inválida para agregar la línea." << endl;
            return;
        }

        int numLineasNuevo = numLineas+1;
        LineaMetro** nuevoArreglo = new LineaMetro*[numLineasNuevo];
        for (int i = 0; i < numLineas; i++) {
            nuevoArreglo[i] = lineas[i];
        }
        delete[] lineas;
        lineas = nuevoArreglo;

        for (int i = numLineas; i > posicion-1; i--) {
            lineas[i] = lineas[i - 1];
        }

        nuevoArreglo[posicion] = new LineaMetro(nombreLinea);
        lineas = nuevoArreglo;

        setNumLineas(numLineasNuevo);
    }
    /*const int getNumEstaciones(){
     *
    }



*/

    int RedMetro::contarLineas() const {
        return numLineas;
    }

/*


    // Destructor
    RedMetro::~RedMetro() {
        for (int i = 0; i < numLineas; i++) {
            delete lineas[i];
        }
        delete[] lineas;
    }
*/
