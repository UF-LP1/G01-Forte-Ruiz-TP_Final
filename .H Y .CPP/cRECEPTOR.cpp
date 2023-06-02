#include "cRECEPTOR.h"

using namespace std;

cRECEPTOR::cRECEPTOR(string nombre, time_t fecha_nacimiento, string telefono, eSEXO sexo, cFLUIDO fluido, cCENTRO centro, time_t fecha_ingreso, ePRIORIDAD prioridad, eESTADO estado):cPACIENTE( nombre, fecha_nacimiento, telefono, sexo, fluido, centro)
{
	this->fecha_ingreso = fecha_ingreso;
	this->prioridad = prioridad;
	this->estado = estado;
}

cRECEPTOR::~cRECEPTOR()
{
}

void cRECEPTOR::set_prioridad(ePRIORIDAD prioridad)
{
	this->prioridad = prioridad;
}

void cRECEPTOR::set_estado(eESTADO estado)
{
	this->estado = estado;
}

time_t cRECEPTOR::get_fecha_ingreso()
{
	return this->fecha_ingreso;
}

ePRIORIDAD cRECEPTOR::get_prioridad()
{
	return this->prioridad;
}

eESTADO cRECEPTOR::get_estado()
{
	return this->estado;
}
