#include "cDONANTE.h"

using namespace std;

cDONANTE::cDONANTE(string nombre, time_t fecha_nacimiento, string telefono, eSEXO sexo, cCENTRO centro, cFLUIDO fluido_dona, vector<cREGISTRO> registros, unsigned int edad, float peso, cHISTORIAL historial) : cPACIENTE( nombre, fecha_nacimiento, telefono, sexo, centro) 
{
	this->fluido_dona = fluido_dona;
	this->registros = registros;
	this->edad = edad;
	this->peso = peso;
	this->historial = historial;
}

cDONANTE::~cDONANTE()
{
}

//setters

void cDONANTE::set_fluido_dona(cFLUIDO fluido_dona)
{
	this->fluido_dona = fluido_dona;
}

void cDONANTE::set_registros(vector<cREGISTRO> registros)
{
	this->registros = registros;
}

void cDONANTE::set_edad(unsigned int edad)
{
	this->edad = edad;
}

void cDONANTE::set_peso(float peso)
{
	this->peso = peso;
}

void cDONANTE::set_historial(cHISTORIAL historial)
{
	this->historial = historial;
}

//getters

cFLUIDO cDONANTE::get_fluido_dona()
{
	return this->fluido_dona;
}

vector<cREGISTRO> cDONANTE::get_registros()
{
	return this->registros;
}

unsigned int cDONANTE::get_edad()
{
	return this->edad;
}

float cDONANTE::get_peso()
{
	return this->peso;
}

cHISTORIAL cDONANTE::get_historial()
{
	return this->historial;
}
