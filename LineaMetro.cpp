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


// Destructor
LineaMetro::~LineaMetro() {
    // Liberar la memoria asignada
    delete[] estaciones;
}

void LineaMetro::agregarEstacion(int* nuevoArreglo, int tamanoNuevoArreglo) {
    // Incrementa el tamaño del arreglo de tamaños
    int* nuevosTamanos = new int[numArreglos + 1];
    for (int i = 0; i < numArreglos; ++i) {
        nuevosTamanos[i] = tamanos[i];
    }
    nuevosTamanos[numArreglos] = tamanoNuevoArreglo;

    // Incrementa el tamaño del arreglo de arreglos
    int** nuevosArreglos = new int*[numArreglos + 1];
    for (int i = 0; i < numArreglos; ++i) {
        nuevosArreglos[i] = arregloDelineametro[i];
    }
    nuevosArreglos[numArreglos] = nuevoArreglo;

    // Libera la memoria del arreglo de tamaños y del arreglo de arreglos originales
    delete[] tamanos;
    delete[] arregloDelineametro;

    // Asigna los nuevos arreglos y tamaños al arreglo de arreglos
    tamanos = nuevosTamanos;
    arregloDelineametro = nuevosArreglos;
    numArreglos++;

}
void LineaMetro::agregarEstacion(int* nuevoArreglo, int tamanoNuevoArreglo, int posicion) {
    // Verificar si la posición especificada es válida
    if (posicion < 0 || posicion > numArreglos) {
        cout << "Posición inválida. No existe el lugar donde quiere colocar su estacion" << endl;
        return;
    }

    int* nuevosTamanos = new int[numArreglos + 1];
    for (int i = 0; i < numArreglos; ++i) {
        nuevosTamanos[i] = tamanos[i];
    }
    nuevosTamanos[numArreglos] = tamanoNuevoArreglo;

    // sube el tamaño dd arreglo
    int** nuevosArreglos = new int*[numArreglos + 1];

    // Copiar los arreglos de estacion hasta la posición especifica deseada
    for (int i = 0; i < posicion; ++i) {
        nuevosArreglos[i] = arregloDelineametro[i];
    }

    // Agregar la nueva estacion en la posición especificada
    nuevosArreglos[posicion] = nuevoArreglo;

    // Copiar las estaciones ya existentes después de la posición especificada
    for (int i = posicion; i < numArreglos; ++i) {
        nuevosArreglos[i + 1] = arregloDelineametro[i];
    }

    // Libera la memoria del arreglo de tamaños y del arreglo de arreglos originales
    delete[] tamanos;
    delete[] arregloDelineametro;

    // Asigna los nuevos arreglos y tamaños al arreglo de arreglos
    tamanos = nuevosTamanos;
    arregloDelineametro = nuevosArreglos;
    numArreglos++;
}
void LineaMetro::borrarEstacion(int posicion) {
    // Verificar si la posición especificada es válida
    if (posicion < 0 || posicion >= numArreglos) {
        cout << "Posición inválida. No se pudo borrar el arreglo." << endl;
        return;
    }

    // Decrementar el tamaño del arreglo de tamaños
    int* nuevosTamanos = new int[numArreglos - 1];
    for (int i = 0, j = 0; i < numArreglos; ++i) {
        if (i != posicion) {
            nuevosTamanos[j++] = tamanos[i];
        }
    }

    // Decrementar el tamaño del arreglo de arreglos
    int** nuevosArreglos = new int*[numArreglos - 1];

    // Copiar los arreglos originales excepto el que se va a borrar
    for (int i = 0, j = 0; i < numArreglos; ++i) {
        if (i != posicion) {
            nuevosArreglos[j++] = arregloDelineametro[i];
        } else {
            // Liberar la memoria del arreglo que se va a borrar
            delete[] arregloDelineametro[i];
        }
    }

    // Libera la memoria del arreglo de tamaños y del arreglo de arreglos originales
    delete[] tamanos;
    delete[] arregloDelineametro;

    // Asigna los nuevos arreglos y tamaños al arreglo de arreglos
    tamanos = nuevosTamanos;
    arregloDelineametro = nuevosArreglos;
    numArreglos--;
}
void LineaMetro::imprimirArregloDelineametro() {
    cout << "Subarreglos almacenados en el arreglo de arreglos:" << endl;
    for (int i = 0; i < numArreglos; ++i) {
        for (int j = 0; j < tamanos[i]; ++j) {
            cout << arregloDelineametro[i][j] << " ";
        }
    }
}
/*int* crearEstacion(int tamano) {
        // Crear un nuevo arreglo dinámico
        int* arreglo = new int[tamano];
        cout << "Ingrese " << tamano << " valores para llenar el arreglo:" << endl;
        for (int i = 0; i < tamano; ++i) {
            cout << "Valor vuelta " << i + 1 << ": ";
            cin >> arreglo[i];
            ++i;
            cout << "Valor ida " << i + 1 << ": ";
            cin >> arreglo[i];
        }

        return arreglo;
    }*/
int* LineaMetro::apartadocrearestacion() {
    int tamano;
    tamano=2;
    int* miArreglo = new int[tamano];
    // Crear un nuevo arreglo dinámico
    int* arreglo = new int[tamano];
    cout << "Ingrese " << tamano << " valores para ajustar su estacion" << endl;
    int i=0;
    if(tamano==2){
        cout << "Valor vuelta " << ": ";
        cin >> arreglo[i];
    }
    i++;
    if(tamano==2){
        cout << "Valor ida " << ": ";
        cin >> arreglo[i];
    }
    // Imprimir el arreglo dinámico
    cout << "distancia a la anterior estacion y siguiente, respectivamente:" << endl;
    for (int i = 0; i < tamano; ++i) {
        cout << miArreglo[i] << "--";
    }
    cout << endl;

    // Liberar la memoria asignada
    delete[] miArreglo;
    return arreglo;
}
void menu(){
    cout<<"Escoja entre las siguientes opciones"<<endl<<endl;
    cout<<"1: Agregar enrutadores "<<endl;
    cout<<"-- Eliminar enrutadores "<<endl;
    cout<<"-- Modificar tabla de algun enrutador "<<endl;
    cout<<"-- Saber cuanto cuesta envier un paquete a cierta ubicacion"<<endl;
    cout<<"2: Saber el camino correcto para que un paquete llegue bien"<<endl;
    cout<<"3: Salir del menu :"<<endl<<endl;
}
