// EstacionMetro.h
#ifndef ESTACIONMETRO_H
#define ESTACIONMETRO_H

#include <string>

using namespace std;

class EstacionMetro {
public:

    EstacionMetro(const string& nombre);


    // Destructor
    ~EstacionMetro(); // Declaración del destructor

    const void getNombre();

private:
    string nombre;
    bool traferencia;
    //String lineas = new
};

#endif // ESTACIONMETRO_H
