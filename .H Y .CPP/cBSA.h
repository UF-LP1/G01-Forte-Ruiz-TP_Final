#pragma once
#ifndef _CBSA_H
#define _CBSA_H


#include "cCENTRO.h"

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
	cPACIENTE* elegir_receptor(VECTOR<cRECEPTOR*> *posibles_receptores);
	int agregar_paciente(cPACIENTE* paciente);

	void protocolo_transplante(cDONANTE* donante, cRECEPTOR* receptor);
	void buscar_posibles_receptores(cDONANTE* donante, VECTOR<cRECEPTOR*> *lista);
	cPACIENTE* iniciar_analisis(cDONANTE* donante);

	//string to_string_BSA(); //PASO A STRING TODAS LAS LISTAS?
	//void imprimir_BSA();
};
#endif // _CBSA_H

