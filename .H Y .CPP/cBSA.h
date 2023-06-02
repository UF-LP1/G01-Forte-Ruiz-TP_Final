#pragma once
#include <vector>
#include "cDONANTE.h"
#include "cRECEPTOR.h"
#include "cCENTRO.h"

using namespace std;

class cBSA {
	vector<cDONANTE> lista_donantes;
	vector<cRECEPTOR> lista_receptores;
	vector<cCENTRO> lista_centros;

public:
	cBSA(vector<cDONANTE> lista_donantes, vector<cRECEPTOR> lista_receptores, vector<cCENTRO> lista_centros);
	~cBSA();
	void set_lista_donantes(vector<cDONANTE> lista_donantes);
	void set_lista_receptores(vector<cRECEPTOR> lista_receptores);
	void set_lista_centros(vector<cCENTRO> lista_centros);

	vector<cDONANTE> get_lista_donantes();
	vector<cRECEPTOR> get_lista_receptores();
	vector<cCENTRO> get_lista_centros();


	
};