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

	cPACIENTE* ptr = dynamic_cast<cPACIENTE*>(&posibles_receptores[max]);
	
	return ptr;

}

void cBSA::agregar_paciente(vector<cPACIENTE*> lista_pacientes) //FALTA VERIFICAR SI NO ESTA EN OTRA LISTA O SI YA ESTABA
{
	cDONANTE* ptr1;
	cRECEPTOR* ptr2;

	for (int i = 0; i < lista_pacientes.size(); i++)
	{
		ptr1 = dynamic_cast<cDONANTE*>(lista_pacientes[i]);
		ptr2 = dynamic_cast<cRECEPTOR*>(lista_pacientes[i]);

		if (ptr1 != nullptr)
			this->lista_donantes.push_back(*ptr1);
		if (ptr2 != nullptr)
			this->lista_receptores.push_back(*ptr2);
	}

	return;
}


void cBSA::protocolo_transplante(cDONANTE* donante, cRECEPTOR* receptor) //falta sobrecarga del -
{
	int i = donante->get_registros().size(); //posicion del ultimo registro
	bool b1,b2;
	b1 = donante->get_fluido()->verificar_fecha_maxima(&donante->get_registros()[i]);//dynamic cast
	if (!b1)
		this->lista_donantes= this->lista_donantes-*donante;
	//se borra de la lista, sobrecarga del -
	
	if (!(b1 && donante->get_centro().get_provincia() == receptor->get_centro().get_provincia() && donante->get_centro().get_partido() == receptor->get_centro().get_partido()))//sobrecarga en centro del ==
		return;//si alguna condicion es falsa, se hace verdadera y entra al if
	
	b2 = receptor->get_centro().realizar_transplante(*donante, *receptor);
	if (b2)
	{
		receptor->set_estado(RECIBIO);
		//this->lista_receptores= this->lista_receptores - receptor; //sobrecarga del -
	}
	else
	{
		receptor->set_estado(INESTABLE);
		receptor->set_prioridad(cinco);
	}

	this->lista_donantes = this->lista_donantes - *donante;
	//si se realizo el trasnplante hay borrar el donante de la lista
	//o cambiar la disponibilidad en el registro, no es mucho borrarlo?
}
vector<cRECEPTOR> cBSA::buscar_posibles_receptores(cDONANTE* donante)
{
	vector<cRECEPTOR> sublista;

	for (int i = 0; i < this->lista_receptores.size(); i++)
	{
		if (&lista_receptores[i] == donante) // creo que me toma la sobrecarga
			sublista.push_back(this->lista_receptores[i]);
	}
	return sublista;
}
void cBSA::iniciar_analisis()// funcion madre que abarca varios metodos
{
	vector<cRECEPTOR> sublista;
	cPACIENTE* pac;

	for (int i = 0; i < this->lista_donantes.size(); i++)
	{
		sublista = buscar_posibles_receptores(&this->lista_donantes[i]);
		pac = elegir_receptor(sublista);
		if (pac != nullptr)
			protocolo_transplante(&(this->lista_donantes[i]), dynamic_cast<cRECEPTOR*>(pac));

	}
	return;
}