#include "Volumen.h"
#include <iostream>

//constructor
Volumen::Volumen(const std::string& nombreBase) : nombreBase(nombreBase) {}


//operacion para mostrar información del volumen
void Volumen::info_volumen() const {
    if (imagenes.empty()) {
        cout << "No hay un volumen cargado." << std::endl;
        return;
    }

    cout << "Información del volumen:" << endl;
    cout << "Nombre base: " << nombreBase << endl;
    cout << "Cantidad de imágenes: " << imagenes.size() << endl;
    cout << "Ancho de las imágenes: " << imagenes[0].getAnchoImagen() << " píxeles" << endl;
    cout << "Alto de las imágenes: " << imagenes[0].getAltoImagen() << " píxeles" << endl;
}
