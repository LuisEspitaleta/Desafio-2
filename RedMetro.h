#ifndef REDMETRO_H
#define REDMETRO_H

#include <string>
#include "LineaMetro.h"

class RedMetro {
private:
    string nombreRed; // Nombre de la red de metro
    LineaMetro** lineas; // Arreglo estático para almacenar hasta 10 líneas de metro
    unsigned short int numLineas;

public:

    //Constructores
    // Constructor que crea una red de metro con una línea predeterminada
    RedMetro(const string& nombreRed);

    // Constructor que crea una red de metro con el nombre y una cantidad inicial de líneas
    RedMetro(const string& nombreRed, unsigned short int numLineas);

    // Destructor
    //~RedMetro();

    // Métodos para manipular líneas de metro
    const string getNombre();
    const string getNombreLinea(int index);
    void setNombreRed(const string& nuevoNombre);
    void setNumLineas(const unsigned short int& nuevoNumLineas);

    void agregarLinea(const string& nuevaLinea);
    void agregarLinea(const string& nuevaLinea, int posicion);
    void eliminarLinea(const string& nombreLinea);
    void eliminarLinea(const int posicion);
    int contarLineas() const;

    // Métodos para gestionar estaciones en la red de metro
    int contarEstacionesRed() const;
    bool estacionPerteneceALinea(const string& nombreEstacion, const string& nombreLinea) const;
};

#endif // REDMETRO_H
