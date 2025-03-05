#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include <string>
#include <vector>
#include "Imagen.h"
#include "Volumen.h"

Imagen cargar_imagen(const std::string& nombreArchivo);
void info_imagen(const Imagen& imagen);
Volumen cargar_volumen(const std::string& nombreBase, int cantidadImagenes);
void info_volumen(const Volumen& volumen);

void f_ayuda();
void f_ayudaComando(int opcion);
void f_procesarComando(int opcion, const std::string& parametro);

#endif // COMANDOS_H_INCLUDED
