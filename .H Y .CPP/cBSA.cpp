#include "cBSA.h"

using namespace std;

cBSA::cBSA(vector<cDONANTE> lista_donantes, vector<cRECEPTOR> lista_receptores, vector<cCENTRO> lista_centros)
{
	this->lista_donantes = lista_donantes;
	this->lista_receptores = lista_receptores;
	this->lista_centros = lista_centros;
}
cBSA::~cBSA()
{
}

//setters
void cBSA::set_lista_donantes(vector<cDONANTE> lista_donantes)
{
	this->lista_donantes = lista_donantes;
}

void cBSA::set_lista_receptores(vector<cRECEPTOR> lista_receptores)
{
	this->lista_receptores = lista_receptores;
}

void cBSA::set_lista_centros(vector<cCENTRO> lista_centros)
{
	this->lista_centros = lista_centros;
}

//getters
vector<cDONANTE> cBSA::get_lista_donantes()
{
	return this->lista_donantes;
}

vector<cRECEPTOR> cBSA::get_lista_receptores()
{
	return this->lista_receptores;
}

vector<cCENTRO> cBSA::get_lista_centros()
{
	return this->lista_centros;
}

bool cBSA::comprobar_requisitos(cDONANTE* donante)
{
	if (donante->get_edad() < 18 || donante->get_edad() > 65)
		return false;
	if (donante->get_peso() <= 50)
		return false;
	if (donante->get_historial().get_enfermedades() == true)
		return false;

	const time_t f_actual = (const time_t)time(NULL);
	struct tm fecha;
	localtime_s(&fecha, &f_actual);
	fecha.tm_mon -= 2;
	time_t f_a = mktime(&fecha);

	if (donante->get_historial().get_ult_tattoo() >= f_a)
		return false;

	if (donante->get_registros().back().get_fecha_extraccion() >= f_a)
		return false;

	return true;
}

cPACIENTE* cBSA::elegir_receptor(vector<cRECEPTOR> posibles_receptores)
{
	if (posibles_receptores.empty())
		return nullptr;

	int max=-1;

	for (int i = 0; i < posibles_receptores.size(); i++)
	{
		if (i == 0 || posibles_receptores[i].get_prioridad() > posibles_receptores[max].get_prioridad())
			max = i;
		else if (posibles_receptores[i].get_prioridad() == posibles_receptores[max].get_prioridad())
		{
			if (posibles_receptores[i].get_fecha_ingreso() < posibles_receptores[max].get_fecha_ingreso())
				max = i;
		}

	}

	cPACIENTE* ptr = dynamic_cast<cPACIENTE*>( posibles_receptores[max]);
	
	return ptr;

}

void cBSA::agregar_paciente(vector<cPACIENTE> lista_pacientes) //FALTA VERIFICAR SI NO ESTA EN OTRA LISTA O SI YA ESTABA
{
	cDONANTE* ptr1;
	cRECEPTOR* ptr2;

	for (int i = 0; i < lista_pacientes.size(); i++)
	{
		ptr1 = dynamic_cast<cDONANTE*>(lista_pacientes[i]);
		ptr2 = dynamic_cast<cRECEPTOR*>(lista_pacientes[i]);

		if (ptr1 != nullptr)
			this->lista_donantes.push_back(lista_pacientes[i]);
		if (ptr2 != nullptr)
			this->lista_receptores.push_back(lista_pacientes[i]);
	}

	return;
}

bool cBSA::operator==(cDONANTE* donante, cRECEPTOR* receptor)
{
	cSANGRE* ptr1 = dynamic_cast<cSANGRE*>(donante->get_fluido());
	cSANGRE* ptr2 = dynamic_cast<cSANGRE*>(receptor->get_fluido());


	if (ptr1 != nullptr && ptr2 != nullptr && ptr1->get_tipo() == ptr2->get_tipo() && ptr1->get_Rh() == ptr2->get_Rh())
		return true;

	cMEDULA* ptr3 = dynamic_cast<cMEDULA*>(donante->get_fluido()); 
	cMEDULA* ptr4 = dynamic_cast<cMEDULA*>(receptor->get_fluido());

	if (ptr3 != nullptr && ptr4 != nullptr) // checkear condiciones
		return true;

	cPLASMA* ptr5 = dynamic_cast<cPLASMA*>(donante->get_fluido());
	cPLASMA* ptr6 = dynamic_cast<cPLASMA*>(receptor->get_fluido());

	if (ptr5 != nullptr && ptr6 != nullptr && ptr5->get_tipo() == ptr6->get_tipo())
		return true;

	return false;
}
