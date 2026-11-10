#ifndef TABLAHASH_H
#define TABLAHASH_H

#include <string>
#include "DiccionarioProductos.h"
#include "Producto.h"

using namespace std;





class TablaHash {
private:

    class Par{
    public:
        string palabra;
        list<Producto*> l;
    };

    list<Par> *T;
    int B;
    int nElem;

    unsigned int fdispersion(string palabra);
    void reestructurar();
public:
    TablaHash();
};

#endif