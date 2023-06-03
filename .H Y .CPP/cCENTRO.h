#pragma once
#include <string>
#include "ePROVINCIA.h"
#include <ctime>
using namespace std;

class cCENTRO {
	string nombre;
	string direccion;
	string partido;
	ePROVINCIA provincia;
	string telefono;
public:
	cCENTRO(string nombre, string direccion, string partido, ePROVINCIA provincia, string telefono);
	~cCENTRO();
	 
	void imprimir();

	//Que pasa si el paciente se debe mudar? Deberia poder modificarse

	string get_nombre();
	string get_direccion();
	string get_partido();
	string get_provincia();
	string get_telefono();
};