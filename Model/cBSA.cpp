#include "cBSA.h"

using namespace std;

cBSA::cBSA(VECTOR<cDONANTE> lista_donantes, VECTOR<cRECEPTOR> lista_receptores, vector<cCENTRO> lista_centros)
{
	this->lista_donantes = lista_donantes;
	this->lista_receptores = lista_receptores;
	this->lista_centros = lista_centros;
}
cBSA::~cBSA()
{ /*
	for (int i = 0; i < lista_donantes.size(); i++)
	{
		if (this->lista_donantes[i].get_centro() != nullptr)
			delete this->lista_donantes[i].get_centro();
		if (this->lista_donantes[i].get_fluido() != nullptr)
			delete this->lista_donantes[i].get_fluido();
		if(this->lista_donantes[i].get_historial()!=nullptr)
			delete this->lista_donantes[i].get_historial();
		for (int j = 0; this->lista_donantes[i].get_registros().size(); j++)
		{
			if(this->lista_donantes[i].get_registros()[j].get_centro()!=nullptr)
				delete this->lista_donantes[i].get_registros()[j].get_centro();
			if(this->lista_donantes[i].get_registros()[j].get_fluido()!=nullptr)
				delete this->lista_donantes[i].get_registros()[j].get_fluido();
		}
	}
	for (int i = 0; i < lista_receptores.size(); i++)
	{
		if(this->lista_receptores[i].get_centro()!=nullptr)
			delete this->lista_receptores[i].get_centro();
		if(this->lista_receptores[i].get_fluido() != nullptr)
			delete this->lista_receptores[i].get_fluido();
		if(this->lista_receptores[i].get_transplante() !=nullptr)
			delete this->lista_receptores[i].get_transplante();
	}
	*/
}

//setters
void cBSA::set_lista_donantes(VECTOR<cDONANTE> lista_donantes)
{
	this->lista_donantes = lista_donantes;
}
void cBSA::set_lista_receptores(VECTOR<cRECEPTOR> lista_receptores)
{
	this->lista_receptores = lista_receptores;
}
void cBSA::set_lista_centros(vector<cCENTRO> lista_centros)
{
	this->lista_centros = lista_centros;
}

//getters
VECTOR<cDONANTE> cBSA::get_lista_donantes()
{
	return this->lista_donantes;
}
VECTOR<cRECEPTOR> cBSA::get_lista_receptores()
{
	return this->lista_receptores;
}
vector<cCENTRO> cBSA::get_lista_centros()
{
	return this->lista_centros;
}


bool cBSA::comprobar_requisitos(cDONANTE* donante)
{

	if (donante->get_edad()<18 || donante->get_edad()>65)
		return false;
	if (donante->get_peso() <= 50)
		return false;
	if (donante->get_historial()->get_enfermedades())
		return false;

	const time_t f_actual = (const time_t)time(NULL);
	struct tm fecha;
	localtime_s(&fecha, &f_actual);
	fecha.tm_mon -= 2;
	time_t f_a = mktime(&fecha);

	if (donante->get_historial()->get_ult_tattoo() >= f_a)
		return false;

	if (donante->get_registros().empty())
		return true;

	if (donante->get_registros().back().get_fecha_extraccion() >= f_a)
		return false;

	return true;
}

cPACIENTE* cBSA::elegir_receptor(VECTOR<cRECEPTOR*> *posibles_receptores)
{
	if (posibles_receptores->empty())
		return nullptr;

	int max=-1;

	for (int i = 0; i < posibles_receptores->size(); i++)
	{
		if (i == 0 || posibles_receptores->at(i)->get_prioridad() > posibles_receptores->at(max)->get_prioridad())
			max = i;
		else if (posibles_receptores->at(i)->get_prioridad() == posibles_receptores->at(max)->get_prioridad())
		{
			if (posibles_receptores->at(i)->get_fecha_ingreso() < posibles_receptores->at(max)->get_fecha_ingreso())
				max = i;
		}

	}

	cPACIENTE* ptr = dynamic_cast<cPACIENTE*>(posibles_receptores->at(max));
	
	return ptr;

}

int cBSA::agregar_paciente(cPACIENTE* paciente)
{
	cRECEPTOR* receptor;
	cDONANTE* donante;
	int a = 0;
	int i = 0;
	receptor = dynamic_cast<cRECEPTOR*>(paciente);
	donante = dynamic_cast<cDONANTE*>(paciente);
	
	if (donante != nullptr)
	{
		while (a != 0 && i<this->lista_donantes.size())
		{
			if (paciente == &(this->lista_donantes[i])) 
				a = -1;
			//Ya estaba en la lista de donantes
			i++;
		}
	}
	i = 0;
	if (receptor != nullptr && a == 0)
	{
		while (a != -1 && i < this->lista_receptores.size())
		{
			if (receptor == &(this->lista_receptores[i])) 
				a = -1;
			//Ya estaba en la lista de receptores
			i++;
		}
	}
	if(receptor != nullptr && a == 0)
		this->lista_receptores + receptor;

	int cant = this->lista_donantes.size();

	if (donante != nullptr && a == 0)
	{
		bool b = this->comprobar_requisitos(donante); 
		if (b) 
		{
			donante->crear_registro();
			this->lista_donantes + donante;
		

		}


	}

	int cant_despues = this->lista_donantes.size();

	if (cant_despues == cant && donante != nullptr)
		a = 1; //Significa que el donante no paso los requisitos.
	return a;
}

void cBSA::protocolo_transplante(cDONANTE* donante, cRECEPTOR* receptor) 
{
	int i = donante->get_registros().size(); //posicion del ultimo registro
	bool b1;
	time_t fecha = donante->get_registros()[i-1].get_fecha_extraccion();
	b1 = donante->get_fluido()->verificar_fecha_maxima(fecha);//dynamic cast
	if (!b1)
	{
		this->lista_donantes - donante;
		return;
	}
	//se borra de la lista, sobrecarga del -
	
	cTRANSPLANTE* transplante=receptor->get_centro()->realizar_transplante();
	receptor->set_transplante(transplante);
	if (transplante->get_resultado())
	{
		receptor->set_estado(RECIBIO);
		this->lista_receptores - receptor; //sobrecarga del -
		
	}
	else
	{
		receptor->set_estado(INESTABLE);
		receptor->set_prioridad(cinco);
	}

	this->lista_donantes - donante;
	
	
}
void cBSA::buscar_posibles_receptores(cDONANTE* donante, VECTOR<cRECEPTOR*> *lista)
{
	for (int i = 0; i < this->lista_receptores.size(); i++)
	{
		if (this->lista_receptores[i] == *donante && this->lista_receptores[i].get_centro() == donante->get_centro())
			lista->push_back(& (this->lista_receptores[i]));
	}

	return;
}
cPACIENTE* cBSA::iniciar_analisis(cDONANTE* donante)
{
	VECTOR<cRECEPTOR*> sublista;
	cPACIENTE* pac = nullptr;

		buscar_posibles_receptores(donante, &sublista);
		if (!(sublista.empty()))
		{
			pac = elegir_receptor(&sublista);
			if (pac != nullptr)
			{
				cRECEPTOR* ptr = dynamic_cast<cRECEPTOR*>(pac);
				protocolo_transplante(donante, ptr);
			}
		}
		if (dynamic_cast<cRECEPTOR*>(pac)->get_transplante() == nullptr)
			pac = nullptr;//por mas que eran compatibles, no sobrevivio el protocolo transplante(n se realizo ningun transplante)

	return pac;
}
