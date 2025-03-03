#include "Imagen.h"
#include <iostream>
#include <fstream>
using namespace std;

//constructor
Imagen::Imagen() : ancho(0), alto(0), maxVal(0){}

//operacion para cargar una imagen desde un archivo PGM
bool Imagen::cargar(const string& nombreArchivo){
    ifstream archivo(nombreArchivo);
    if(!archivo) {
        cout<<"Error: No se pudo abrir el archivo"<<nombreArchivo <<endl;
        return false;
    }

    string linea;
    archivo>>linea;
    if(linea != "P2"){
        cout<<"Error: Formato de archivo no soportado"<<endl;
        return false;
    }

    archivo>>ancho>>alto;
    archivo>> maxVal;

    //redimensionar la matriz de píxeles
    pixeles.resize(alto, vector<int>(ancho));

    //leer los valores de los píxeles
    for(int i = 0; i < alto; ++i){
        for(int j = 0; j < ancho; ++j){
            archivo>>pixeles[i][j];
        }
    }

    nombre= nombreArchivo;
    cout<<"La imagen "<<nombreArchivo<<" ha sido cargada."<<endl;
    return true;
}

