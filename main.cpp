#include <iostream>
#include <string>
#include "RedMetro.h"
#include "LineaMetro.h"

using namespace std;

int main()
{
    /*
    LineaMetro linea1 = new LineaMetro();
    cout << "Hello World!" << endl;
    EstacionMetro estacionNueva = new EstacionMetro();

    cout << "Donde quieres AGG la estacion" << endl;

    cout << "En que posicion?(si coloca 0 se agg de ultimo): " << endl;
    unsigned short int posicionAgg;

    if (si == 0) {
        linea1.agragarEstacion(EstacionMetro);
    } else {
        linea1.agragarEstacion(EstacionMetro, posicionAgg);
    }*/
        string nombreRedMetro;
        char crearMasLineas;
        int cantidadLineas = 1; // Por defecto, se crea al menos una línea

        // Solicitar nombre de la red de metro
        cout << "Ingrese el nombre de la red de metro: ";
        cin >> nombreRedMetro;

        // Preguntar si desea crear más de una línea de metro
        cout << "¿Desea crear más de una línea de metro? (S/N): ";
        cin >> crearMasLineas;

        if (crearMasLineas == 'S' || crearMasLineas == 's') {
            cout << "¿Cuántas líneas de metro desea crear? ";
            cin >> cantidadLineas;
        }

        if (cantidadLineas) {
            // Crear la red de metro con varias lineas
            RedMetro redMetro(nombreRedMetro, cantidadLineas);
        } else {
            // Crear la red de metro con una sola linea
            RedMetro redMetro(nombreRedMetro);
        }



        // Crear la primera línea de metro
        LineaMetro primeraLinea("Línea 1 de " + nombreRedMetro);
        redMetro.agregarLinea(primeraLinea);

        // Crear líneas adicionales si se solicita
        for (int i = 2; i <= cantidadLineas; i++) {
            string nombreLinea = "Línea " + to_string(i) + " de " + nombreRedMetro;
            LineaMetro nuevaLinea(nombreLinea);
            redMetro.agregarLinea(nuevaLinea);
        }

        // Mostrar resumen de la red de metro creada
        cout << "\nResumen de la red de metro \"" << nombreRedMetro << "\":" << endl;
        cout << "Número total de líneas: " << redMetro.contarLineas() << endl;
        cout << "Número total de estaciones en la red: " << redMetro.contarEstacionesRed() << endl;

        // Ejemplo de verificación de pertenencia de estación a una línea
        string nombreEstacion;
        cout << "\nIngrese el nombre de una estación para verificar si pertenece a la primera línea creada: ";
        cin >> nombreEstacion;

        bool pertenece = redMetro.estacionPerteneceALinea(nombreEstacion, "Línea 1 de " + nombreRedMetro);
        if (pertenece) {
            cout << "La estación \"" << nombreEstacion << "\" pertenece a la primera línea." << endl;
        } else {
            cout << "La estación \"" << nombreEstacion << "\" no pertenece a la primera línea." << endl;
        }

    return 0;
}
