#indef EMERGENCIAS_HPP
#define EMERGENCIAS_HPP

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


