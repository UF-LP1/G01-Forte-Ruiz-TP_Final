#pragma once
#ifndef _FUNCIONES_H
#define _FUNCIONES_H
#include <vector>
#include <iostream>

#include "cDONANTE.h"
#include "cRECEPTOR.h"



bool operator==(cRECEPTOR& receptor, cDONANTE& donante) {
	bool a = false;
	int i = 0;

	cSANGRE* ptr1 = nullptr;
	cSANGRE* ptr2 = nullptr;

	cMEDULA* ptr3 = nullptr;
	cMEDULA* ptr4 = nullptr;

	cPLASMA* ptr5 = nullptr;
	cPLASMA* ptr6 = nullptr;

	while (i < donante.get_registros().size())
	{
		cSANGRE* ptr1 = dynamic_cast<cSANGRE*>(donante.get_registros()[i].get_fluido());
		cSANGRE* ptr2 = dynamic_cast<cSANGRE*>(receptor.get_fluido());

		if (ptr1 != nullptr && ptr2 != nullptr && ptr2->compatibilidad(ptr1))
			return true;//a = true;

		cMEDULA* ptr3 = dynamic_cast<cMEDULA*>(donante.get_registros()[i].get_fluido());
		cMEDULA* ptr4 = dynamic_cast<cMEDULA*>(receptor.get_fluido());

		if (ptr3 != nullptr && ptr4 != nullptr && ptr4->compatibilidad(ptr3))
			return true;// a = true;

		cPLASMA* ptr5 = dynamic_cast<cPLASMA*>(donante.get_registros()[i].get_fluido());
		cPLASMA* ptr6 = dynamic_cast<cPLASMA*>(receptor.get_fluido());

		if (ptr5 != nullptr && ptr6 != nullptr && ptr6->compatibilidad(ptr5))
			return true;// a = true;
		i++;
	}
	return false; //return a;
}
//SOBRECARGA DE <<
ostream& operator<<(ostream& out, const vector<cRECEPTOR>& lista_receptores)
{
	for (int i = 0; i < lista_receptores.size(); i++)
	{
		out << lista_receptores[i].to_string() << endl;
		out << "----------------------" << endl;
	}
	return out;
}
ostream& operator<<(ostream& out, const vector<cDONANTE>& lista_donantes)
{
	for (int i = 0; i < lista_donantes.size(); i++)
	{
		out << lista_donantes[i].to_string() << endl;
		out << "----------------------" << endl;
	}
	return out;
}
ostream& operator<<(ostream& out, const vector<cCENTRO>& lista_centros)
{
	for (int i = 0; i < lista_centros.size(); i++)
	{
		out << lista_centros[i].to_string() << endl;
		out << "----------------------" << endl;
	}
	return out;
}

#endif // !_FUNCIONES_H

