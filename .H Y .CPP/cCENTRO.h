#pragma once
#include <string>
#include "ePROVINCIA.h"
#include <ctime>
#include "cDONANTE.h"
#include "cRECEPTOR.h"
#include "cTRANSPLANTE.h"

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
	bool realizar_transplante(cDONANTE donante, cRECEPTOR receptor);
	//Que pasa si el paciente se debe mudar? Deberia poder modificarse.

	void set_nombre(string nombre);
	void set_direccion(string direccion);
	void set_partido(string partido);
	void set_provincia(ePROVINCIA provincia);
	void set_telefono(string telefono);
	string get_nombre();
	string get_direccion();
	string get_partido();
	ePROVINCIA get_provincia();
	string get_telefono();
};