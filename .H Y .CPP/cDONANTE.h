#pragma once
#include "cPACIENTE.h"
#include "cFLUIDO.h"
#include "cREGISTRO.h" 
#include "cHISTORIAL.h"
#include <vector>

class cDONANTE : public cPACIENTE{
	vector<cREGISTRO> registros;
	float peso;
	cHISTORIAL* historial;

public:
	cDONANTE(string nombre, time_t fecha_nacimiento, string telefono, eSEXO sexo, cFLUIDO* fluido, cCENTRO* centro, string dni, vector<cREGISTRO> registros, float peso, cHISTORIAL* historial);
	~cDONANTE();
	void imprimir();

	void set_registros(vector<cREGISTRO> registros);
	void set_peso(float peso);// nie
	void set_historial(cHISTORIAL* historial);// nie

	vector<cREGISTRO> get_registros();
	float get_peso();
	cHISTORIAL* get_historial();

	void crear_registro(cFLUIDO* fluido);

	string to_string_DONANTE() const;
	void imprimir_DONANTE(); //SOBRECARGA DEL <<?? EN CADA IMPRIMIR SERIA
};
	