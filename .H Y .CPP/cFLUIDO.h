#pragma once
#include "cREGISTRO.h"
#include "eTIPO.h"
#include <ctime>
#include <sstream>

class cFLUIDO {
protected:
	unsigned int volumen;
public:
	cFLUIDO(unsigned int volumen);
	~cFLUIDO();

	virtual bool verificar_fecha_maxima(cREGISTRO* registro) = 0;
	virtual bool compatibilidad(cFLUIDO* donante) = 0;
	virtual string to_string()=0;
	void imprimir();//CREO que no es virtual

	void set_volumen(unsigned int volumen);
	unsigned int get_volumen();
};