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

void TablaHash::reestructurar(){

}

unsigned int TablaHash::fdispersion(string palabra){
    unsigned int hash = 0;

}