// EstacionMetro.cpp

#include <string>
#include "Header/EstacionMetro.h"

using namespace std;

EstacionMetro::EstacionMetro(const string& nombrEstacion) : nombrEstacion(nombrEstacion) {
    // Puedes agregar más implementaciones aquí si es necesario
}


const string EstacionMetro::getNombre(){
    return nombrEstacion;
}

