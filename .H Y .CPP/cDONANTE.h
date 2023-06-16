#pragma once
#ifndef _CDONANTE_H
#define _CDONANTE_H

#include "cPACIENTE.h"
#include "cFLUIDO.h"
#include "cREGISTRO.h" 
#include "cHISTORIAL.h"
#include <vector>

class cDONANTE : public cPACIENTE {
	vector<cREGISTRO> registros;
	float peso;
	cHISTORIAL* historial;

public:
	cDONANTE(int edad, string nombre, time_t fecha_nacimiento, string telefono, eSEXO sexo, cFLUIDO* fluido, cCENTRO* centro, string dni, vector<cREGISTRO> registros, float peso, cHISTORIAL* historial);
	~cDONANTE();
	void imprimir();


	void set_registros(vector<cREGISTRO> registros);
	void set_peso(float peso);// nie
	void set_historial(cHISTORIAL* historial);// nie

	vector<cREGISTRO> get_registros();
	float get_peso();
	cHISTORIAL* get_historial();

	void crear_registro();
	void imprimir();
	string to_string() const;

};

#endif // !_CDONANTE_H


	