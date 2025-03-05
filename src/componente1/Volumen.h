#ifndef VOLUMEN_H
#define VOLUMEN_H

#include <string>
#include <vector>
#include "Imagen.h" // Incluir la clase Imagen

class Volumen {
private:
    std::vector<Imagen> imagenes;
    std::string nombreBase;

public:
    //constructor
    Volumen(const std::string& nombreBase);

    //operaciones
    void info_volumen() const;
};

#endif // VOLUMEN_H
