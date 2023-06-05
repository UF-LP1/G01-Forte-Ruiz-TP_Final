#pragma once
#include <string>
#include <ctime>
#include "cCENTRO.h"
#include "eSEXO.h"
#include "cFLUIDO.h"

using namespace std;


class cPACIENTE {
protected:
	string nombre;
	time_t fecha_nacimiento;
	string telefono;
	eSEXO sexo;
	cFLUIDO* fluido;
	cCENTRO centro;
	string dni;
public:
	cPACIENTE(string nombre, time_t fecha_nacimiento, string telefono, eSEXO sexo, cFLUIDO* fluido, cCENTRO centro, string dni);
	~cPACIENTE();

	void imprimir();

	void set_centro(cCENTRO centro);
	void set_nombre(string nombre);
	void set_fecha_nacimiento(time_t fecha_nac);
	void set_telefono(string telefono);
	void set_sexo(eSEXO sexo);
	void set_fluido(cFLUIDO* fluido);
	void set_dni(string dni);

	string get_nombre();
	time_t get_fecha_nacimiento();
	string get_telefono();
	eSEXO get_sexo();
	cFLUIDO* get_fluido();
	cCENTRO get_centro();
	string get_dni();
};