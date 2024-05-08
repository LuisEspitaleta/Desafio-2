#include <iostream>
#include <string>
#include "RedMetro.h"

using namespace std;

int main()
{

    string nombreRedMetro;
    char crearMasLineas;
    int cantidadLineas = 1; // Por defecto, se crea al menos una línea

    // Solicitar nombre de la red de metro
    cout << "Ingrese el nombre de la red de metro: ";
    getline(cin, nombreRedMetro);
    cout << nombreRedMetro << endl;
    // Preguntar si desea crear más de una línea de metro
    cout << "Desea crear mas de una linea de metro? (S/N): ";
    cin >> crearMasLineas;

    if (crearMasLineas == 'S' || crearMasLineas == 's') {
        cout << "Cuantas lineas de metro desea crear? : ";
        cin >> cantidadLineas;
    }

    // Crear la instancia de RedMetro
    RedMetro redMetro(nombreRedMetro, cantidadLineas);

    // Mostrar resumen de la red de metro creada
    cout << "\nResumen de la red de metro \"" << redMetro.getNombre() << "\":" << endl;
    cout << "Numero total de lineas: " << redMetro.contarLineas() << endl;
    cout << "\nNombre de las lineas guardadas en la red de metro \"" << redMetro.getNombre() << "\":" << endl;
    for (int i = 0; i < redMetro.contarLineas(); ++i) {
        cout << "Linea " << (i + 1) << ": " << redMetro.getNombreLinea(i) << endl;
    }
    //cout << "Número total de estaciones en la red: " << redMetro.contarEstacionesRed() << endl;

    // Ejemplo de verificación de pertenencia de estación a una línea
    string nombreLineaNueva;
    cout << "\nIngrese el nombre de la nueva linea a agregar: ";
    cin.ignore();
    getline(cin, nombreLineaNueva);
    redMetro.agregarLinea(nombreLineaNueva);

    cout << "\nNombre de las lineas actulizada en la red de metro \"" << redMetro.getNombre() << "\":" << endl;
    cout << "Numero total de lineas: " << redMetro.contarLineas() << endl;
    for (int i = 0; i < redMetro.contarLineas(); ++i) {
        cout << "Linea " << (i + 1) << ": " << redMetro.getNombreLinea(i) << endl;
    }

    int posicionLineaNueva;
    cout << "\nIngrese el nombre de la nueva linea a agregar con posicion: ";
    cin.clear();
    getline(cin, nombreLineaNueva);
    cout << "\nAgregar la posicion: ";
    cin >> posicionLineaNueva;
    redMetro.agregarLinea(nombreLineaNueva, posicionLineaNueva);

    cout << "\nNombre de las lineas actulizada en la red de metro \"" << redMetro.getNombre() << "\":" << endl;
    cout << "Numero total de lineas: " << redMetro.contarLineas() << endl;
    for (int i = 0; i < redMetro.contarLineas(); ++i) {
        cout << "Linea " << (i + 1) << ": " << redMetro.getNombreLinea(i) << endl;
    }


    int posicionLineaEliminar;
    cout << "\nIngrese el nombre de la nueva linea a agregar con posicion: ";
    cout << "\nElimina la posicion: ";
    cin >> posicionLineaEliminar;
    redMetro.eliminarLinea(posicionLineaEliminar);
    cout << "\nNombre de las lineas actulizada en la red de metro \"" << redMetro.getNombre() << "\":" << endl;
    cout << "Numero total de lineas: " << redMetro.contarLineas() << endl;
    for (int i = 0; i < redMetro.contarLineas(); ++i) {
        cout << "Linea " << (i + 1) << ": " << redMetro.getNombreLinea(i) << endl;
    }

    string nombreLineaEliminar;
    cout << "\nIngrese el nombre de la nueva linea a agregar con posicion: ";
    cout << "\nElimina la posicion: ";
    cin.ignore();
    getline(cin, nombreLineaEliminar);
    redMetro.eliminarLinea(nombreLineaEliminar);
    cout << "\nNombre de las lineas actulizada en la red de metro \"" << redMetro.getNombre() << "\":" << endl;
    cout << "Numero total de lineas: " << redMetro.contarLineas() << endl;
    for (int i = 0; i < redMetro.contarLineas(); ++i) {
        cout << "Linea " << (i + 1) << ": " << redMetro.getNombreLinea(i) << endl;
    }
    /*bool pertenece = redMetro.estacionPerteneceALinea(nombreEstacion, "Línea 1 de " + nombreRedMetro);
    if (pertenece) {
        cout << "La estación \"" << nombreEstacion << "\" pertenece a la primera línea." << endl;
    } else {
        cout << "La estación \"" << nombreEstacion << "\" no pertenece a la primera línea." << endl;
    }*/

    return 0;
}
