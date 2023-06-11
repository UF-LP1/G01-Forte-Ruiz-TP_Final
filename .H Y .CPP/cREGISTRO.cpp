#include "cREGISTRO.h"

using namespace std;

cREGISTRO::cREGISTRO(cFLUIDO* fluido,time_t fecha_extraccion, cCENTRO* centro)
{
	this->fluido = fluido;
	this->fecha_extraccion = fecha_extraccion;
	this->centro = centro;
}

cREGISTRO::cREGISTRO()
{
	this->fluido = nullptr;
	this->fecha_extraccion = time(NULL);
	this->centro = nullptr;
}

cREGISTRO::~cREGISTRO()
{
}

cFLUIDO* cREGISTRO::get_fluido()
{
	return this->fluido;
}

time_t cREGISTRO::get_fecha_extraccion()
{
	return this->fecha_extraccion;
}

cCENTRO* cREGISTRO::get_centro()
{
	return this->centro;
}

void cREGISTRO::set_fluido(cFLUIDO* fluid)
{
	this->fluido = fluid;

}

void cREGISTRO::set_fecha_extraccion(time_t fecha)
{
	this->fecha_extraccion = fecha;
}

void cREGISTRO::set_centro(cCENTRO* centro)
{
	this->centro = centro;
}

string cREGISTRO::to_string_REGIS() const
{
	string c;
	struct tm fecha;
	cSANGRE* ptr1;
	cMEDULA* ptr2;
	cPLASMA* ptr3;

	localtime_s(&fecha, (const time_t*)(this->get_fecha_extraccion())); //CHECKEAR CASTEO

	c.append(to_string(fecha.tm_mday)); c.append("/"); c.append(to_string(fecha.tm_mon + 1)); c.append("/"); c.append(to_string(fecha.tm_year + 1900));
	c.append(", DONACION: ");
	
	ptr1 = dynamic_cast<cSANGRE*>(this->get_fluido());
	ptr2 = dynamic_cast<cMEDULA*>(this->get_fluido());
	ptr3 = dynamic_cast<cPLASMA*>(this->get_fluido());

	if (ptr1 != nullptr)
		c.append(ptr1->to_string_SANGRE());  
	else if(ptr2 != nullptr)
		c.append(ptr2->to_string_MED());
	else if(ptr3 != nullptr)
		c.append(ptr3->to_string_PLASMA());
	c.append(", SE ATIENDE EN: "); c.append(this->get_centro()->to_string_CENTRO());
	
}
