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
    const string getNombre();

private:
    string nombrEstacion;
    bool traferencia;
    //String lineas = new
};

#endif // ESTACIONMETRO_H
