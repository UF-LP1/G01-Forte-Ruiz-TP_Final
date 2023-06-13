#include "cTRANSPLANTE.h"

cTRANSPLANTE::cTRANSPLANTE(time_t fecha, cRECEPTOR* paciente, cCENTRO* centro, cFLUIDO* fluido, bool resultado)
{
	this->fecha = fecha;
	this->paciente = paciente;
	this->centro = centro;
	this->fluido = fluido;
	this->resultado = resultado;
	return;
}

cTRANSPLANTE::~cTRANSPLANTE()
{
}

void cTRANSPLANTE::imprimir()
{
	cout << to_string() << endl;
}

string cTRANSPLANTE:: to_string()
{
	stringstream ss;
	ss << "Transplante realizado:" << endl;
	struct tm aux;
	localtime_s(&aux, (const time_t*)fecha);
	ss << "Fecha:" << aux.tm_mday << "/" << aux.tm_mon + 1 << "/" << aux.tm_year + 1900 << endl
		<< this->paciente->to_string()
		<< this->centro->to_string();

	cMEDULA* ptr1 = dynamic_cast <cMEDULA*> (this->fluido);
	cPLASMA* ptr2 = dynamic_cast <cPLASMA*> (this->fluido);
	cSANGRE* ptr3 = dynamic_cast <cSANGRE*> (this->fluido);

	if (ptr1 != nullptr)
		ss << ptr1->to_string();
	if (ptr2 != nullptr)
		ss << ptr2->to_string();
	if (ptr3 != nullptr)
		ss << ptr3->to_string();

	ss << "Resultado: ";
	if (this->resultado)
		ss << "exitoso" << endl;
	else
		ss << "con complicaciones" << endl; //fallado, complicado, fracaso, deficiente

	return ss.str();
}