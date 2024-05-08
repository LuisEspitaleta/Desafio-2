#ifndef REDMETRO_H
#define REDMETRO_H

#include <string>
#include "LineaMetro.h"

class RedMetro {
private:
    string nombreRed; // Nombre de la red de metro
    LineaMetro* lineas[10]; // Arreglo estático para almacenar hasta 10 líneas de metro
    unsigned short int numLineas;

public:
    // Constructor que crea una red de metro con una línea predeterminada
    RedMetro(const string& nombreRed);

    // Constructor que crea una red de metro con el nombre y una cantidad inicial de líneas
    RedMetro(const string& nombreRed, unsigned short int numLineas);

    // Destructor
    ~RedMetro();

    // Métodos para manipular líneas de metro
    void agregarLinea(const LineaMetro& nuevaLinea);
    void agregarLinea(const LineaMetro& nuevaLinea, int posicion);
    void eliminarLinea(const std::string& nombreLinea);
    int contarLineas() const;

    // Métodos para gestionar estaciones en la red de metro
    int contarEstacionesRed() const;
    bool estacionPerteneceALinea(const std::string& nombreEstacion, const std::string& nombreLinea) const;
};

#endif // REDMETRO_H
