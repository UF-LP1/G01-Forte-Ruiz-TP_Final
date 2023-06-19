#pragma once
#ifndef _CPLASMA_H
#define _CPLASMA_H
#include "cFLUIDO.h"
#include "eTIPO.h"

class cPLASMA : public cFLUIDO {
	eTIPO tipo;
public:
	cPLASMA(unsigned int volumen, eTIPO tipo);
	~cPLASMA();

	bool compatibilidad(cFLUIDO* donante);// bool operator==(cFLUIDO* donante, cFLUIDO* receptor)
	bool verificar_fecha_maxima(time_t fecha_extraccion);
	eTIPO get_tipo();
	string to_string() const;
	void imprimir();
};
#endif // !_CPLASMA_H

