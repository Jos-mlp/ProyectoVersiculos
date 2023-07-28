#ifndef NODO_H
#define NODO_H
#include <string>

using namespace std;

class Nodo
{
private:
	string pasaje;
	string texto;
	Nodo* siguiente;

public:
    //constructores
	Nodo();
	Nodo(string texto, string pasaje);

	//Modificadores
	void ModificarPasaje(string pasaje);
    void ModificarTexto(string texto);
	void ModificarSiguiente(Nodo* siguiente);

	//Obtensores
	string ObtenerPasaje();
	string ObtenerTexto();
	Nodo* ObtenerSiguiente();
};

#endif // NODO_H
