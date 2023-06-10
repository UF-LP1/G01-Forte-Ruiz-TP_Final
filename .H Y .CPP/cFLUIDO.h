#pragma once
#include "cREGISTRO.h"
#include "eTIPO.h"
#include <ctime>
class cFLUIDO {
protected:
	unsigned int volumen;
public:
	cFLUIDO(unsigned int volumen);
	~cFLUIDO();

	virtual bool verificar_fecha_maxima(cREGISTRO* registro) = 0;
	virtual bool compatibilidad(cFLUIDO* donante) = 0;// bool operator==(cFLUIDO* donante, cFLUIDO* receptor)

	void set_volumen(unsigned int volumen);
	unsigned int get_volumen();
};