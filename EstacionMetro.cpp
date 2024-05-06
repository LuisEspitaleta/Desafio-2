// EstacionMetro.cpp

#include <iostream>
#include <string>
#include "EstacionMetro.h"

using namespace std;

EstacionMetro::EstacionMetro(const string& nombre) : nombre(nombre) {
    // Puedes agregar más implementaciones aquí si es necesario
}

const void EstacionMetro::getNombre() {
    cout << "Estación: " << nombre << "\n";
}

