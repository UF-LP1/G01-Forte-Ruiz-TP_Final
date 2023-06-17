#pragma once
#ifndef _CCENTRO_H
#define _CCENTRO_H


#include <string>
#include <ctime>
#include <iostream>
#include <sstream>
#include "ePROVINCIA.h"
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
	cTRANSPLANTE* realizar_transplante();

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

	string to_string() const;

	void imprimir();

	bool operator==(cCENTRO* centro);

};
#endif // !_CCENTRO_H

