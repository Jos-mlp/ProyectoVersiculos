#include "Nodo.h"

Nodo::Nodo() {
	this->pasaje = "";
	this->texto="";
	this->siguiente = nullptr;
}

Nodo::Nodo(string pasa, string text) {
	this->pasaje = pasa;
	this->texto=text;
	this->siguiente = nullptr;
}

void Nodo::ModificarPasaje(string pasa) {
	this->pasaje = pasa;
}

void Nodo::ModificarTexto(string text) {
	this->texto = text;
}

void Nodo::ModificarSiguiente(Nodo* siguiente) {
	this->siguiente = siguiente;
}

string Nodo::ObtenerPasaje() {
	return this->pasaje;
}

string Nodo::ObtenerTexto() {
	return this->texto;
}

Nodo* Nodo::ObtenerSiguiente() {
	return this->siguiente;
}
