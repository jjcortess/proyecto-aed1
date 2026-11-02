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


void DiccionarioProductos::precios(double min, double max) { 
    list<Producto>::iterator it;
    for (it= lista.begin(); it!=lista.end(); it++){
        if(it->getprecio() <= max && it->getprecio() >= min) {
            it->mostrar();
        }
    }
}


void DiccionarioProductos::eliminar(long long int id){
    list<Producto>::iterator it = lista.begin();
    while(it!=lista.end() && it->getidentificador()<id){
        it++;
    }

    if(it->getidentificador()==id){
        lista.erase(it);
        contador--;
    }
}


void DiccionarioProductos::producto(long long int id){
    list<Producto>::iterator it = lista.begin();
    while(it!=lista.end() && it->getidentificador()<id){
        it++;
    }

    if(it->getidentificador()==id){
        it->mostrar();
    }
}

