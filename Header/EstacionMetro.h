// EstacionMetro.h
#ifndef ESTACIONMETRO_H
#define ESTACIONMETRO_H

#include <string>

using namespace std;

class EstacionMetro {
    public:

        // Constructor
        EstacionMetro(const string& nombrEstacion);

        // Destructor
        ~EstacionMetro();

        // Métodos de acceso (getters) para nombrEstacion
        const string getNombreEstacion();

        // Método de modificación (setter) para nombrEstacion
        void setNombreEstacion(const string& nombrNuevoEstacion) ;

        // Métodos de acceso (getters) y modificación (setter) para traferencia
        const bool tieneTransferencia();

        void setTieneTransferencia(bool tiene);

        // Método de acceso (getter) para lineas
        const string* getLineas();

        // Método de modificación (setter) para lineas
        void setLineas(const string* nuevasLineas, int numLineas);

        // Métodos de acceso (getters) y modificación (setter) para tiempos
        const int** getTiempos();

        void setTiempos(int** nuevosTiempos, int filas, int columnas);


    private:
        string nombrEstacion;
        bool traferencia;
        string* lineas;
        int* numTranferencias;
        int** tiempos;
};

#endif // ESTACIONMETRO_H
