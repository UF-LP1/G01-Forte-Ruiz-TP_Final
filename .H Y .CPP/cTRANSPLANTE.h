#pragma once
#include <ctime>
#include "cRECEPTOR.h"
#include "cSANGRE.h"
#include "cPLASMA.h"
#include "cMEDULA.h"
#include "cCENTRO.h"

//nota: no necesite a�adir sstream, supongo que viene de fluido y paciente
class cTRANSPLANTE {
	time_t fecha;
	bool resultado;
	static int num_transplante; 
public:
	cTRANSPLANTE(time_t fecha, bool resultado);
	~cTRANSPLANTE();
	void imprimir();
	string to_string() const;
};