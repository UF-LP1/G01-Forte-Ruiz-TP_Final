#include "cHISTORIAL.h"

using namespace std;

cHISTORIAL::cHISTORIAL(bool tiene_tattoo, time_t ult_tattoo, bool enfermedades)
{
	this->tiene_tattoo = tiene_tattoo;
	this->ult_tattoo = ult_tattoo;
	this->enfermedades = enfermedades;
}

cHISTORIAL::~cHISTORIAL()
{
}

//setters

void cHISTORIAL::set_tiene_tattoo(bool tiene_tattoo)
{
	this->tiene_tattoo = tiene_tattoo;
}
void cHISTORIAL::set_ult_tattoo(time_t ult_tattoo)
{
	this->ult_tattoo = ult_tattoo;

}
void cHISTORIAL::set_enfermedades(bool enfermedades)
{
	this->enfermedades = enfermedades;
}

//getters

bool cHISTORIAL::get_tiene_tattoo()
{
	return this->tiene_tattoo;
}
time_t cHISTORIAL::get_ult_tattoo()
{
	return this->ult_tattoo;
}
bool cHISTORIAL::get_enfermedades() const
{
	return this->enfermedades;
}

string cHISTORIAL::to_string() const
{
	struct tm fecha;
	localtime_s(&fecha, (const time_t*)this->ult_tattoo);

	stringstream ss;
	ss << "Registro: " << endl;
	ss<<"Tiene enfermedades sanguineas: ";

	if (this->get_enfermedades())
		ss << "SI." << endl;
	else
		ss << "NO." << endl;

	if (this->tiene_tattoo)
	{
		ss << "FECHA DE ULTIMO TATUAJE: "
			<< fecha.tm_mday << "/" << fecha.tm_mon + 1 << "/" << fecha.tm_year + 1900 << endl;
	}

	return ss.str();
}

void cHISTORIAL::imprimir()
{
	cout << to_string() << endl;
}
