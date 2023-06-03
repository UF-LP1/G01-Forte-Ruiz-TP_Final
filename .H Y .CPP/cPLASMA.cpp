#include "cPLASMA.h"

cPLASMA::cPLASMA(unsigned int volumen):cFLUIDO(volumen)
{
}

cPLASMA::~cPLASMA()
{
}

eTIPO cPLASMA::get_tipo()
{
	return this->tipo;
}
