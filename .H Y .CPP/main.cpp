#include <iostream>

#include "cMENU.h"

int main()
{
	/*
	si agregamos una lista de transplantes al bsa 
	en menu, podemos llamar a imprimir ese listado y filtrarlo con la fecha actual
	(imprimiria todos porque no vamos a tener un archivo de transplantes anteriores (o si?) )
	el objetivo es que informe si hubo match o no del paciente recien registrado
	*/
	time_t fecha1;
	const time_t fecha_act = (const time_t)time(NULL);
	struct tm fecha;
	localtime_s(&fecha, &fecha_act);
	fecha.tm_mon -= 6; //le resto 6 meses a la fecha actual para que cumpla con los requitos
	time_t f_a = mktime(&fecha);
	fecha1 = f_a;

	VECTOR<cRECEPTOR> lista1;
	vector<cCENTRO> lista3;
	cPLASMA plasma(450,O);
	cFLUIDO* fluid = &plasma;
	cCENTRO centro("favachoto", "paso", "coronel osales", Jujuy, "123");
	lista3.push_back(centro);
	cCENTRO* cent = &centro;
	cRECEPTOR pac1(25, "juan perez",fecha1, "23", FEMENINO, fluid, cent, "4457", time(NULL), uno, ESTABLE);
	lista1.push_back(pac1);
	VECTOR<cDONANTE> lista2;
	cHISTORIAL historial(false, 0, false);
	vector <cREGISTRO> registros;
	cDONANTE pac2(25, "juan perez", fecha1, "23", FEMENINO, fluid, cent, "4457", registros, 75.0, &historial);
	
	//lista2.push_back(pac2);
	cBSA banco(lista2,lista1,lista3);
	banco.agregar_paciente(&pac2);
	cMENU menu(&banco);
	menu.ejecutar();
	return 0;
}

