#include "Volumen.h"

//operación para mostrar información de el volumen
void Volumen::info_volumen(const vector<Imagen>& volumen, const string& nombreBase) {
    if (volumen.empty()) {
        cout << "No hay un volumen cargado." << endl;
        return;
    }

    cout << "Información del volumen:" << endl;
    cout << "Nombre base: " << nombreBase << endl;
    cout << "Cantidad de imágenes: " << volumen.size() << endl;
    cout << "Ancho de las imágenes: " << volumen[0].getAnchoImagen() << " píxeles" << endl;
    cout << "Alto de las imágenes: " << volumen[0].getAltoImagen() << " píxeles" << endl;
}
