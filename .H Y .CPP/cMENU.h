#pragma once
#ifndef _CMENU_H
#define _CMENU_H
/*#ifdef _WIN32
	#include<Windows.h>
#endif
*/
#include "cBSA.h"
#include "ePROVINCIA.h"
#include <ctype.h>

using namespace std;

class cMENU {
	cBSA* BSA;
public:
	cMENU(cBSA* bsa);
	~cMENU();

	void ejecutar(); //funcion principal

	//funciones extras

	cCENTRO* verificar_centro(string nombre, string partido, ePROVINCIA provincia);
	int control_entradas(int sup, int inf);
	//void limpiar_pantalla();

	//funciones principales
	cRECEPTOR* buscar_receptor(string dni);
	cDONANTE* buscar_donante(string dni);
	void imprimir_listado_donantes();
	void imprimir_listado_receptores();
	void informe_mensual(vector<int>* cont_x_prov);
	void buscar_centro(cCENTRO* centro);

	//funciones imprimir
	void imprimir();
	void imprimir_submenu();
	void imprimir_datos_receptor();
	void imprimir_datos_donante();
	void imprimir_provincias();


	//funciones escribir
	cPACIENTE* escribir_donante();
	cPACIENTE* escribir_receptor();

	int escribir_edad();
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
#endif // !_CMENU_H

