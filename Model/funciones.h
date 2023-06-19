#pragma once
#ifndef _FUNCIONES_H
#define _FUNCIONES_H
#include <vector>
#include <iostream>

#include "cDONANTE.h"
#include "cRECEPTOR.h"



bool operator==(cRECEPTOR& receptor, cDONANTE& donante);
ostream& operator<<(ostream& out, const vector<cRECEPTOR>& lista_receptores);
ostream& operator<<(ostream& out, const vector<cDONANTE>& lista_donantes);
ostream& operator<<(ostream& out, const vector<cCENTRO>& lista_centros);
#endif // !_FUNCIONES_H

