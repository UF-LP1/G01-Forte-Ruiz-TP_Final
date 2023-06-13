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
	this->num_transplante--;
}

void cTRANSPLANTE::imprimir()
{
	cout << to_string() << endl;
}

string cTRANSPLANTE:: to_string() const
{
	stringstream ss;
	ss << "Numero de transplante realizado:" << this->num_transplante <<endl;
	struct tm aux;
	localtime_s(&aux, (const time_t*)fecha);
	ss << "Fecha:" << aux.tm_mday << "/" << aux.tm_mon + 1 << "/" << aux.tm_year + 1900 << endl;


	ss << "Resultado: ";
	if (this->resultado)
		ss << "exitoso" << endl;
	else
		ss << "con complicaciones" << endl; //fallado, complicado, fracaso, deficiente

	return ss.str();
}