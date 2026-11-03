#include "DiccionarioProductos.h"
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include "Producto.h"


DiccionarioProductos::DiccionarioProductos(){
    contador = 0;
}


void DiccionarioProductos::insertar(Producto nuevo){
    list<Producto>::iterator it = lista.begin();
    while (it!=lista.end() && it->getidentificador()<nuevo.getidentificador()){
        it++;
    }
    if (it==lista.end() || it->getidentificador()!=nuevo.getidentificador()){
        lista.insert(it, nuevo);
        contador++;
    }

    
}




void DiccionarioProductos::eliminar(long long int id){

    list<Producto>::iterator it = lista.begin();
    while(it!=lista.end() && it->getidentificador()<id){
        it++;
    }

    if(it != lista.end() && it->getidentificador()==id){
        lista.erase(it);
        contador--;
    }
}


void DiccionarioProductos::producto(long long int id){
    cout << "producto " << id << '\n';

    list<Producto>::iterator it = lista.begin();
    while(it!=lista.end() && it->getidentificador()<id){
        it++;
    }

    if(it != lista.end() && it->getidentificador()==id){
        cout << "1. ";
        it->mostrar();
        cout << "Total: 1 productos\n";
    } else {
        cout << "Total: 0 productos\n";
    }
}


void DiccionarioProductos::precios(double min, double max) { 
    cout << "precios " << min << ' ' << max << '\n';

    int encontrados=0;
    list<Producto>::iterator it;

    for (it= lista.begin(); it!=lista.end(); it++){
        if(it->getprecio() <= max && it->getprecio() >= min) {
            encontrados++;
            cout << encontrados << ". ";
            it->mostrar();
        }
    }

    cout << "Total: " << encontrados << " productos\n";
}

