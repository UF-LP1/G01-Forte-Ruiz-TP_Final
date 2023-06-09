#include "cHISTORIAL.h"

using namespace std;

cHISTORIAL::cHISTORIAL(bool tiene_tattoo, time_t ult_tattoo, bool enfermedades)
{
	this->tiene_tattoo = tiene_tattoo;
	this->ult_tattoo = ult_tattoo;
	this->enfermedades = enfermedades;
}

cHISTORIAL::~cHISTORIAL()
{
}

//setters

void cHISTORIAL::set_tiene_tattoo(bool tiene_tattoo)
{
	this->tiene_tattoo = tiene_tattoo;
}

void cHISTORIAL::set_ult_tattoo(time_t ult_tattoo)
{
	this->ult_tattoo = ult_tattoo;

}

void cHISTORIAL::set_enfermedades(bool enfermedades)
{
	this->enfermedades = enfermedades;
}

//getters

bool cHISTORIAL::get_tiene_tattoo()
{
	return this->tiene_tattoo;
}

time_t cHISTORIAL::get_ult_tattoo()
{
	return this->ult_tattoo;
}

bool cHISTORIAL::get_enfermedades() const
{
	return this->enfermedades;
}

string cHISTORIAL::to_string_HIST() const
{
	string c;
	struct tm fecha;
	localtime_s(&fecha, (const time_t*)this->ult_tattoo);

	c.append("Tiene enfermedades sanguineas: ");
	if (this->get_enfermedades())
		c.append("SI.");
	else
		c.append("NO.");

	if (this->tiene_tattoo)
	{
		c.append(", FECHA DE ULTIMO TATUAJE: "); 
		c.append(to_string(fecha.tm_mday)); c.append("/"); c.append(to_string(fecha.tm_mon + 1)); c.append("/"); c.append(to_string(fecha.tm_year + 1900));
	}
	

	return c;
}
