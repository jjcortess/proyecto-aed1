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
        for (it; it != T_antigua[i].begin(); it++){
            unsigned int nuevo_hash = fdispersion(it->palabra);
            //T[nuevo_hash]
        }

    }
}

unsigned int TablaHash::fdispersion(string palabra){
    unsigned int hash = 0;
    unsigned int p = 31;
    for (char c : palabra){
        hash = hash*p + (unsigned char)c;
    }

    return hash%B;
}
