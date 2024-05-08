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
            cout << "Posicion invalida para agregar la linea." << endl;
        }else{
            int numLineasNuevo = numLineas+1;
            LineaMetro** nuevoArreglo = new LineaMetro*[numLineasNuevo];
            for (int i = 0; i < numLineasNuevo; i++) {
                if (i < posicion-1) {
                    nuevoArreglo[i] = lineas[i];
                } else if(i > posicion-1){
                    nuevoArreglo[i] = lineas[i-1];
                } else{
                    nuevoArreglo[i] = new LineaMetro(nombreLinea);
                }

            }
            delete[] lineas;
            lineas = nuevoArreglo;
            setNumLineas(numLineasNuevo);
        }
    }

    // Método para eliminar una línea en la posición x del arreglo líneas
    void RedMetro::eliminarLinea(const int posicion) {
        if (posicion < 1 || posicion > numLineas) {
            cout << "Posición inválida para eliminar la línea." << endl;
        }else{
            int numLineasNuevo = numLineas-1;
            LineaMetro** nuevoArreglo = new LineaMetro*[numLineasNuevo];
            for (int i = 0; i < numLineasNuevo; i++) {
                if (i < (posicion-1)) {
                    nuevoArreglo[i] = lineas[i];
                } else {
                    nuevoArreglo[i] = lineas[i+1];
                }
            }
            delete[] lineas;
            lineas = nuevoArreglo;
            setNumLineas(numLineasNuevo);
        }
    }

    // Método para eliminar una línea en la posición x del arreglo líneas
    void RedMetro::eliminarLinea(const string& nombreLinea) {
        bool nombreExiste = false;
        int posicionNombre;
        for (int i = 0; i < numLineas; i++) {
            if (lineas[i]->getNombre() == nombreLinea) {
                posicionNombre = i;
                nombreExiste = true;
            }
        }
        if (nombreExiste) {

            cout << "posiciones del nombre: " << posicionNombre;
            int numLineasNuevo = numLineas-1;
            LineaMetro** nuevoArreglo = new LineaMetro*[numLineasNuevo];
            for (int i = 0; i < numLineasNuevo; i++) {
                if (i < posicionNombre) {
                    nuevoArreglo[i] = lineas[i];
                } else {
                    nuevoArreglo[i] = lineas[i+1];
                }
            }
            delete[] lineas;
            lineas = nuevoArreglo;
            setNumLineas(numLineasNuevo);
        }else{
            cout << "La linea con ese nombre no existe." << endl;
        }
    }

    /*const int getNumEstaciones(){
     *
    }

    int RedMetro::contarEstacionesRed() const {
        int totalEstaciones = 0;
        for (int i = 0; i < numLineas; i++) {
            totalEstaciones += lineas[i]->getNumEstaciones();
        }
        return totalEstaciones;
    }

    bool RedMetro::estacionPerteneceALinea(const string& nombreEstacion, const string& nombreLinea) const {
        for (int i = 0; i < numLineas; i++) {
            if (lineas[i]->getNombre() == nombreLinea) {
                return lineas[i]->buscarEstacion(nombreEstacion);
            }
        }
        return false;
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
