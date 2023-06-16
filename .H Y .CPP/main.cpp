#include <iostream>
#include "cBSA.h"
#include "cCENTRO.h"
#include "cDONANTE.h"
#include "cFLUIDO.h"
#include "cHISTORIAL.h"
#include "cMEDULA.h"
#include "cPACIENTE.h"
#include "cPLASMA.h"
#include "cRECEPTOR.h"
#include "cREGISTRO.h"
#include "cSANGRE.h"
#include "eESTADO.h"
#include "ePRIORIDAD.h"
#include "eSEXO.h"
#include "eTIPO.h"
#include "cMENU.h"

int main()
{
	/*
	si agregamos una lista de transplantes al bsa 
	en menu, podemos llamar a imprimir ese listado y filtrarlo con la fecha actual
	(imprimiria todos porque no vamos a tener un archivo de transplantes anteriores (o si?) )
	el objetivo es que informe si hubo match o no del paciente recien registrado
	*/
	VECTOR<cRECEPTOR> lista1;
	vector<cCENTRO> lista3;
	cPLASMA plasma(450,O);
	cFLUIDO* fluid = &plasma;
	cCENTRO centro("favaloro", "paso", "coonel osales", Jujuy, "123");
	lista3.push_back(centro);
	cCENTRO* cent = &centro;
	cRECEPTOR pac1(25, "juan perez",(time_t)2300000, "23", FEMENINO, fluid, cent, "4457", time(NULL), uno, ESTABLE);
	lista1.push_back(pac1);
	VECTOR<cDONANTE> lista2;
	cHISTORIAL historial(false, 0, false);
	vector <cREGISTRO> registros;
	cDONANTE pac2(25, "juan perez", (time_t)2300000, "23", FEMENINO, fluid, cent, "4457", registros, 75.0, &historial);
	lista2.push_back(pac2);
	cBSA banco(lista2,lista1,lista3);
	banco.buscar_posibles_receptores(&pac2);
	return 0;
}

