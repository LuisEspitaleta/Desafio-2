#include <iostream>
#include <string>
#include "Header/RedMetro.h"
#include "Header/LineaMetro.h"

using namespace std;

int main()
{
    string nombreRedMetro, nombreEstacion, nombreLinea, nombreLineaTransferencia;
    char crearMasLineas, esTransferencia;
    int cantidadLineas = 1, numTransferencia; // Por defecto, se crea al menos una linea
    bool lineExiste = false, estacionExiste = false;
    LineaMetro* linea;
    LineaMetro* lineaImprimir;

    // Solicitar nombre de la red de metro
    cout << "Ingrese el nombre de la red de metro: ";
    getline(cin, nombreRedMetro);

    // Preguntar si desea crear mas de una linea de metro
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
        cout<<"\nEscoja entre las siguientes opciones"<<endl<<endl;
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
        case 1:
            cout << "Ha elegido la opcion 1: Agregar una estacion de una linea" << endl;
            cout << "Cual es el nombre de la estacion a Crear: ";
            cin.ignore();
            getline(cin, nombreEstacion);
            lineExiste = false;
            while (!lineExiste) {
                cout << "Cual es el nombre de la Linea donde se va agregrar: ";              
                cin.clear();
                getline(cin, nombreLinea);

                // Verificar si la linea esta presente en RedMetro
                lineExiste = redMetro.existeLinea(nombreLinea);
                if (!lineExiste) {
                    cout << "La linea '" << nombreLinea << "' no existe en RedMetro. Intente de nuevo." << endl;
                }
            }

            cout << "Tiene transferencia? (S/N): ";
            cin >> esTransferencia;
            if (esTransferencia == 's'){
                bool trans = true;
                cout << "Cuantas lineas pasan por la estacion: ";
                cin >> numTransferencia;
                string* arregloTransferencias[numTransferencia];
                arregloTransferencias[0] =  new string(nombreLinea);
                for (int i = 0; i < numTransferencia; i++){
                    if (i != 0) {
                        cout << "Nombre de la linea de transferencia "<< i+1 <<": ";
                        cin.ignore();
                        //cin.clear();
                        getline(cin, nombreLineaTransferencia);
                        lineExiste = redMetro.existeLinea(nombreLineaTransferencia);
                        if (lineExiste){
                            arregloTransferencias[i] =  new string(nombreLineaTransferencia);
                        }
                    }
                }
                cout <<numTransferencia  << endl;
                for (int j = 0; j < numTransferencia; j++) {
                    cout <<numTransferencia<< " " << j << endl;
                    for (int k = 0; k < redMetro.getLineas(); k++) {
                        if (*arregloTransferencias[j] == redMetro.getNombreLinea(k)){
                            linea = &redMetro.getLinea(k);
                            linea->agregarEstacion(nombreEstacion, numTransferencia, *arregloTransferencias, trans);
                            cout << "Estaciones actuales de la Linea " << linea->getNombre() << endl;
                            for (int i = 0; i < linea->getNumEstaciones(); i++) {
                                cout << "Linea " << (i + 1) << ": " << linea->getNombreEstacion(i) << endl;
                            }
                            if (k == 0) {
                                lineaImprimir = &redMetro.getLinea(k);
                            }
                            break;
                        }
                    }
                }
            }
            break;
        case 2:
            cout << "Ha elegido la opcion 2: Eliminar una estacion de una linea" << endl;
            cout << "Cual es el nombre de la Linea que se va a Eliminar: ";  
            cin.ignore();
            cin.clear();
            getline(cin, nombreLinea);       
            lineExiste = redMetro.existeLinea(nombreLinea);
            if (lineExiste){
                for (int i = 0; i < redMetro.getLineas(); i++){                
                    if (nombreLinea == redMetro.getNombreLinea(i)){
                        redMetro.eliminarLinea(nombreLinea);
                    }
                    
                }
            }{
              cout << "La Linea que se va a Eliminar no existe\n\n" << endl;
            }
            break;
        case 3:
            cout << "Ha elegido la opcion 3: Saber cuantas lineas tiene la red metro" << endl;
            cout<<"La red metro tiene "<< redMetro.getLineas() <<" lineas"<<endl;
            cout<<"Estas son las lineas pertenecientes a su respectiva red metro :"<<endl;
            for (int i = 0; i < redMetro.getLineas(); ++i) {
                cout << "Linea " << (i + 1) << ": " << redMetro.getNombreLinea(i) << endl;
            }
            break;
        case 4:
            cout << "Ha elegido la opcion 4: Verificar si una estacion pertenece a cierta linea" << endl;
            cout<<"Ingrese el nombre de la estacion : ";
            cin.ignore();
            getline(cin, nombreEstacion);
            cout<<"Ingrese el nombre de la linea donde quiere revisar: ";
            getline(cin, nombreLinea);
            for (int i = 0; i < redMetro.getLineas(); ++i) {
                if (nombreLinea == redMetro.getNombreLinea(i)){
                    linea = &redMetro.getLinea(i);
                    estacionExiste = linea->existeEstacion(nombreEstacion);
                    if(estacionExiste) {
                        cout << "La estacion " << nombreEstacion << " Es una parada de la linea " << nombreLinea << endl;
                    }else{
                        cout << "La estacion " << nombreEstacion << " No es una parada de la linea " << nombreLinea << endl;
                    }
                    break;
                }
            }

            break;
        case 5:
             cout << "Ha elegido la opcion 5: Agregar una nueva linea a la red metro" << endl;
                cout << "¿Desea especificar la posicion de la nueva linea? (S/N): ";
                char opcion;
                cin >> opcion;

                if (opcion == 'S' || opcion == 's') {

                    cout << "Nombre de la linea que desea agregar: ";
                    cin.ignore(); // Limpiar la entrada
                    getline(cin, nombreLinea);

                    // Si se elige especificar la posicion
                    unsigned short int posicion;
                    cout << "En qué lugar desea agregar su nueva linea: ";
                    cin >> posicion;

                    // Aqui se agrega la linea con posicion
                    redMetro.agregarLinea(nombreLinea, posicion);
                    
                } else {
                    // Si no se desea especificar la posicion
                    cout << "Nombre de la linea que desea agregar: ";
                    getline(cin, nombreLinea);

                    // Aqui se agrega la linea sin posicion
                    redMetro.agregarLinea(nombreLinea);
                    cout << "Se ha agregado la linea '" << nombreLinea << "' correctamente." << endl;
                }
                
                cout << "\nNombre de las lineas actulizada en la red de metro \"" << redMetro.getNombre() << "\":" << endl;
                cout << "Numero total de lineas: " << redMetro.getLineas() << endl;
                for (int i = 0; i < redMetro.getLineas(); i++) {
                    cout << "Linea " << (i + 1) << ": " << redMetro.getNombreLinea(i) << endl;
                }

            break;
        case 6:

            cout << "Ha elegido la opcion 6: Eliminar una linea de la red metro" << endl;            
            cout<<"Que linea desea eliminar :"<<endl;
            cin.ignore();
            getline(cin, nombreLinea);
            redMetro.eliminarLinea(nombreLinea);
            cout<<"Primero se analizara si su linea contiene estaciones de transferencia"<<endl;
            cout << "\nNombre de las lineas actulizada en la red de metro \"" << redMetro.getNombre() << "\":" << endl;
            cout << "Numero total de lineas: " << redMetro.getLineas() << endl;
            for (int i = 0; i < redMetro.getLineas(); ++i) {
                cout << "Linea " << (i + 1) << ": " << redMetro.getNombreLinea(i) << endl;
            }
            break;
        case 7:
            cout << "Ha elegido la opcion 7: Saber cuantas estaciones tiene una red metro" << endl;
            // Agregar aqui la logica para la opcion 7
            break;
        case 8:
            cout << "Ha elegido la opcion 8: Salir del menu. ¡Hasta luego!" << endl;
            //delete[] nombres;
            break;
        default:
            cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
            break;
        }
    } while(opcion != 8);




    return 0;
}
