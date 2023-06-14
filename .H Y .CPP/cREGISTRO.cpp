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

string cREGISTRO::to_string() const
{
	struct tm fecha;
	localtime_s(&fecha, (const time_t*)this->fecha_extraccion);

	stringstream ss;
	ss << "Donacion: " << endl;
	ss << "Fecha extraccion: " << fecha.tm_mday << "/" << fecha.tm_mon + 1 << "/" << fecha.tm_year + 1900;
	
	cMEDULA* ptr1 = dynamic_cast <cMEDULA*> (this->fluido);
	cPLASMA* ptr2 = dynamic_cast <cPLASMA*> (this->fluido);
	cSANGRE* ptr3 = dynamic_cast <cSANGRE*> (this->fluido);

	if (ptr1 != nullptr)
		ss << ptr1->to_string();
	if (ptr2 != nullptr)
		ss << ptr2->to_string();
	if (ptr3 != nullptr)
		ss << ptr3->to_string();

	ss << this->centro->to_string();

	return ss.str();
}

void cREGISTRO::imprimir()
{
	cout << to_string() << endl;
}

