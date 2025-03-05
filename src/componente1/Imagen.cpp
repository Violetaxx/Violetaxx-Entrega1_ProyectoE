#include "Imagen.h"
#include <iostream>
#include <fstream>

using namespace std; 

Imagen::Imagen() : anchoImagen(0), altoImagen(0) {}//constructor

//getters
string Imagen::getNombreImagen() const { return nombreImagen; }
int Imagen::getAltoImagen() const { return altoImagen; }
int Imagen::getAnchoImagen() const { return anchoImagen; }
vector<vector<int>> Imagen::getPixeles() const { return pixeles; }

//setters
void Imagen::setNombreImagen(const string& nombre) { nombreImagen = nombre; }
void Imagen::setAltoImagen(int alto) { altoImagen = alto; }
void Imagen::setAnchoImagen(int ancho) { anchoImagen = ancho; }
void Imagen::setPixeles(const vector<vector<int>>& pixeles) { Imagen::pixeles = pixeles; }

//operacion para cargar una imagen desde un archivo PGM
bool Imagen::cargar_imagen(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << endl;
        return false;
    }

    string linea;
    archivo >> linea;
    if (linea != "P2") {
        cerr << "Error: Formato de archivo no soportado" << endl;
        return false;
    }

    archivo >> anchoImagen >> altoImagen;

    //redimensionar la matriz de píxeles
    pixeles.resize(altoImagen, vector<int>(anchoImagen));

    //leer los valores de los píxeles
    for(int i = 0; i < altoImagen; ++i){
        for(int j = 0; j < anchoImagen; ++j){
            int pixel;
            archivo >> pixel;
            if(pixel < 0 || pixel > 255){//manejo de errores
            cerr << "Error: Valor de píxel fuera de rango en " << nombreArchivo << endl;
            return false;
        }
        pixeles[i][j] = pixel;
    }
}

    nombreImagen = nombreArchivo;
    cout << "La imagen " << nombreArchivo << " ha sido cargada." << endl;
    return true;
}

//operación para mostrar información de la imagen
void Imagen::info_imagen() const {
    cout << "Información de la imagen:" << endl;
    cout << "Nombre de la imagen: " << nombreImagen << endl;
    cout << "Ancho de la imagen: " << anchoImagen << " píxeles" << endl;
    cout << "Alto de la imagen: " << altoImagen << " píxeles" << endl;
}
