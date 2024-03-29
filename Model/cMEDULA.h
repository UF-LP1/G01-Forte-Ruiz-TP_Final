#pragma once
#ifndef _CMEDULA_H
#define _CMEDULA_H
#include "cFLUIDO.h"
#include "eCOLOR.h"

using namespace std;

class cMEDULA : public cFLUIDO {
	eCOLOR color;
public:
	cMEDULA(unsigned int volumen, eCOLOR color);
	~cMEDULA();

	void set_color(eCOLOR color);
	eCOLOR get_color();

	bool compatibilidad(cFLUIDO* donante);
	bool verificar_fecha_maxima(time_t fecha_extraccion);

	string to_string() const;
	void imprimir();
};

#endif // !_CMEDULA_H

	
	

	
	
	