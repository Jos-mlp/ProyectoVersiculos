#include "Lista.h"

Lista::Lista() {
	this->frente = nullptr;
	this->fondo = nullptr;
	this->tamanio = 0;
}
string Lista::Recorrer() {
	string resultado;
	Nodo* aux = this->frente;
	while (aux != nullptr) {
		resultado = resultado + aux->ObtenerPasaje() + '\n'+ aux->ObtenerTexto() + '\n';
		if (aux->ObtenerSiguiente() != nullptr)
			resultado = resultado + "-";
		aux = aux->ObtenerSiguiente();
	}
	return resultado;
}

void Lista::InsertarInicio(string pasa, string text) {
	Nodo* nuevo = new Nodo();
	nuevo->ModificarPasaje(pasa);
	nuevo->ModificarTexto(text);

	if (this->frente == nullptr && this->fondo == nullptr) {
		this->frente = nuevo;
		this->fondo = nuevo;
		this->tamanio = 1;
	}
	else {
		Nodo* aux = this->frente;
		this->frente = nuevo;
		nuevo->ModificarSiguiente(aux);
		this->tamanio++;
	}
}

void Lista::InsertarFinal(string pasa, string text){
	Nodo* nuevo = new Nodo();
	nuevo->ModificarPasaje(pasa);
	nuevo->ModificarTexto(text);

	if (this->frente == nullptr && this->fondo == nullptr) {
		this->frente = nuevo;
		this->fondo = nuevo;
		this->tamanio = 1;
	}
	else {
		Nodo* aux = this->fondo;
		this->fondo = nuevo;
		aux->ModificarSiguiente(fondo);
		nuevo->ModificarSiguiente(NULL);
		this->tamanio++;
	}
}


Nodo * Lista::BuscarEspecifico(string referencia)
{
	Nodo* aux = this->frente;
	while (aux != nullptr) {
		if (aux->ObtenerPasaje() == referencia) {
			return aux;
		}
		aux = aux->ObtenerSiguiente();
	}
	return aux;
}
