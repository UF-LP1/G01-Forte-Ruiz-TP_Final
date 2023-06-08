#include "cTRANSPLANTE.h"

cTRANSPLANTE::cTRANSPLANTE(time_t fecha, cRECEPTOR* paciente, cCENTRO* centro, cFLUIDO* fluido, bool resultado)
{
	this->fecha = fecha;
	this->paciente = paciente;
	this->centro = centro;
	this->fluido = fluido;
	this->resultado = resultado;
	return;
}

cTRANSPLANTE::~cTRANSPLANTE()
{
}

void cTRANSPLANTE::imprimir()
{
}
