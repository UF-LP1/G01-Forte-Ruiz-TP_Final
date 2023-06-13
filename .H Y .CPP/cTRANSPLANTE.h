#pragma once
#include <ctime>
#include "cRECEPTOR.h"
#include "cSANGRE.h"
#include "cPLASMA.h"
#include "cMEDULA.h"
#include "cCENTRO.h"

//nota: no necesite añadir sstream, supongo que viene de fluido y paciente
class cTRANSPLANTE {
	time_t fecha;
	cRECEPTOR* paciente;
	cCENTRO* centro;
	cFLUIDO* fluido;
	bool resultado;
public:
	cTRANSPLANTE(time_t fecha, cRECEPTOR* paciente, cCENTRO* centro, cFLUIDO* fluido, bool resultado);
	~cTRANSPLANTE();
	void imprimir();
	string to_string();
};