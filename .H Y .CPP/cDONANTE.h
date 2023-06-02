#pragma once
#include "cPACIENTE.h"
#include "cFLUIDO.h"
#include "cREGISTRO.h"
#include "cHISTORIAL.h"
#include <vector>

class cDONANTE : public cPACIENTE{
	vector<cREGISTRO> registros;
	unsigned int edad;
	float peso;
	cHISTORIAL historial;

public:
	cDONANTE(string nombre, time_t fecha_nacimiento, string telefono, eSEXO sexo, cFLUIDO fluido, cCENTRO centro, vector<cREGISTRO> registros, unsigned int edad, float peso, cHISTORIAL historial);
	~cDONANTE();

	void set_registros(vector<cREGISTRO> registros);
	void set_edad(unsigned int edad);// DETALLE: si cae la fecha de nacimiento la tiene que updatear
	void set_peso(float peso);// nie
	void set_historial(cHISTORIAL historial);// nie

	vector<cREGISTRO> get_registros();
	unsigned int get_edad();
	float get_peso();
	cHISTORIAL get_historial();

};
	