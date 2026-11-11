#include "DiccionarioProductos.h"
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include "Producto.h"


string minusculas(string palabra) {
    int longi = palabra.length();
    for(int i = 0; i<longi; i++) { 
        unsigned char car = palabra[i];
        if (car>= 'A' && car<='Z'){
            palabra[i] += 32;
        } else if (car == 0xC3 && i + 1 < longi) { 
            unsigned char siguiente = palabra[i+1];
            if(siguiente == 0x81 || siguiente == 0x89 || siguiente == 0x8D || siguiente == 0x93 || siguiente == 0x9A || siguiente == 0x91 || siguiente == 0x9C){
                palabra[i+1] += 32;
            }
            i++;
        }
    }
    return palabra;

}


DiccionarioProductos::DiccionarioProductos(){
    contador = 0;
}

int DiccionarioProductos::numElem() {
    return contador;
}


void DiccionarioProductos::insertar(Producto nuevo){
    
    list<Producto>::iterator it = lista.begin();
    while (it!=lista.end() && it->getidentificador()<nuevo.getidentificador()){
        it++;
    }
    if (it==lista.end() || it->getidentificador()!=nuevo.getidentificador()){
        list<Producto>::iterator it_nuevo = lista.insert(it, nuevo);
        contador++;


        string linea = nuevo.getnombre() + " " + nuevo.getdescripcion();
        istringstream iss(linea);
        string palabra;

        
        while(iss >> palabra) {
            tabla.insertar(minusculas(palabra), &(*it_nuevo));
        }
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

void DiccionarioProductos::palabras(string palabra){
    cout << "palabras " << palabra << '\n';
    tabla.consultar(minusculas(palabra));
}