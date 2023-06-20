#include "cTRANSPLANTE.h"

int cTRANSPLANTE::num_transplante = 0;

cTRANSPLANTE::cTRANSPLANTE(time_t fecha, bool resultado)
{
	this->fecha = fecha;
	this->resultado = resultado;
	this->num_transplante++;
	return;
}


cTRANSPLANTE::~cTRANSPLANTE()
{
	
}

void cTRANSPLANTE::set_resultado(bool resultado)
{
	this->resultado = resultado;
}

bool cTRANSPLANTE::get_resultado()
{
	return this->resultado;
}

void cTRANSPLANTE::imprimir()
{
	cout << to_string() << endl;
}

string cTRANSPLANTE:: to_string() const
{
	stringstream ss;
	ss << "Transplante realizado:" << endl;
	ss << "t/Numero de transplante realizado:" << this->num_transplante <<endl;
	struct tm aux;
	localtime_s(&aux, &this->fecha);
	ss << "    Fecha:" << aux.tm_mday << "/" << aux.tm_mon + 1 << "/" << aux.tm_year + 1900 << endl;


	ss << "    Resultado: ";
	if (this->resultado)
		ss << "EXITOSO." << endl;
	else
		ss << "CON COMPLICACIONES." << endl; 

	return ss.str();
}