#ifndef LINEAMETRO_H
#define LINEAMETRO_H

#include<string>
#include "EstacionMetro.h"

using namespace std;

class LineaMetro {

private:
    string nombreLinea;
    EstacionMetro** estaciones; // Arreglo dinámico;
    unsigned short int numEstaciones; // Número de estaciones en la línea de metro

public: //Metodos

    //Constructores
    LineaMetro();
    LineaMetro(const string& nombreLinea);
    LineaMetro(const string& nombreLinea, unsigned short int numEstaciones);

    //Getter y Setter
    const string getNombre();
    const int getNumEstaciones();
    void setNombre(const string& nuevoNombre);
    void setNumEstaciones(const unsigned short int& nuevoNumEstaciones);
    const void imprimirNombre();
    const void imrprimiNumEstaciones();
    EstacionMetro& getEstacion(int indice);
    const string getNombreEstacion(int index);
    const bool getVerificarTranferencia(int index);
    void agregarEstacion(const string& nombreEstacionNueva);
    void agregarEstacion(const string& nombreEstacionNueva, int posicion);
    void agregarEstacion(const string& nombreEstacionNueva, int numTransferencia, string* arregloTransferencias, bool esTranferencia);
    const bool existeEstacion(const string& nombreEstacion);
    void eliminarEstacion(const int posicion);
    bool* buscarEstacion(string nombre, string nombreEstacion);


    // Destructor
    ~LineaMetro();

};


#endif // LINEAMETRO_H
