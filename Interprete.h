#ifndef INTERPRETE_H
#define INTERPRETE_H

#include <string>
#include "DiccionarioProductos.h"
#include "Producto.h"

using namespace std;

class Interprete {
private:
    DiccionarioProductos dic;
    Producto actual; 
    int contador;    

    void procesar_insertar();
    void procesar_palabras();
    void procesar_precios();
    void procesar_eliminar();
    void procesar_productos();
    void procesar_comando(string comando);

public:
    Interprete();
    void ejecutar();
};

#endif