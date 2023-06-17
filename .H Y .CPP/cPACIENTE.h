#pragma once
#ifndef _CPACIENTE_H
#define _CPACIENTE_H
#include <string>
#include <ctime>
#include "cCENTRO.h"
#include "eSEXO.h"
#include "cFLUIDO.h"

using namespace std;


class cPACIENTE {
protected:
	string nombre;
	time_t fecha_nacimiento;//struct tm
	int edad;
	string telefono;
	eSEXO sexo;
	cFLUIDO* fluido;
	cCENTRO* centro;
	string dni;
public:
	cPACIENTE(int edad, string nombre, time_t fecha_nacimiento, string telefono, eSEXO sexo, cFLUIDO* fluido, cCENTRO* centro, string dni);
	~cPACIENTE();

	bool operator==(cPACIENTE* pac2);

	virtual string to_string() const = 0;
	void set_centro(cCENTRO* centro);
	void set_edad(int edad);
	void set_nombre(string nombre);
	void set_fecha_nacimiento(time_t fecha_nac);
	void set_telefono(string telefono);
	void set_sexo(eSEXO sexo);
	void set_fluido(cFLUIDO* fluido);


	string get_nombre();
	int get_edad();
	time_t get_fecha_nacimiento();
	string get_telefono();
	eSEXO get_sexo();
	cFLUIDO* get_fluido();
	cCENTRO* get_centro();
	string get_dni();

};
#endif // !_CPACIENTE_H

