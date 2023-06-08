#pragma once
#include "cFLUIDO.h"
#include "eTIPO.h"

class cPLASMA : public cFLUIDO {
	eTIPO tipo;
public:
	cPLASMA(unsigned int volumen);
	~cPLASMA();

	bool compatibilidad(cFLUIDO* donante);// bool operator==(cFLUIDO* donante, cFLUIDO* receptor)
	bool verificar_fecha_maxima(cREGISTRO* registro);
	eTIPO get_tipo();
	string to_string_PLASMA();
};
	