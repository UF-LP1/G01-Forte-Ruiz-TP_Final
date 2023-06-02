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
	cFLUIDO fluido;
	cCENTRO centro;
public:
	cPACIENTE(string nombre, time_t fecha_nacimiento, string telefono, eSEXO sexo, cFLUIDO fluido, cCENTRO centro);
	~cPACIENTE();

	void set_centro(cCENTRO centro);

	string get_nombre();
	time_t get_fecha_nacimiento();
	string get_telefono();
	eSEXO get_sexo();
	cFLUIDO get_fluido();
	cCENTRO get_centro();

};