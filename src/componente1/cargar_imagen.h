
#include "Imagen.h"
#include <iostream>
#include <fstream>

using namespace std;

Imagen::Imagen() : ancho(0), alto(0), maxVal(0) {}//constructor

//operacion para cargar una imagen desde un archivo PGM
bool Imagen::cargar(const string& nomArchi){
    ifstream archivo(nomArchi);
    if(!archivo){
        cout << "Error: No se pudo abrir el archivo " << nomArchi << endl;
        return false;
    }

    string linea;
    archivo >> linea;
    if(linea != "P2"){
        cout<<"Error: Formato de archivo no soportado"<<endl;
        return false;
    }

    archivo>>ancho>>alto;
    archivo>>maxVal;

    // Redimensionar la matriz de píxeles
    pixeles.resize(alto, vector<int>(ancho));

    // Leer los valores de los píxeles
    for(int i = 0; i < alto; ++i){
        for(int j = 0; j < ancho; ++j){
            archivo>>pixeles[i][j];
        }
    }

    nombre = nomArchi;
    cout<<"La imagen "<<nomArchi<<" ha sido cargada."<<endl;
    return true;
}

// Operación para mostrar información de la imagen
void Imagen::mostrarInfo() const {
    cout<<"Imagen cargada en memoria: "<<nombre<<", ancho: "<<ancho<<", alto: "<<alto<<", maximo valor: "<<maxVal<<endl;
}
