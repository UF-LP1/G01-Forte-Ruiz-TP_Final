#pragma once
#include "cBSA.h"
#include <iostream>
#include <string>
#include <ctime>
#include "ePROVINCIA.h"

using namespace std;

class cMENU {
	cBSA* BSA;
public:
	cMENU(cBSA* bsa);
	~cMENU();

	void ejecutar();

	//funciones extras
	void buscar_centro(cCENTRO* centro);
	cCENTRO* verificar_centro(string nombre, string partido, ePROVINCIA provincia);

	//funciones principales
	cRECEPTOR* buscar_receptor(string dni);
	cDONANTE* buscar_donante(string dni);
	void imprimir_listado_donantes();
	void imprimir_listado_receptores();
	void informe_mensual();

	//funciones imprimir
	void imprimir();
	void imprimir_submenu();
	void imprimir_datos_receptor();
	void imprimir_datos_donante();
	void imprimir_provincias();
	int control_entradas(int sup, int inf);

	//funciones escribir
	cPACIENTE* escribir_donante();
	cPACIENTE* escribir_receptor();
	
	string escribir_nombre();
	time_t escribir_fecha();
	string escribir_telefono();
	eSEXO escribir_sexo();
	cCENTRO* escribir_centro();

	eTIPO escribir_tipos();
	cFLUIDO* escribir_fluido();
	cFLUIDO* escribir_sangre();
	cFLUIDO* escribir_plasma();
	cFLUIDO* escribir_medula();
	string escribir_dni();

	ePRIORIDAD escribir_prioridad();
	eESTADO escribir_estado();

	float escribir_peso();
	cHISTORIAL* escribir_historial();
	vector <cREGISTRO> escribir_registros();

};