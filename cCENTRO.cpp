#include "cCENTRO.h"

cCENTRO::cCENTRO(string nombre, string direccion, string partido, string provincia, string telefono)
{
	this->nombre = nombre;
	this->direccion = direccion;
	this->partido = partido;
	this->provincia = provincia;
	this->telefono = telefono;
}

cCENTRO::~cCENTRO()
{
}

//getters

string cCENTRO::get_nombre()
{
	return this->nombre;
}

string cCENTRO::get_direccion()
{
	return this->direccion;
}

string cCENTRO::get_partido()
{
	return this->partido;
}

string cCENTRO::get_provincia()
{
	return this->provincia;
}

string cCENTRO::get_telefono()
{
	return this->telefono;
}
