#include "comandos.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Cargar imagen
Imagen cargar_imagen(const std::string& nombreArchivo) {
    Imagen imagen;
    if (!imagen.cargar_imagen(nombreArchivo)) {
        return Imagen(); // Retorna una imagen vacía en caso de error
    }
    return imagen;
}

// Mostrar información de la imagen
void info_imagen(const Imagen& imagen) {
    imagen.info_imagen();
}

// Cargar volumen
Volumen cargar_volumen(const std::string& nombreBase, int cantidadImagenes) {
    Volumen volumen(nombreBase);
    for (int i = 0; i < cantidadImagenes; ++i) {
        stringstream ss;
        ss << nombreBase << i << ".pgm";
        Imagen imagen = cargar_imagen(ss.str());
        if (imagen.getAnchoImagen() > 0) { // Verifica si la imagen se cargó correctamente
            volumen.agregarImagen(imagen);
        } else {
            cout << "Error al cargar la imagen " << ss.str() << endl;
        }
    }
    return volumen;
}

// Mostrar información del volumen
void info_volumen(const Volumen& volumen) {
    volumen.info_volumen();
}

void f_ayuda() {
    cout << "Los comandos disponibles son:\n";
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
}

void f_ayudaComando(int opcion) {
    switch (opcion) {
        case 1:
            cout << "Uso: cargar_imagen nombre_imagen.pgm\nCarga en memoria la imagen PGM indicada.\n";
            break;
        case 2:
            cout << "Uso: cargar_volumen nombre_base n_im\nCarga un volumen de imágenes numeradas.\n";
            break;
        case 3:
            cout << "Uso: info_imagen\nMuestra la información de la imagen cargada en memoria.\n";
            break;
        case 4:
            cout << "Uso: info_volumen\nMuestra la información del volumen cargado en memoria.\n";
            break;
        case 5:
            cout << "Uso: proyeccion2D direccion criterio nombre_archivo.pgm\nGenera una proyección 2D.\n";
            break;
        case 6:
            cout << "Uso: codificar_imagen nombre_archivo.huf\nCodifica la imagen en formato Huffman.\n";
            break;
        case 7:
            cout << "Uso: decodificar_archivo nombre_archivo.huf nombre_imagen.pgm\nDecodifica un archivo Huffman.\n";
            break;
        case 8:
            cout << "Uso: segmentar salida_imagen.pgm sx1 sy1 sl1 ...\nSegmenta la imagen con semillas dadas.\n";
            break;
        default:
            cout << "Error: Comando no válido.\n";
            break;
    }
}

void f_procesarComando(int opcion, string& parametro) {
    cout << "[";

    switch (opcion) {
        case 1:
            cout << "cargar_imagen] " << parametro << "\n";
            f_ayudaComando(opcion);
            if (parametro.empty())
                cout << "Error: Debes proporcionar una imagen en formato .pgm\n";
            else
                cout << "Éxito: Imagen '" << parametro << "' cargada correctamente.\n";
            break;

        case 2:
            cout << "cargar_volumen] " << parametro << "\n";
            f_ayudaComando(opcion);
            if (parametro.empty())
                cout << "Error: Debes proporcionar un volumen.\n";
            else
                cout << "Éxito: Volumen '" << parametro << "' cargado correctamente.\n";
            break;

        case 3:
            cout << "info_imagen]\n";
            f_ayudaComando(opcion);
            cout << "Mostrando información de la imagen...\n";
            break;

        case 4:
            cout << "info_volumen]\n";
            f_ayudaComando(opcion);
            cout << "Mostrando información del volumen...\n";
            break;

        case 5:
            cout << "proyeccion2D]\n";
            f_ayudaComando(opcion);
            cout << "Generando proyección 2D...\n";
            break;

        case 6:
            cout << "codificar_imagen]\n";
            f_ayudaComando(opcion);
            cout << "Codificando imagen...\n";
            break;

        case 7:
            cout << "decodificar_archivo]\n";
            f_ayudaComando(opcion);
            cout << "Decodificando archivo...\n";
            break;

        case 8:
            cout << "segmentar]\n";
            f_ayudaComando(opcion);
            cout << "Segmentando imagen...\n";
            break;

        default:
            cout << "comando_desconocido]\n";
            f_ayudaComando(opcion);
            cout << "Error: Comando no reconocido.\n";
    }
}
