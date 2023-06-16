#pragma once
#ifndef _CSANGRE_H
#define _CSANGRE_H
#include "cFLUIDO.h"
#include "eTIPO.h"

class cSANGRE : public cFLUIDO {
	eTIPO tipo;
	bool Rh;
public:
	cSANGRE(unsigned int volumen, eTIPO tipo, bool Rh);
	~cSANGRE();

	eTIPO get_tipo();
	bool get_Rh();

	bool verificar_fecha_maxima(cREGISTRO* registro);
	bool compatibilidad(cFLUIDO* donante);

	string to_string() const;
	void imprimir();
};
#endif // !_CSANGRE_H

