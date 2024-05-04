#include <QCoreApplication>
#include "lineametro.h"
#include <iostream>
#include <string>
int main(int argc, char *argv[])
{
    int tamano=2;
    int* miArreglo = crearEstacion(tamano);
    LineaMetro arreglo;

    // Crear dos subarreglos
    int arreglo1[] = {1, 2, 3};
    int tamanoArreglo1 = sizeof(arreglo1) / sizeof(arreglo1[0]);
    int arreglo2[] = {4, 5, 6, 7};
    int tamanoArreglo2 = sizeof(arreglo2) / sizeof(arreglo2[0]);
    creararreglo(tamano);
    // Agregar los subarreglos al arreglo de arreglos

    arreglo.agregarEstacion(arreglo1, tamanoArreglo1);
    arreglo.agregarEstacion(arreglo2, tamanoArreglo2);

    // Imprimir el arreglo de arreglos
    arreglo.imprimirArregloDelineametro();

    return 0;
}
