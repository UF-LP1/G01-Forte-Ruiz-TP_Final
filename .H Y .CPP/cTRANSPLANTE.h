#pragma once
#include <ctime>
#include "cRECEPTOR.h"
#include "cSANGRE.h"
#include "cPLASMA.h"
#include "cMEDULA.h"
#include "cCENTRO.h"

class cTRANSPLANTE {
	time_t fecha;
	cRECEPTOR paciente;
	cCENTRO centro;
	cFLUIDO* fluido;
	bool resultado;
public:
	cTRANSPLANTE(time_t fecha, cRECEPTOR paciente, cCENTRO centro, cFLUIDO* fluido, bool resultado);
	~cTRANSPLANTE();
	void imprimir();
};