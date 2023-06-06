#pragma once
#include "cBSA.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class cMENU {
	cBSA* BSA;
public:
	cMENU(cBSA* bsa);
	~cMENU();
	void ejecutar();
	void buscar_centro(string nombre, string provincia, ePROVINCIA partido);
	cRECEPTOR* buscar_receptor(string dni);
	void imprimir_listado_donantes();
	void imprimir_listado_receptores();
	void informe_mensual();
	void imprimir();
	void imprimir_submenu();
	void imprimir_datos_receptor();


};