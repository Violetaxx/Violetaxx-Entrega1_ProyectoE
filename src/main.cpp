#include "comandos.h"
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int opcion;
    string parametro;
    Imagen imagenCargada; // Variable para almacenar la imagen cargada
    Volumen volumenCargado(""); // Variable para almacenar el volumen cargado

    while (true) {
        cout << "$ ";
        cout << "Seleccione una opción:\n";
        cout << "1. cargar_imagen\n";
        cout << "2. cargar_volumen\n";
        cout << "3. info_imagen\n";
        cout << "4. info_volumen\n";
        cout << "5. proyeccion2D\n";
        cout << "6. codificar_imagen\n";
        cout << "7. decodificar_archivo\n";
        cout << "8. segmentar\n";
        cout << "9. Ayuda\n";
        cout << "10. Salir\n";
        cout << "$ ";

        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        if (opcion == 10)
            break;

        if (opcion == 9) {
            f_ayuda();
        } else if (opcion >= 1 && opcion <= 8) {
            if (opcion == 1 || opcion == 2) {
                cout << "Ingrese el parámetro: ";
                getline(cin, parametro);
                f_procesarComando(opcion, parametro);
            } else {
                f_procesarComando(opcion, "");
            }
        } else {
            cout << "Opción no valida\n";
        }
    }
    return 0;
}

void f_procesarComando(int opcion, const string& parametro) {
    switch (opcion) {
        case 1: { // cargar_imagen
            imagenCargada = cargar_imagen(parametro);
            if (imagenCargada.getAnchoImagen() > 0) {
                cout << "Imagen cargada correctamente.\n";
            } else {
                cout << "Error al cargar la imagen.\n";
            }
            break;
        }
        case 2: { // cargar_volumen
            stringstream ss(parametro);
            string nombreBase;
            int cantidadImagenes;
            ss >> nombreBase >> cantidadImagenes;
            volumenCargado = cargar_volumen(nombreBase, cantidadImagenes);
            cout << "Volumen cargado correctamente.\n";
            break;
        }
        case 3: { // info_imagen
            info_imagen(imagenCargada);
            break;
        }
        case 4: { // info_volumen
            info_volumen(volumenCargado);
            break;
        }
        case 5: { // proyeccion2D
            cout << "proyeccion2D]\n";
            // Aquí iría la lógica para proyeccion2D
            break;
        }
        case 6: { // codificar_imagen
            cout << "codificar_imagen]\n";
            // Aquí iría la lógica para codificar_imagen
            break;
        }
        case 7: { // decodificar_archivo
            cout << "decodificar_archivo]\n";
            // Aquí iría la lógica para decodificar_archivo
            break;
        }
        case 8: { // segmentar
            cout << "segmentar]\n";
            // Aquí iría la lógica para segmentar
            break;
        }
    }
}
