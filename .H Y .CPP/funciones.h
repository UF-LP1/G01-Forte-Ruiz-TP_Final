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

//SOBRECARGA DE <<
ostream& operator<<(ostream& out, const vector<cRECEPTOR>& lista_receptores)
{
	for (int i = 0; i < lista_receptores.size(); i++)
	{
		out << lista_receptores[i].to_string()<<endl;
		out << "----------------------" << endl;
	}
	return out;
}
ostream& operator<<(ostream& out, const vector<cDONANTE>& lista_donantes)
{
	for (int i = 0; i < lista_donantes.size(); i++)
	{
		out << lista_donantes[i].to_string()<<endl;
		out << "----------------------" << endl;
	}
	return out;
}
ostream& operator<<(ostream& out, const vector<cCENTRO>& lista_centros)
{
	for (int i = 0; i < lista_centros.size(); i++) 
	{
		out << lista_centros[i].to_string()<<endl; 
		out << "----------------------" << endl;
	}
	return out;
}
