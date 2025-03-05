#include <iostream>
#include <sstream>
#include <vector>
#include "comandos.h"

using namespace std;

int main() {
    // Pruebas para cargar_imagen
    Imagen imagen1 = cargar_imagen("imagen1.pgm");
    if (imagen1.getAnchoImagen() > 0) {
        cout << "Prueba cargar_imagen exitosa.\n";
    } else {
        cout << "Prueba cargar_imagen fallida.\n";
    }

    // Pruebas para info_imagen
    info_imagen(imagen1);

    // Pruebas para cargar_volumen
    Volumen volumen1 = cargar_volumen("volumen", 3);
    info_volumen(volumen1);

    // Pruebas para cargar_imagen con un archivo inexistente
    Imagen imagen2 = cargar_imagen("noexiste.pgm");
    if (imagen2.getAnchoImagen() == 0) {
        cout << "Prueba cargar_imagen con archivo inexistente exitosa.\n";
    } else {
        cout << "Prueba cargar_imagen con archivo inexistente fallida.\n";
    }

    // Pruebas para cargar_volumen con imágenes inexistentes
    Volumen volumen2 = cargar_volumen("volumen_inexistente", 3);
    info_volumen(volumen2);

    return 0;
}
