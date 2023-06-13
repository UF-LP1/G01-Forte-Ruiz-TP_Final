#include "cDONANTE.h"

using namespace std;

cDONANTE::cDONANTE(string nombre, time_t fecha_nacimiento, string telefono, eSEXO sexo, cFLUIDO* fluido, cCENTRO* centro, string dni, vector<cREGISTRO> registros, float peso, cHISTORIAL* historial) : cPACIENTE( nombre, fecha_nacimiento, telefono, sexo, fluido, centro, dni)
{
	this->registros = registros;
	this->peso = peso;
	this->historial = historial;
}

cDONANTE::~cDONANTE()
{
}

void cDONANTE:: imprimir() {

}



//setters

void cDONANTE::set_registros(vector<cREGISTRO> registros)
{
	this->registros = registros;
}

void cDONANTE::set_peso(float peso)
{
	this->peso = peso;
}

void cDONANTE::set_historial(cHISTORIAL* historial)
{
	this->historial = historial;
}

//getters

vector<cREGISTRO> cDONANTE::get_registros()
{
	return this->registros;
}

float cDONANTE::get_peso()
{
	return this->peso;
}

cHISTORIAL* cDONANTE::get_historial()
{
	return this->historial;
}

void cDONANTE::crear_registro()
{
	time_t f_actual = time(NULL);
	cREGISTRO registro(this->fluido, f_actual, this->centro);
	this->registros.push_back(registro);
}


string cDONANTE::to_string() const
{
	const time_t fecha = (const time_t)this->fecha_nacimiento;
	struct tm aux;
	localtime_s(&aux, &fecha);
	stringstream ss;
	ss << "Nombre: " << this->nombre << endl << "DNI: " << this->dni << endl
		<< "Fecha de nacimiento: " << aux.tm_mday << "/" << aux.tm_mon + 1 << "/" << aux.tm_year + 1900 << endl
		<< "Telefono: " << this->telefono << endl << "Sexo: ";
	if (this->sexo == FEMENINO)
		ss << "Femenino" << endl;
	else
		ss << "Masculino" << endl;

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

	//hasta aca es igual que paciente

	ss << "Peso: " << this->peso << endl;
	ss << this->historial->to_string();
	for (int i = 0; i < this->registros.size(); i++)
	{
		ss << this->registros[i].to_string();
	}
	return ss.str();
}
void cDONANTE::imprimir()
{
	cout << to_string() << endl;
}