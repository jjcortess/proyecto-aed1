#include <iostream>
#include <string>
#include <sstream>
#include "Producto.h"
using namespace std;


Producto::Producto() {
    identificador = 0;
    precio = 0.0;
}

long long int Producto::getidentificador(){
    return identificador;
}

double Producto::getprecio(){
    return precio;
}

void Producto::leer(){
    cin >> identificador;
    cin.ignore();
    getline(cin,nombre);
    getline(cin,descripcion);
    cin >> precio;
}


void Producto::mostrar(){
    cout<<nombre<< " ("<< identificador << ")" << '\n' << "  " << descripcion << '\n' << "  " << precio << ' ' << "euros" << '\n';
}




