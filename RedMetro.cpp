#include <iostream>
#include "LineaMetro.h"

using namespace std;

class RedMetro {
private:
    string nombreRed;
    LineaMetro** lineas;     // Arreglo dinámico de punteros a LineaMetro
    unsigned short int numLineas;
    int capacidad = 20;

public:
    // Constructor que crea una red de metro con una línea predeterminada
    RedMetro(const string& nombreRed) : nombreRed(nombreRed), numLineas(1) {
        lineas = new LineaMetro*[numLineas];
    }

    // Constructor que crea una red de metro con el nombre y una cantidad inicial de líneas
    RedMetro(const string& nombreRed, unsigned short int  numLineas) : nombreRed(nombreRed), numLineas(numLineas) {
        lineas = new LineaMetro*[numLineas];
    }

    // Método para agregar una línea al final del arreglo de líneas
    void agregarLinea(const LineaMetro& nuevaLinea) {
        if (numLineas < capacidad) {
            lineas[numLineas++] = new LineaMetro(nuevaLinea);
        } else {
            // Implementar código para aumentar la capacidad del arreglo si es necesario
            cout << "No se puede agregar más líneas. El arreglo está lleno." << std::endl;
        }
    }

    void agregarLinea(const LineaMetro& nuevaLinea, int posicion) {
        if (posicion >= 0 && posicion <= numLineas && numLineas < capacidad) {
            // Desplazar las líneas existentes hacia la derecha para hacer espacio en la posición deseada
            for (int i = numLineas; i > posicion; i--) {
                lineas[i] = lineas[i - 1];
            }
            // Agregar la nueva línea en la posición especificada
            lineas[posicion] = new LineaMetro(nuevaLinea);
            numLineas++;
        } else {
            cout << "Posición inválida para agregar la línea." << std::endl;
        }
    }

    ~RedMetro() {
        // Liberar la memoria asignada a las líneas de metro
        for (int i = 0; i < numLineas; i++) {
            delete lineas[i];
        }
    }
};
