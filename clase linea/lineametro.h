#ifndef LINEAMETRO_H
#define LINEAMETRO_H
#include<string>
#include<iostream>
using namespace std;

class LineaMetro {
private:
    int** arregloDelineametro; // Arreglo de arreglos dinámico
    int* tamanos; // Arreglo para almacenar los tamaños de los subarreglos
    int numArreglos; // Número de arreglos almacenados en el arreglo principal

public:
    // Constructor
    LineaMetro() : arregloDelineametro(nullptr), tamanos(nullptr), numArreglos(0) {}

    // Destructor
    ~LineaMetro() {
        // Liberar la memoria asignada
        for (int i = 0; i < numArreglos; ++i) {
            delete[] arregloDelineametro[i];
        }
        delete[] arregloDelineametro;
        delete[] tamanos;
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
    void imprimirArregloDelineametro() {
        cout << "Subarreglos almacenados en el arreglo de arreglos:" << endl;
        for (int i = 0; i < numArreglos; ++i) {
            for (int j = 0; j < tamanos[i]; ++j) {
                cout << arregloDelineametro[i][j] << " ";
            }
        }
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
    void apartadocrearestacion() {
        int tamano;
        cout << "Ingrese el tamaño del arreglo: ";
        cin >> tamano;

        int* miArreglo = crearEstacion(tamano);

        // Imprimir el arreglo dinámico
        cout << "Arreglo ingresado:" << endl;
        for (int i = 0; i < tamano; ++i) {
            cout << miArreglo[i] << " ";
        }
        cout << endl;

        // Liberar la memoria asignada
        delete[] miArreglo;
    }
};



#endif // LINEAMETRO_H
