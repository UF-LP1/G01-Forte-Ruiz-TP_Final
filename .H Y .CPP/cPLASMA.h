#pragma once
#include "cFLUIDO.h"
#include "eTIPO.h"

class cPLASMA : public cFLUIDO {
	eTIPO tipo;
public:
	cPLASMA(unsigned int volumen);
	~cPLASMA();

	eTIPO get_tipo();
};
	