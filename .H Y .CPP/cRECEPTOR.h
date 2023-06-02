#pragma once
#include <ctime>
#include "ePRIORIDAD.h"
#include "eESTADO.h"
#include "cFLUIDO.h"
#include "cPACIENTE.h"

using namespace std;

class cRECEPTOR : public cPACIENTE {
	cFLUIDO fluido_necesita;
	time_t fecha_ingreso;
	ePRIORIDAD prioridad;
	eESTADO estado;
public:
	cRECEPTOR(string nombre, time_t fecha_nacimiento, string telefono, eSEXO sexo, cCENTRO centro, cFLUIDO fluido_necesita, time_t fecha_ingreso, ePRIORIDAD prioridad, eESTADO estado);
	~cRECEPTOR();

	void set_prioridad(ePRIORIDAD prioridad);
	void set_estado(eESTADO estado);

	cFLUIDO get_fluido_necesita();
	time_t get_fecha_ingreso();
	ePRIORIDAD get_prioridad();
	eESTADO get_estado();

};