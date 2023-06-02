#include "cREGISTRO.h"

using namespace std;

cREGISTRO::cREGISTRO(cFLUIDO fluido,time_t fecha_extraccion, cCENTRO centro)
{
	this->fluido = fluido;
	this->fecha_extraccion = fecha_extraccion;
	this->centro = centro;
}

cREGISTRO::~cREGISTRO()
{
}

cFLUIDO cREGISTRO::get_fluido()
{
	return this->fluido;
}

time_t cREGISTRO::get_fecha_extraccion()
{
	return this->fecha_extraccion;
}

cCENTRO cREGISTRO::get_centro()
{
	return this->centro;
}
