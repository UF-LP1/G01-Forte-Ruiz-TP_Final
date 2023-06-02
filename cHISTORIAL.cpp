#include "cHISTORIAL.h"

using namespace std;

cHISTORIAL::cHISTORIAL(time_t ult_tattoo, bool enfermedades)
{
	this->ult_tattoo = ult_tattoo;
	this->enfermedades = enfermedades;
}

cHISTORIAL::~cHISTORIAL()
{
}

//setters

void cHISTORIAL::set_ult_tattoo(time_t ult_tattoo)
{
	this->ult_tattoo = ult_tattoo;

}

void cHISTORIAL::set_enfermedades(bool enfermedades)
{
	this->enfermedades = enfermedades;
}

//getters

time_t cHISTORIAL::get_ult_tattoo()
{
	return this->ult_tattoo;
}

bool cHISTORIAL::get_enfermedades()
{
	return this->enfermedades;
}
