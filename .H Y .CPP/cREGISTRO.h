#pragma once
#include "cFLUIDO.h"
#include "cCENTRO.h"
#include <ctime>

using namespace std;

class cREGISTRO {
	cFLUIDO fluido;
	time_t fecha_extraccion;
	cCENTRO centro;
public:
	cREGISTRO(cFLUIDO fluido, time_t fecha_extraccion, cCENTRO centro);
	~cREGISTRO();

	cFLUIDO get_fluido();
	time_t get_fecha_extraccion();
	cCENTRO get_centro();
};