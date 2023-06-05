#pragma once
#include "cFLUIDO.h"

using namespace std;

class cMEDULA : public cFLUIDO {
public:
	cMEDULA(unsigned int volumen);
	~cMEDULA();	

	bool compatibilidad(cFLUIDO* donante);// bool operator==(cFLUIDO* donante, cFLUIDO* receptor)
	bool verificar_fecha_maxima(cREGISTRO* registro);
};
	
	
	

	
	
	