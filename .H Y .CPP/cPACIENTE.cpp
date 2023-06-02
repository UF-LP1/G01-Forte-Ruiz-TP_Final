#include "cPACIENTE.h"

cPACIENTE::cPACIENTE(string nombre, time_t fecha_nacimiento, string telefono, eSEXO sexo, cFLUIDO fluido, cCENTRO centro)
{
	this->nombre = nombre;
	this-> fecha_nacimiento = fecha_nacimiento();
	this->telefono = telefono;
	this->sexo = sexo;
	this->fluido = fluido;
	this->centro = centro;

}

cPACIENTE::~cPACIENTE()
{
}

//setter

void cPACIENTE::set_centro(cCENTRO centro)
{
	this->centro = centro;
}

//getters

string cPACIENTE::get_nombre()
{
	return this->nombre;
}

time_t cPACIENTE::get_fecha_nacimiento()
{
	return this->fecha_nacimiento;
}

string cPACIENTE::get_telefono()
{
	return this->telefono;
}

eSEXO cPACIENTE::get_sexo()
{
	return this->sexo;
}

cFLUIDO cPACIENTE::get_fluido()
{
	return this->fluido;
}

cCENTRO cPACIENTE::get_centro()
{
	return this->centro;
}
