#include "LineaMetro.h"
#include "EstacionMetro.h"

#include <string>
#include <iostream>

using namespace std;

// Constructor que crea una linea de metro con dos estaciones predeterminadas
LineaMetro::LineaMetro(const string& nombreLinea) : nombreLinea(nombreLinea), numEstaciones(2) {
    estaciones = new EstacionMetro*[numEstaciones];
    estaciones[0] = new EstacionMetro("Estacion 1");
    estaciones[1] = new EstacionMetro("Estacion 2");
}

// Constructor que crea una linea de metro con el nombre y una cantidad inicial de estaciones
LineaMetro::LineaMetro(const string& nombreLinea, unsigned short int  numEstaciones) : nombreLinea(nombreLinea), numEstaciones(numEstaciones) {
    estaciones = new EstacionMetro*[numEstaciones];
    for (int i = 0; i < numEstaciones; i++) {
        estaciones[i] = new EstacionMetro("Estacion " + to_string(i));
    }
}

const string LineaMetro::getNombre(){

    return nombreLinea;
}

const int LineaMetro::getNumEstaciones(){
    return numEstaciones;
}

void LineaMetro::setNombre(const string& nuevoNombre) {
    nombreLinea = nuevoNombre;
}

void LineaMetro::setNumEstaciones(const unsigned short int& nuevoNumEstaciones) {
    numEstaciones = nuevoNumEstaciones;
}

// Método para agregar una línea al final del arreglo líneas
void LineaMetro::agregarEstacion(const string& nombreEstacionNueva) {
    int numEstacionesNuevo = numEstaciones+1;
    EstacionMetro** nuevoArreglo = new EstacionMetro*[numEstaciones];
    for (int i = 0; i < numEstaciones; i++) {
        nuevoArreglo[i] = estaciones[i];
    }
    delete[] estaciones;
    nuevoArreglo[numEstaciones] = new EstacionMetro(nombreEstacionNueva);
    estaciones = nuevoArreglo;

    setNumEstaciones(numEstacionesNuevo);
}


// Método para agregar una línea en la posición x del arreglo líneas
void LineaMetro::agregarEstacion(const string& nombreEstacionNueva, int posicion) {
    if (posicion < 0 || posicion > numEstaciones) {
        cout << "Posicion invalida para agregar la Estacion." << endl;
    }else{
        int numEstacionesNuevo = numEstaciones+1;
        EstacionMetro** nuevoArreglo = new EstacionMetro*[numEstacionesNuevo];
        for (int i = 0; i < numEstacionesNuevo; i++) {
            if (i < posicion-1) {
                nuevoArreglo[i] = estaciones[i];
            } else if(i > posicion-1){
                nuevoArreglo[i] = estaciones[i-1];
            } else{
                nuevoArreglo[i] = new EstacionMetro(nombreEstacionNueva);
            }

        }
        delete[] estaciones;
        estaciones = nuevoArreglo;
        setNumEstaciones(numEstacionesNuevo);
    }
}
// Método para eliminar una línea en la posición x del arreglo líneas
void LineaMetro::eliminarEstacion(const int posicion) {
    if (posicion < 1 || posicion > numEstaciones) {
        cout << "Posición inválida para eliminar la línea." << endl;
    }else{
        int numEstacionesNuevo = numEstaciones-1;
        EstacionMetro** nuevoArreglo = new EstacionMetro*[numEstacionesNuevo];
        for (int i = 0; i < numEstacionesNuevo; i++) {
            if (i < (posicion-1)) {
                nuevoArreglo[i] = estaciones[i];
            } else {
                nuevoArreglo[i] = estaciones[i+1];
            }
        }
        delete[] estaciones;
        estaciones = nuevoArreglo;
        setNumEstaciones(numEstacionesNuevo);
    }
}
