#include "Interprete.h"
#include <iostream>
#include <sstream>

using namespace std;

Interprete::Interprete() {
}

void Interprete::procesar_insertar() {
    Producto nuevo;
    nuevo.leer();
    dic.insertar(nuevo);
    cout << dic.getcontador() << " productos\n";
}

void Interprete::procesar_eliminar() {
    long long int id;
    cin >> id;
    dic.eliminar(id);
    cout << dic.getcontador() << " productos\n";
}


void Interprete::procesar_productos() {
    long long int id;
    cin >> id;
    dic.producto(id);
}


void Interprete::procesar_precios() {
    double MIN, MAX;
    cin >> MIN >> MAX;
    dic.precios(MIN,MAX);
}


void Interprete::procesar_comando(string comando) {
    if(comando == "insertar") { 
        procesar_insertar();
    }
    else if(comando == "precios") { 
        procesar_precios(); 
    }
    else if(comando == "eliminar") { 
        procesar_eliminar(); 
    }
    else if(comando == "producto") { 
        procesar_productos(); 
    }
}

void Interprete::ejecutar() {
    string comando;
    while(cin >> comando) {
        procesar_comando(comando);
    }
}