#include "cMENU.h"

cMenu::cMENU(cBSA bsa)
{
	this->BSA = bsa;
}

cMenu::~cMENU()
{
}

void cMenu::ejecutar()
{
}

void cMenu::buscar_centro(string nombre, string partido, string provincia)
{
	vector<cRECEPTOR> lista_espera;

	for (int i = 0; i < this->BSA.get_lista_receptores().size(); i++)
	{
		if (this->BSA.get_lista_receptores()[i].get_nombre() == nombre && this->BSA.get_lista_receptores()[i].get_partido() == partido && this->BSA.get_lista_receptores()[i].get_provincia() == provincia)
			lista_espera.push_back(this->BSA.get_lista_receptores()[i]);
	}

	for (i = 0; i < lista_espera.size(); i++)
	{
		lista_espera[i].imprimir();
	}
	return;
}

void cMenu::buscar_receptor()
{
}

void cMenu::imprimir_listado_donantes() //se puede hacer sobrecarga del << (tipo cout<<BSA.get_lista_donantes())
{
	for (int i = 0; i < this->BSA.get_lista_donantes().size(); i++)
	{
		this->BSA.get_lista_donantes()[i].imprimir();
	}
}

void cMenu::imprimir_listado_receptores() //se podria hacer sobrecarga del << (tipo cout<<BSA.get_lista_donantes())
{
	for (int i = 0; i < this->BSA.get_lista_receptores().size(); i++)
	{
		this->BSA.get_lista_receptores()[i].imprimir();
	}
}

void cMenu::informe_mensual()
{
}

void cMenu::imprimir()
{
	cout << "----------------------------" << endl 
		<< "Banco de Sangre Argentino" << endl 
		<<"----------------------------";
	cout << endl << "1) Registrar paciente."
		<< endl << "2) Mostrar lista de espera de un centro de salud."
		<< endl << "3) Buscar un paciente."
		<< endl << "4) Mostrar listado de pacientes donantes."
		<< endl << "5) Mostrar listado de pacientes receptores."
		<< endl << "6) Informe mensual de donanciones en cada provincia." << endl;
}

void cMenu::imprimir_submenu()
{
	cout << endl << "1) Informar prioridad"
		<< "2) Modificar datos" << endl;
}
