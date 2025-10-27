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
x
    return a;
}

Nodo* insertarIncidente(Nodo* heap, Incidente* nuevoIncidente) {
    Nodo* nuevoNodo = new Nodo(nuevoIncidente);
    return merge(heap, nuevoNodo);
}

/*Henry-atenderIncidente*/
Nodo* atenderIncidente(Nodo* heap) {
    if (!heap) return nullptr;

    mostrarIncidente(heap->incidente);
    Nodo* nuevoHeap = merge(heap->izq, heap->der);
    delete heap;
    return nuevoHeap;

}

void mostrarIncidente(Incidente* incidente) {
    if (!incidente) return;
    std::cout << "Prioridad: " << incidente->prioridad << "\n";
    std::cout << "Descripción: " << incidente->descripcion << "\n";
    std::cout << "Ubicación: " << incidente->ubicacion << "\n";
}
Nodo* fusionarZonas(Nodo* zonaA, Nodo* zonaB) {
    return merge(zonaA, zonaB);
}
