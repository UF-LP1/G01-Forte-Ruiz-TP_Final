#pragma once
#ifndef _FUNCIONES_H
#define _FUNCIONES_H
#include <vector>
#include <iostream>

#include "cCENTRO.h"
#include "cDONANTE.h"
#include "cRECEPTOR.h"


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

