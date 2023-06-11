#include "cRECEPTOR.h"

using namespace std;

cRECEPTOR::cRECEPTOR(string nombre, time_t fecha_nacimiento, string telefono, eSEXO sexo, cFLUIDO* fluido, cCENTRO* centro, string dni, time_t fecha_ingreso, ePRIORIDAD prioridad, eESTADO estado):cPACIENTE( nombre, fecha_nacimiento, telefono, sexo, fluido, centro, dni)
{
	this->fecha_ingreso = fecha_ingreso;
	this->prioridad = prioridad;
	this->estado = estado;
}

cRECEPTOR::~cRECEPTOR()
{
}

void cRECEPTOR::imprimir()
{
}

bool cRECEPTOR::operator==(cDONANTE* donante)
{
	cSANGRE* ptr1 = dynamic_cast<cSANGRE*>(donante->get_fluido());
	cSANGRE* ptr2 = dynamic_cast<cSANGRE*>(this->fluido);

	if (ptr1 != nullptr && ptr2 != nullptr && ptr2->compatibilidad(ptr1))
		return true;

	cMEDULA* ptr3 = dynamic_cast<cMEDULA*>(donante->get_fluido());
	cMEDULA* ptr4 = dynamic_cast<cMEDULA*>(this->fluido);

	if (ptr3 != nullptr && ptr4 != nullptr && ptr4->compatibilidad(ptr3)) // checkear condiciones
		return true;

	cPLASMA* ptr5 = dynamic_cast<cPLASMA*>(donante->get_fluido());
	cPLASMA* ptr6 = dynamic_cast<cPLASMA*>(this->fluido);

	if (ptr5 != nullptr && ptr6 != nullptr && ptr6->compatibilidad(ptr5))
		return true;

	return false;
	
}


void cRECEPTOR::set_prioridad(ePRIORIDAD prioridad)
{
	this->prioridad = prioridad;
}

void cRECEPTOR::set_estado(eESTADO estado)
{
	this->estado = estado;
}

void cRECEPTOR::set_fecha(time_t fecha)
{
	this->fecha_ingreso = fecha;
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
