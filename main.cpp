#include <iostream>

using namespace std;

int main()
{
    LineaMetro linea1 = new LineaMetro();
    cout << "Hello World!" << endl;
    EstacionMetro estacionNueva = new EstacionMetro();

    cout << "Donde quieres AGG la estacion" << endl;

    cout << "En que posicion?(si coloca 0 se agg de ultimo): " << endl;
    unsigned short int posicionAgg;

    if (si == 0) {
        linea1.agragarEstacion(EstacionMetro);
    } else {
        linea1.agragarEstacion(EstacionMetro, posicionAgg);
    }

    return 0;
}
