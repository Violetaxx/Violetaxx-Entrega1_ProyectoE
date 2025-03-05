#ifndef IMAGEN_H
#define IMAGEN_H

#include <string>
#include <vector>

class Imagen{
private:
    std::string nombreImagen;
    int altoImagen;
    int anchoImagen;
    std::vector<std::vector<int>> pixeles;

public:
    Imagen();//constructor

    //getters
    std::string getNombreImagen() const;
    int getAltoImagen() const;
    int getAnchoImagen() const;
    std::vector<std::vector<int>> getPixeles() const;

    //setters
    void setNombreImagen(const std::string& nombre);
    void setAltoImagen(int alto);
    void setAnchoImagen(int ancho);
    void setPixeles(const std::vector<std::vector<int>>& pixeles);

    //operaciones
    bool cargar(const std::string& nombreArchivo);
    void info_imagen() const;
};

#endif // IMAGEN_H
