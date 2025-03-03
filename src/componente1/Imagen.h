#ifndef IMAGEN_H
#define IMAGEN_H
using namesapce std;

#include <string>
#include <vector>

class Imagen {
private:
    string nombre;
    int ancho;
    int alto;
    int maxVal;
    vector<vector<int>> pixeles;

public:
    Imagen(); //constructor

    //operaciones
    bool cargar(string& nomArchi);
    void mostrarInfo();
};

#endif
