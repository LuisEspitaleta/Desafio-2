#ifndef LINEAMETRO_H
#define LINEAMETRO_H

#include<string>
#include "EstacionMetro.h"

using namespace std;

class LineaMetro {
    private: //Atributos
        string name;
        
        int numStations;
        int** arregloDelineametro; // Arreglo de arreglos dinámico
        int* tamanos; // Arreglo para almacenar los tamaños de los subarreglos
        int numArreglos; // Número de arreglos almacenados en el arreglo principal
        
    public: //Metodos
        LineaMetro(string name, string transportType);
        
        string getName() const;
        string getTransportType() const;
        int getNumStations() const;
        
        void adicionarEstacion(Station* station, int position = -1);
        void eliminStation(int position);
        bool hasStation(const Station* station) const;
        
    private:
        string nombre;
        EstacionMetro estaciones[20]; // Capacidad máxima de estaciones por línea
        int numEstaciones;
};


#endif // LINEAMETRO_H


#ifndef LINEAMETRO_H
#define LINEAMETRO_H

#include <string>
#include <vector>
#include "EstacionMetro.h"

class LineaMetro {
public:
    LineaMetro(const std::string& nombre);
    void AgregarEstacion(const EstacionMetro& estacion);
    // Otros métodos relevantes para la línea
private:
    std::string nombre_;
    std::vector<EstacionMetro> estaciones_;
};

#endif // LINEAMETRO_H

#ifndef LINEAMETRO_H
#define LINEAMETRO_H

#include <iostream>


class LineaMetro {
public:
    LineaMetro(const std::string& nombre) : nombre(nombre), numEstaciones(0) {}
    
    void agregarEstacion(const std::string& nombreEstacion) {
        estaciones[numEstaciones++] = EstacionMetro(nombreEstacion);
    }
    
    void eliminarEstacion(int indice) {
        if (indice >= 0 && indice < numEstaciones) {
            for (int i = indice; i < numEstaciones - 1; ++i) {
                estaciones[i] = estaciones[i + 1];
            }
            --numEstaciones;
        }
    }
    
    int getNumEstaciones() const {
        return numEstaciones;
    }
    

};

#endif
