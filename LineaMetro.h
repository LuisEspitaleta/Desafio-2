#ifndef LINEAMETRO_H
#define LINEAMETRO_H

#include<string>
#include "EstacionMetro.h"

using namespace std;

class LineaMetro {

public: //Metodos

    //Constructores
    LineaMetro(const string& nombre, unsigned short int numEstaciones);
    LineaMetro(const string& nombre);

    //Getter y Setter
    const string getName();
    const int getNumEstaciones();

    const void imprimirNombre();
    const void imrprimiNumEstaciones();

    void agregarEstacion(const EstacionMetro& nuevaEstacion);
    void agregarEstacion(const EstacionMetro& nuevaEstacion, unsigned short int posicionAgg);

    void eliminarEstacion(const EstacionMetro& nuevaEstacion);

    bool* buscarEstacion(string nombre, string nombreEstacion);



    // Destructor
    ~LineaMetro();


private:
    string nombre;
    EstacionMetro* estacione[20];  // Puntero al arreglo de estaciones
    unsigned short int numEstaciones; // Número de estaciones en la línea de metro
};


#endif // LINEAMETRO_H
