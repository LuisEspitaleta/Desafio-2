#include "LineaMetro.h"
#include <string>
#include <iostream>

using namespace std;

LineaMetro::LineaMetro(const string& nombre) : nombre(nombre), numEstaciones(2) {
    
}

LineaMetro::LineaMetro(const string& nombre, unsigned short int numEstaciones) : nombre(nombre), numEstaciones(numEstaciones) {

}

//Getter y Setter
const string LineaMetro::getName(){
    return nombre;
}
const int LineaMetro::getNumEstaciones(){
    return numEstaciones;
}

const void LineaMetro::imprimirNombre(){
    cout << "Nombre de la estacion: " << nombre << endl;
}
const int imrprimiNumEstaciones(){
    cout << "Cantidadde la estacion: " << nombre << endl;
}


int* crearEstacion(int tamano) {
    // Crear un nuevo arreglo dinámico
    int* arreglo = new int[tamano];
    cout << "Ingrese " << tamano << " valores para llenar el arreglo:" << endl;
    for (int i = 0; i < tamano; ++i) {
        cout << "Valor " << i + 1 << ": ";
        cin >> arreglo[i];
    }
    
    return arreglo;
}

void agregarEstacion(int* nuevoArreglo, int tamanoNuevoArreglo) {
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

~LineaMetro() {
    // Liberar la memoria asignada
    for (int i = 0; i < numArreglos; ++i) {
        delete[] arregloDelineametro[i];
    }
    delete[] arregloDelineametro;
    delete[] tamanos;
}
