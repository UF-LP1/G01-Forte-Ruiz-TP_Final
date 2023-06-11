#pragma once
#include "cFLUIDO.h"
#include "cCENTRO.h"
#include <ctime>

using namespace std;

class cREGISTRO {
	cFLUIDO* fluido;
	time_t fecha_extraccion;
	cCENTRO* centro;
public:
	cREGISTRO(cFLUIDO* fluido, time_t fecha_extraccion, cCENTRO* centro);
	cREGISTRO();
	~cREGISTRO();

	cFLUIDO* get_fluido();
	time_t get_fecha_extraccion();
	cCENTRO* get_centro();

	void set_fluido(cFLUIDO* fluid);
	void set_fecha_extraccion(time_t fecha);
	void set_centro(cCENTRO* centro);

	string to_string_REGIS() const;
};