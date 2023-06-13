#pragma once
#include "cFLUIDO.h"

using namespace std;

class cMEDULA : public cFLUIDO {
public:
	cMEDULA(unsigned int volumen);
	~cMEDULA();	

	bool compatibilidad(cFLUIDO* donante);
	bool verificar_fecha_maxima(cREGISTRO* registro);

	string to_string_MED() const;
	//string to_string();
};
	
	
	

	
	
	