#include "Interprete.h"
#include <iostream>
#include <sstream>

using namespace std;

Interprete::Interprete() {
    contador = 0;
}

void Interprete::procesar_insertar() {
    Producto nuevo;
    nuevo.leer();
    dic.insertar(nuevo);
    cout << dic.numElem() << " productos\n";
}

void Interprete::procesar_eliminar() {
    long long int id;
    cin >> id;
    dic.eliminar(id);
    cout << --contador << " productos\n";
}


void Interprete::procesar_productos() {
    long long int id;
    cin >> id;
    cout << "producto " << id << '\n';
    cout << 1 << ". ";
    actual.mostrar();
    cout << "Total: 1 producto\n";
}


void Interprete::procesar_precios() {
    double MIN, MAX;
    cin >> MIN >> MAX;
    cout << "precios " << MIN << ' ' << MAX << '\n';
    cout << 1 << ". ";
    actual.mostrar();
    cout << "Total: 1 producto\n";
}




/*
void Interprete::procesar_palabras() {
    string linea;
    string palabra;
    getline(cin, linea);
    istringstream iss(linea);
    cout << "palabras" << linea << '\n';
    cout << 1 << ". ";
    actual.mostrar();
    cout << "Total: 1 producto\n";
}
*/



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