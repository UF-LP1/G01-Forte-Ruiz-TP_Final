#pragma once
#include <ctime>
#include "ePRIORIDAD.h"
#include "eESTADO.h"
#include "cFLUIDO.h"
#include "cPACIENTE.h"

using namespace std;

class cRECEPTOR : public cPACIENTE {
	time_t fecha_ingreso;
	ePRIORIDAD prioridad;
	eESTADO estado;
public:
	cRECEPTOR(string nombre, time_t fecha_nacimiento, string telefono, eSEXO sexo, cFLUIDO fluido, cCENTRO centro, time_t fecha_ingreso, ePRIORIDAD prioridad, eESTADO estado);
	~cRECEPTOR();

	void imprimir();

	void set_prioridad(ePRIORIDAD prioridad);
	void set_estado(eESTADO estado);

	time_t get_fecha_ingreso();
	ePRIORIDAD get_prioridad();
	eESTADO get_estado();

};