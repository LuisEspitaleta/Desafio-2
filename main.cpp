#include <iostream>
#include <string>
#include "Header/RedMetro.h"
#include "Header/MenuFuntions.h"

using namespace std;

int main()
{

    string nombreRedMetro, nombreEstacion, nombreLinea, nombreLineaTransferencia;
    char crearMasLineas, esTransferencia;
    int cantidadLineas = 1, numTransferencia; // Por defecto, se crea al menos una línea
    bool lineExiste = false;

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
    cout << "Numero total de lineas: " << redMetro.getLineas() << endl;
    cout << "\nNombre de las lineas guardadas en la red de metro \"" << redMetro.getNombre() << "\":" << endl;
    for (int i = 0; i < redMetro.getLineas(); ++i) {
        cout << "Linea " << (i + 1) << ": " << redMetro.getNombreLinea(i) << endl;
    }
    //cout << "Número total de estaciones en la red: " << redMetro.contarEstacionesRed() << endl;

    int opcion;
    do {
        cout<<"Escoja entre las siguientes opciones"<<endl<<endl;
        cout<<"1: Agregar estaciones "<<endl;
        cout<<"2: Eliminar una estacion de una linea "<<endl;
        cout<<"3: Saber cuantas lineas tiene una red metro "<<endl;
        cout<<"4: Verificar si una estacion pertenece a cierta linea "<<endl;
        cout<<"5: Agregar una nueva linea a la red metro"<<endl;
        cout<<"6: Eliminar una linea de la red metro"<<endl;
        cout<<"7: Saber cuantas estaciones tiene una red metro"<<endl;
        cout<<"8: Salir del menu :"<<endl<<endl;

        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch(opcion) {
        case 1:{
            cout << "Ha elegido la opción 1: Agregar una estacion de una linea" << endl;
            cout << "Cual es el nombre de la estacion a Crear: ";
            cin.ignore();
            getline(cin, nombreEstacion);
            cout << "Cual es el nombre de la Linea donde se va agregrar: ";
            cin.ignore();
            getline(cin, nombreLinea);
            cout << "Tiene transferencia? (S/N): ";
            cin >> esTransferencia;
            if (esTransferencia == 'S'){
                cout << "Cuanatas lineas pasan por la estacion: ";
                cin >> numTransferencia;
                string* arregloTransferencias[numTransferencia];
                arregloTransferencias[0] = &nombreLinea;
                for (int i = 1; i < numTransferencia; i++)
                {
                    cout << "Nombre de la linea de transferencia "<< i <<": ";
                    cin.clear();
                    getline(cin, nombreLineaTransferencia);
                    lineExiste = redMetro.estacionPerteneceALinea(nombreLineaTransferencia);
                    if (lineExiste){
                        arregloTransferencias[i] = &nombreLineaTransferencia;
                    }
                    
                }                
            }

            for (int i = 0; i < redMetro.getLineas(); ++i) {
                if (nombreLinea == redMetro.getNombreLinea(i)){
                    LineaMetro& linea = redMetro.getLinea(1);
                    linea.agregarEstacion(nombreLinea);
                }
            }   
                
            void agregarEstacion();
        case 2:
            cout << "Ha elegido la opción 2: Eliminar una estacion de una linea" << endl;
            // Agregar aquí la lógica para la opción 2
            break;
        case 3:
            cout << "Ha elegido la opción 3: Saber cuantas lineas tiene una red metro" << endl;
            // Agregar aquí la lógica para la opción 3
            break;
        case 4:
            cout << "Ha elegido la opción 4: Verificar si una estacion pertenece a cierta linea" << endl;
            // Agregar aquí la lógica para la opción 4
            break;
        case 5:
            cout << "Ha elegido la opción 5: Agregar una nueva linea a la red metro" << endl;
            // Agregar aquí la lógica para la opción 5
            break;
        case 6:
            cout << "Ha elegido la opción 6: Eliminar una linea de la red metro" << endl;
            // Agregar aquí la lógica para la opción 6
            break;
        case 7:
            cout << "Ha elegido la opción 7: Saber cuantas estaciones tiene una red metro" << endl;
            // Agregar aquí la lógica para la opción 7
            break;
        case 8:
            cout << "Ha elegido la opción 8: Salir del menu. ¡Hasta luego!" << endl;
            //delete[] nombres;
            break;
        default:
            cout << "Opción no válida. Por favor, elija una opción válida." << endl;
            break;
        }
    } while(opcion != 8);



    // Ejemplo de verificación de pertenencia de estación a una línea
    string nombreLineaNueva;
    cout << "\nIngrese el nombre de la nueva linea a agregar: ";
    cin.ignore();
    getline(cin, nombreLineaNueva);
    redMetro.agregarLinea(nombreLineaNueva);

    cout << "\nNombre de las lineas actulizada en la red de metro \"" << redMetro.getNombre() << "\":" << endl;
    cout << "Numero total de lineas: " << redMetro.getLineas() << endl;
    for (int i = 0; i < redMetro.getLineas(); ++i) {
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
    cout << "Numero total de lineas: " << redMetro.getLineas() << endl;
    for (int i = 0; i < redMetro.getLineas(); ++i) {
        cout << "Linea " << (i + 1) << ": " << redMetro.getNombreLinea(i) << endl;
    }

    int posicionLineaEliminar;
    cout << "\nIngrese el nombre de la nueva linea a agregar con posicion: ";
    cout << "\nElimina la posicion: ";
    cin >> posicionLineaEliminar;
    redMetro.eliminarLinea(posicionLineaEliminar);
    cout << "\nNombre de las lineas actulizada en la red de metro \"" << redMetro.getNombre() << "\":" << endl;
    cout << "Numero total de lineas: " << redMetro.getLineas() << endl;
    for (int i = 0; i < redMetro.getLineas(); ++i) {
        cout << "Linea " << (i + 1) << ": " << redMetro.getNombreLinea(i) << endl;
    }

    string nombreLineaEliminar;
    cout << "\nIngrese el nombre de la nueva linea a agregar con posicion: ";
    cout << "\nElimina la posicion: ";
    cin.ignore();
    getline(cin, nombreLineaEliminar);
    redMetro.eliminarLinea(nombreLineaEliminar);
    cout << "\nNombre de las lineas actulizada en la red de metro \"" << redMetro.getNombre() << "\":" << endl;
    cout << "Numero total de lineas: " << redMetro.getLineas() << endl;
    for (int i = 0; i < redMetro.getLineas(); ++i) {
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
