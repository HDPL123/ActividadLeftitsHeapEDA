#include <iostream>
#include "emergencias.hpp"

using namespace std;

void mostrarMenu() {
    cout << "\n===== Emergencias Smart City =====\n";
    cout << "1. Insertar incidente\n";
    cout << "2. Atender incidente\n";
    cout << "3. Ver incidente mas urgente\n";
    cout << "4. Fusionar zonas\n";
    cout << "5. Mostrar todos los incidentes\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion: ";
}

Incidente* incidenteMasUrgente(Nodo* heap) {    //Joaquin Lescano
    return heap ? heap->incidente : nullptr;
}

void printHeap(Nodo* heap, int nivel = 0) {
    if (!heap) return;
    for (int i = 0; i < nivel; ++i) cout << "  ";
    cout << "- [" << heap->incidente->prioridad << "] "
        << heap->incidente->descripcion << " (" << heap->incidente->ubicacion << ")\n";
    printHeap(heap->izq, nivel + 1);
    printHeap(heap->der, nivel + 1);
}

int main() {
    Nodo* zonaA = nullptr;
    Nodo* zonaB = nullptr;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1: {
            int prioridad;
            string descripcion, ubicacion;
            cout << "Prioridad: ";
            cin >> prioridad;
            cin.ignore();
            cout << "Descripcion: ";
            getline(cin, descripcion);
            cout << "Ubicacion: ";
            getline(cin, ubicacion);
            Incidente* nuevo = new Incidente(prioridad, descripcion, ubicacion);
            zonaA = insertarIncidente(zonaA, nuevo);
            break;
        }
        case 2:
            zonaA = atenderIncidente(zonaA);
            break;
        case 3: {
            Incidente* urgente = incidenteMasUrgente(zonaA);
            if (urgente) mostrarIncidente(urgente);
            else cout << "No hay incidentes.\n";
            break;
        }
        case 4:
            zonaB = insertarIncidente(zonaB, new Incidente(2, "Incendio", "Zona B"));
            zonaB = insertarIncidente(zonaB, new Incidente(5, "Robo", "Zona B"));
            zonaA = fusionarZonas(zonaA, zonaB);
            zonaB = nullptr;
            cout << "Zonas fusionadas.\n";
            break;
        case 5:
            printHeap(zonaA);
            break;
        case 0:
            cout << "Saliendo\n";
            break;
        default:
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}

