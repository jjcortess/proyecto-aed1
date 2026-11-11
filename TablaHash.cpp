#include "TablaHash.h"
#include <iostream>
#include <string>
#include <sstream>
#include <list>

TablaHash::TablaHash() {
    B = 101;
    nElem = 0;
    T = new list<Par>[B];
}

TablaHash::~TablaHash() {
    delete[] T;
}

int siguientePrimo(int p){
    return p;
}

void TablaHash::reestructurar(){
    int B_antiguo = B;
    list<Par>* T_antigua = T;

    B = B*2 + 1; //un impar o un primo yo q se
    T = new list<Par>[B];

    for (int i=0; i<B_antiguo; i++){
        list<Par>::iterator it = T_antigua[i].begin();
        for (it; it != T_antigua[i].end(); it++){
            unsigned int nuevo_hash = fdispersion(it->palabra);
            T[nuevo_hash].push_back(*it);
        }
    }
    delete[] T_antigua;
}

unsigned int TablaHash::fdispersion(string palabra){
    unsigned int hash = 0;
    unsigned int p = 31;
    for (char c : palabra){
        hash = hash*p + (unsigned char)c;
    }

    return hash%B;
}

void TablaHash::insertar(string palabra, Producto *nuevo){
    unsigned int hash = fdispersion(palabra); 
    for (list<Par>::iterator it = T[hash].begin(); it != T[hash].end(); it++){
        if (it->palabra == palabra){

            
            for(list<Producto*>::iterator itProds = it->l.begin(); itProds != it->l.end(); itProds++){
                if(*itProds == nuevo) return;
            }

            it->l.push_back(nuevo);
            return;

        }
    }

    // si no está ya la palabra:

    Par nuevoPar;
    nuevoPar.palabra = palabra;
    nuevoPar.l.push_back(nuevo);

    T[hash].push_back(nuevoPar);
    nElem++;


    if (nElem > B-5) reestructurar();

}


void consultar (string nombre){



}



