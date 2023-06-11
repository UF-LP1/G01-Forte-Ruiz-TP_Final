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

void cDONANTE::agregar(cBSA* banco)
{
	bool a = banco->comprobar_requisitos(this);
	if (a)
		banco->get_lista_donantes() + this;
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

void cDONANTE::crear_registro(cFLUIDO* fluido)
{
	time_t f_actual = time(NULL);
	cREGISTRO registro(fluido, f_actual, this->centro);
	this->registros.push_back(registro);
}

string cDONANTE::to_string_DONANTE() const
{
	string c, f_nac;
	struct tm fecha_nac;
	localtime_s(&fecha_nac, (const time_t*)this->fecha_nacimiento);
	int mes, anio;
	mes = fecha_nac.tm_mon + 1;
	anio = fecha_nac.tm_year + 1900;
	f_nac.append(to_string(fecha_nac.tm_mday));
	f_nac.append("/"); f_nac.append(to_string(mes)); f_nac.append("/");
	f_nac.append(to_string(anio)); 
	/////
	c.append(f_nac); 
	c.append(", "); c.append(to_string(this->peso));
	c.append(" kg.\n");
	c.append("REGISTROS:\n");
	for (int i = 0; i < this->registros.size(); i++) //Voy a guardar todos los registros
	{
		this->registros[i].to_string_REGIS();
		c.append("\n"); //Para que imprima un registro abajo de otro.
	}

	c.append("HISTORIAL:\n");
	c.append(this->historial->to_string_HIST());

	c.append("\n");
	return c;
}
