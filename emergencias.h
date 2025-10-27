#indef EMERGENCIAS_H
#define EMERGENCIAS_H

#include <iostream>
#include <string>

using namespace std;

struct Incidente 
{
	int prioridad;
	string descripcion;
	string ubicacion;

	Incidente(int p, string d, string u);
};

struct Nodo
{
	Incidente* incidente;
	int npl;
	Nodo* izq;
	Nodo* der;

	Nodo(Incidente* inc)
};

Nodo* insertarIncidente(Nodo* heap, Incidente* nuevoIncidente);

#endif

/*henrypillpe*/
Nodo* atenderIncidente(Nodo* heap);
void mostrarIncidente(Incidente* incidente);

//*********
Nodo* fusionarZonas(Nodo* zonaA, Nodo* zonaB);


