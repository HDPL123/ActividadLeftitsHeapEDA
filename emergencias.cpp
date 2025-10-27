#include <iostream>
#include <Algorithm>
#include "emergencias.h"

using namespace std;

Incidente::Incidente(int p, string d, string u)
    : prioridad(p), descripcion(d), ubicacion(u) {
}

Nodo::Nodo(Incidente* inc)
    : incidente(inc), npl(0), izq(nullptr), der(nullptr) {
}

Nodo* merge(Nodo* a, Nodo* b) {
    if (!a) return b;
    if (!b) return a;

    if (a->incidente->prioridad > b->incidente->prioridad)
        swap(a, b);  

    a->der = merge(a->der, b);

    int nplIzq = a->izq ? a->izq->npl : -1;
    int nplDer = a->der ? a->der->npl : -1;

    if (nplIzq < nplDer)
        swap(a->izq, a->der);

    a->npl = (a->der ? a->der->npl : -1) + 1;

    return a;
}

Nodo* insertarIncidente(Nodo* heap, Incidente* nuevoIncidente) {
    Nodo* nuevoNodo = new Nodo(nuevoIncidente);
    return merge(heap, nuevoNodo);
}
