#include "cPACIENTE.h"

cPACIENTE::cPACIENTE(int edad, string nombre, time_t fecha_nacimiento, string telefono, eSEXO sexo, cFLUIDO* fluido, cCENTRO* centro, string dni)
{
	this->nombre = nombre;
	this-> fecha_nacimiento = fecha_nacimiento;
	this->telefono = telefono;
	this->sexo = sexo;
	this->fluido = fluido;
	this->centro = centro;
	this->edad = edad;
	this->dni = dni;
}

cPACIENTE::~cPACIENTE()
{
}

bool cPACIENTE::operator==(cPACIENTE* pac2)
{
	if (this->dni == pac2->get_dni())
		return true;
	else
		return false;
}


//setter

void cPACIENTE::set_centro(cCENTRO* centro)
{
	this->centro = centro;
}
void cPACIENTE::set_edad(int edad)
{
	this->edad = edad;
}
void cPACIENTE::set_nombre(string nombre)
{
	this->nombre = nombre;
}
void cPACIENTE::set_fecha_nacimiento(time_t fecha_nac)
{
	this->fecha_nacimiento = fecha_nac;
}
void cPACIENTE::set_telefono(string telefono)
{
	this->telefono = telefono;
}
void cPACIENTE::set_sexo(eSEXO sexo)
{
	this->sexo = sexo;
}

void cPACIENTE::set_fluido(cFLUIDO* fluido)
{
	this->fluido = fluido;
}

//getters

string cPACIENTE::get_nombre()
{
	return this->nombre;
}

int cPACIENTE::get_edad()
{
	return this->edad;
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

cFLUIDO* cPACIENTE::get_fluido()
{
	return this->fluido;
}

cCENTRO* cPACIENTE::get_centro()
{
	return this->centro;
}

string cPACIENTE::get_dni()
{
	return this->dni;
}
