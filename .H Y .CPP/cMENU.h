#pragma once
#include "cBSA.h"
#include <iostream>
#include <string>

using namespace std;

class cMenu {
	cBSA BSA;
public:
	cMENU(cBSA bsa);
	~cMENU();
	void ejecutar();
	void buscar_centro(string nombre, string provincia, string partido);
	void buscar_receptor();
	void imprimir_listado_donantes();
	void imprimir_listado_receptores();
	void informe_mensual();
	void imprimir();
	void imprimir_submenu();
};