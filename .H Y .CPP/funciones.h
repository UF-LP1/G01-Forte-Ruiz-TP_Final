#pragma once
#include <vector>
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

bool operator==(cDONANTE donante, cRECEPTOR receptor)
{
	cSANGRE* ptr1 = dynamic_cast<cSANGRE*>(donante.get_fluido());
	cSANGRE* ptr2 = dynamic_cast<cSANGRE*>(receptor.get_fluido());


	if (ptr1 != nullptr && ptr2 != nullptr && ptr2->compatibilidad(ptr1))
		return true;

		cMEDULA* ptr3 = dynamic_cast<cMEDULA*>(donante.get_fluido());
		cMEDULA* ptr4 = dynamic_cast<cMEDULA*>(receptor.get_fluido());

		if (ptr3 != nullptr && ptr4 != nullptr && ptr4->compatibilidad(ptr3)) // checkear condiciones
			return true;

		cPLASMA* ptr5 = dynamic_cast<cPLASMA*>(donante.get_fluido());
		cPLASMA* ptr6 = dynamic_cast<cPLASMA*>(receptor.get_fluido());

		if (ptr5 != nullptr && ptr6 != nullptr && ptr6->compatibilidad(ptr5))
			return true;

	return false;
}


std::vector<cDONANTE> operator-(std::vector<cDONANTE> *lista, cDONANTE elemento)
{
	for (int i = 0; i < lista->size(); i++) 
	{
		if (lista->at(i)==elemento)//hacer sobrecarga del ==, estas comparando dos objetos
			lista->erase(lista->begin() + i);//si tira error hay que hacer como hicimos en el TP3
	}
	return *lista;

}
std::vector<cRECEPTOR> operator-(std::vector<cRECEPTOR> *lista, cRECEPTOR elemento) //para que sea void tiene que recibir la direccion de lalista, no copiarla
{
	for (int i = 0; i < lista->size(); i++)
	{
		if (lista[i] == elemento)
			lista->erase(lista->begin() + i);//si tira error hay como hicimos en el TP3
	}
	return *lista;

}