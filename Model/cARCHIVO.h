#pragma once
#ifndef _CARCHIVO_H
#define _CARCHIVO_H
#include <fstream>
#include "cCENTRO.h"
#include "cDONANTE.h"
#include "cFLUIDO.h"
#include "cHISTORIAL.h"
#include "cMEDULA.h"
#include "cPACIENTE.h"
#include "cPLASMA.h"
#include "cRECEPTOR.h"
#include "cREGISTRO.h"
#include "cSANGRE.h"

using namespace std;

class cARCHIVO {
	ifstream* fpin;
	ofstream* fpout;

public:
	cARCHIVO(ifstream* fpin, ofstream* fpout);
	~cARCHIVO();

	void set_fpin(ifstream* fpin);
	void set_fpout(ofstream* fpout);

	ifstream* get_fpin();
	ofstream* get_fpout();

	void leer_HISTORIALES(vector<cHISTORIAL>& historiales);
	void leer_REGISTROS();
	void leer_SANGRE();
	void leer_MEDULA();
	void leer_PLASMA();
	void leer_DONANTES();
	void leer_RECEPTORES();
	void leer_CENTROS();

	void escribir_HISTORIALES(cHISTORIAL historial, int pos);
	void escribir_REGISTROS();
	void escribir_SANGRE();
	void escribir_MEDULA();
	void escribir_PLASMA();
	void escribir_DONANTES();
	void escribir_RECEPTORES();
	void escribir_CENTROS();


};
#endif
