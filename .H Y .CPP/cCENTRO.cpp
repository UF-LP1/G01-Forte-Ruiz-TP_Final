#include "cCENTRO.h"

cCENTRO::cCENTRO(string nombre, string direccion, string partido, ePROVINCIA provincia, string telefono)
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

bool cCENTRO::realizar_transplante()
{
	bool a;
	srand(time(NULL));
	a = rand() % 1;// los valores bool son 0 y 1?? si no funciona hacer los if
	return a;
}

void cCENTRO::imprimir()
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
