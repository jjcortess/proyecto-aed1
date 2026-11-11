#ifndef DICCIONARIO_PRODUCTOS_H
#define DICCIONARIO_PRODUCTOS_H
#include <list>
#include "Producto.h"
#include "TablaHash.h"
using namespace std;


class DiccionarioProductos{
    private:
        list<Producto> lista;
        TablaHash tabla;
        int contador;
    public:
        DiccionarioProductos();
        int numElem();
        void insertar(Producto nuevo);
        void eliminar(long long int id);
        void producto(long long int id);
        void precios(double min, double max);
        void palabras(string palabra);
  
};

#endif 
