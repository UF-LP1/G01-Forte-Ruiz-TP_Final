#pragma once
#ifndef _CFLUIDO_H
#define _CFLUIDO_H
#include "eTIPO.h"
#include <ctime>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class cFLUIDO {
protected:
	unsigned int volumen;
public:
	cFLUIDO(unsigned int volumen);
	~cFLUIDO();

	virtual bool verificar_fecha_maxima(time_t fecha_extraccion) = 0;
	virtual bool compatibilidad(cFLUIDO* donante) = 0;
	virtual string to_string() const = 0;


	void set_volumen(unsigned int volumen);
	unsigned int get_volumen();
};
#endif // !_CFLUIDO_H

