#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Producto{
    private:
        long long int identificador;
        string nombre, descripcion;
        double precio;
    public:
        Producto();
        
        long long int getidentificador();
        double getprecio();

        void leer(void);
        void mostrar(void);
        bool es_anterior(Producto &otro);

};

#endif 
