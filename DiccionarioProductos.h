#ifndef DICCIONARIO_PRODUCTOS_H
#define DICCIONARIO_PRODUCTOS_H
#include <list>
#include "Producto.h"
using namespace std;


class DiccionarioProductos{
    private:
        list<Producto> lista;
        int contador;
    public:
        DiccionarioProductos();
        void insertar(Producto nuevo);
        void eliminar(long long int id);
        void producto(long long int id);
        void precios(double min, double max);

        int numElem(){
            return contador;
        }

};

#endif 
