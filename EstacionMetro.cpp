// EstacionMetro.cpp
#include <string>
#include "Header/EstacionMetro.h"


using namespace std;

    // Constructor
    EstacionMetro::EstacionMetro(const string& nombrEstacion) : nombrEstacion(nombrEstacion), numTranferencias(0){
        lineas = new string[1];

    }

    // Destructor
    EstacionMetro::~EstacionMetro(){
    }

    // Métodos de acceso (getters) para nombrEstacion
    const string EstacionMetro::getNombreEstacion()  {
        return nombrEstacion;
    }

    // Método de modificación (setter) para nombrEstacion
    void EstacionMetro::setNombreEstacion(const string& nombrNuevoEstacion) {
        nombrEstacion = nombrNuevoEstacion;
    }

    // Métodos de acceso (getters) y modificación (setter) para traferencia
    const bool EstacionMetro::tieneTransferencia()  {
        return traferencia;
    }

    void EstacionMetro::setTieneTransferencia(bool tiene) {
        traferencia = tiene;
    }

    // Método de acceso (getter) para lineas
    const string* EstacionMetro::getLineas(){
        return lineas;
    }

    // Método de modificación (setter) para lineas
    void EstacionMetro::setLineas(const string* nuevasLineas, int numLineas) {
        // Suponemos que numLineas indica el tamaño del nuevo arreglo de lineas
        // Aquí se debería implementar una lógica para copiar o asignar las nuevas lineas
        // Asumiendo que `lineas` es un arreglo dinámico
        // Esto es un ejemplo simplificado
        delete[] lineas; // Liberamos la memoria del arreglo anterior
        lineas = new string[numLineas];
        for (int i = 0; i < numLineas; ++i) {
            lineas[i] = nuevasLineas[i];
        }
    }

    // Métodos de acceso (getters) y modificación (setter) para tiempos
    const int** EstacionMetro::getTiempos() {
        return tiempos;
    }

    void EstacionMetro::setTiempos(int** nuevosTiempos, int filas, int columnas) {
        // Suponemos que filas y columnas son las dimensiones del nuevo arreglo 2D de tiempos
        // Aquí se debería implementar una lógica para copiar o asignar los nuevos tiempos
        // Asumiendo que `tiempos` es un arreglo 2D dinámico
        // Esto es un ejemplo simplificado
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                tiempos[i][j] = nuevosTiempos[i][j];
            }
        }
    }

