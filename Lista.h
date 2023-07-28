#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"

class Lista
{
private:
	int tamanio;
	Nodo* frente;
	Nodo* fondo;
public:
	// Constructores
	Lista();

	// Insertar
	void InsertarInicio(string pasa,string text);
	void InsertarFinal(string pasa,string text);


	// Buscar
	Nodo* BuscarEspecifico(string referencia);


	// Métodos auxiliares
	bool EstaVacia();
	int ObtenerTamanio();
	string Recorrer();
};

#endif // LISTA_H
