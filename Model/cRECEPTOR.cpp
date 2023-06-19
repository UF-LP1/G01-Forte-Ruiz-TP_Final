#include "cRECEPTOR.h"

using namespace std;

cRECEPTOR::cRECEPTOR(int edad, string nombre, time_t fecha_nacimiento, string telefono, eSEXO sexo, cFLUIDO* fluido, cCENTRO* centro, string dni, time_t fecha_ingreso, ePRIORIDAD prioridad, eESTADO estado):cPACIENTE(edad, nombre, fecha_nacimiento, telefono, sexo, fluido, centro, dni)
{
	this->fecha_ingreso = fecha_ingreso;
	this->prioridad = prioridad;
	this->estado = estado;
	this->transplante = nullptr;
}

cRECEPTOR::~cRECEPTOR()
{
}

bool cRECEPTOR::operator==(cRECEPTOR* receptor)
{
	bool b = false;
	cSANGRE* ptr1 = dynamic_cast<cSANGRE*>(this->fluido);
	cSANGRE* ptr2 = dynamic_cast<cSANGRE*>(receptor->get_fluido());
	cPLASMA* ptr3 = dynamic_cast<cPLASMA*>(this->fluido);
	cPLASMA* ptr4 = dynamic_cast<cPLASMA*>(receptor->get_fluido());
	cMEDULA* ptr5 = dynamic_cast<cMEDULA*>(this->fluido);
	cMEDULA* ptr6 = dynamic_cast<cMEDULA*>(receptor->get_fluido());

	if (this->dni == receptor->get_dni() && (ptr1 != nullptr && ptr2 != nullptr))
		b = true;
	else if (this->dni == receptor->get_dni() && (ptr3 != nullptr && ptr4 != nullptr))
		b = true;
	else if (this->dni == receptor->get_dni() && (ptr5 != nullptr && ptr6 != nullptr))
		b = true;

	return b;
}

void cRECEPTOR::set_prioridad(ePRIORIDAD prioridad)
{
	this->prioridad = prioridad;
}

void cRECEPTOR::set_estado(eESTADO estado)
{
	this->estado = estado;
}

void cRECEPTOR::set_fecha(time_t fecha)
{
	this->fecha_ingreso = fecha;
}

void cRECEPTOR::set_transplante(cTRANSPLANTE* transplante)
{
	this->transplante = transplante;
}


time_t cRECEPTOR::get_fecha_ingreso()
{
	return this->fecha_ingreso;
}

ePRIORIDAD cRECEPTOR::get_prioridad()
{
	return this->prioridad;
}

eESTADO cRECEPTOR::get_estado()
{
	return this->estado;
}

cTRANSPLANTE* cRECEPTOR::get_transplante()
{
	return this->transplante;
}

string cRECEPTOR::to_string() const
{
	struct tm aux;
	localtime_s(&aux, &this->fecha_nacimiento);
	stringstream ss;

	ss << "-------------------------------" << endl;

	ss << "Paciente:" << endl; //donante/recep

	ss << "Nombre: " << this->nombre << endl << "DNI: " << this->dni << endl
		<< "Fecha de nacimiento: " << aux.tm_mday << "/" << aux.tm_mon + 1 << "/" << aux.tm_year + 1900 << endl
		<< "Telefono: " << this->telefono << endl << "Sexo: ";
	if (this->sexo == FEMENINO)
		ss << "Femenino" << endl;
	else
		ss << "Masculino" << endl;
	ss << "DEBE RECIBIR: " << endl;
	cMEDULA* ptr1 = dynamic_cast <cMEDULA*> (this->fluido);
	cPLASMA* ptr2 = dynamic_cast <cPLASMA*> (this->fluido);
	cSANGRE* ptr3 = dynamic_cast <cSANGRE*> (this->fluido);

	if (ptr1 != nullptr)
		ss << ptr1->to_string();
	if (ptr2 != nullptr)
		ss << ptr2->to_string();
	if (ptr3 != nullptr)
		ss << ptr3->to_string();



	//hasta aca igual que el padre
	struct tm fecha;
	localtime_s(&fecha, &this->fecha_ingreso);
	string estados[3]{ "ESTABLE", "INESTABLE", "RECIBIO" };
	string prioridades[5]{ "uno", "dos", "tres", "cuatro", "cinco" };
	ss << "Fecha de ingreso:" << fecha.tm_mday << "/" << fecha.tm_mon + 1 << "/" << fecha.tm_year + 1900 << endl
		<< "Estado: " << estados[this->estado] << endl
		<< "Prioridad: " << prioridades[this->prioridad] << endl;
	ss << this->centro->to_string();
	if (transplante != nullptr)
		ss << transplante->to_string() << endl;
	ss << "-------------------------------" << endl;

	return ss.str();
}

void cRECEPTOR::imprimir()
{
	cout << to_string() << endl;
}