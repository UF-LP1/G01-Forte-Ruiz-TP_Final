#include "cFLUIDO.h"

cFLUIDO::cFLUIDO(unsigned int volumen)
{
	this->volumen = volumen;
}

cFLUIDO::~cFLUIDO()
{
}

//setters

void cFLUIDO::imprimir()
{
	cout << to_string();
}

void cFLUIDO::set_volumen(unsigned int volumen)
{
	this->volumen = volumen;

}

//getters

unsigned int cFLUIDO::get_volumen()
{
	return this->volumen;
}
