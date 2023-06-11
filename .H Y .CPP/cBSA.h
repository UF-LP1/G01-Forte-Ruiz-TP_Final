#pragma once
#include <vector>
#include "cDONANTE.h"
#include "cRECEPTOR.h"
#include "cCENTRO.h"
#include "cSANGRE.h"
#include "cMEDULA.h"
#include "cPLASMA.h"
#include "funciones.h"
#include "VECTOR.h"

using namespace std;

class cBSA {
	VECTOR<cDONANTE> lista_donantes;
	VECTOR<cRECEPTOR> lista_receptores;
	vector<cCENTRO> lista_centros;

public:
	cBSA(VECTOR<cDONANTE> lista_donantes, VECTOR<cRECEPTOR> lista_receptores, vector<cCENTRO> lista_centros);
	~cBSA();
	void set_lista_donantes(VECTOR<cDONANTE> lista_donantes);
	void set_lista_receptores(VECTOR<cRECEPTOR> lista_receptores);
	void set_lista_centros(vector<cCENTRO> lista_centros);

	VECTOR<cDONANTE> get_lista_donantes();
	VECTOR<cRECEPTOR> get_lista_receptores();
	vector<cCENTRO> get_lista_centros();

	bool comprobar_requisitos(cDONANTE* donante);
	cPACIENTE* elegir_receptor(VECTOR<cRECEPTOR> posibles_receptores);
	void agregar_paciente(VECTOR<cPACIENTE*> lista_pacientes);

	void protocolo_transplante(cDONANTE* donante, cRECEPTOR* receptor);
	VECTOR<cRECEPTOR> buscar_posibles_receptores(cDONANTE* donante);
	void iniciar_analisis();

	//string to_string_BSA(); //PASO A STRING TODAS LAS LISTAS?
	//void imprimir_BSA();
};