#include "cSANGRE.h"

cSANGRE::cSANGRE(unsigned int volumen, eTIPO tipo, bool Rh):cFLUIDO(volumen)
{
	this->tipo = tipo;
	this->Rh = Rh;
}

cSANGRE::~cSANGRE()
{
}

eTIPO cSANGRE::get_tipo()
{
	return this->tipo;
}

bool cSANGRE::get_Rh()
{
	return this->Rh;
}
