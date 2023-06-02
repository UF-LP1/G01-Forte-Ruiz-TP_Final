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
