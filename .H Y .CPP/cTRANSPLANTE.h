#pragma once
#ifndef _CTRANSPLANTE_H
#define _CTRANSPLANTE_H
#include <ctime>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class cTRANSPLANTE {
	time_t fecha;
	bool resultado;
	static int num_transplante;
public:
	cTRANSPLANTE(time_t fecha, bool resultado);
	~cTRANSPLANTE();
	bool get_resultado();
	void imprimir();
	string to_string() const;
};
#endif // !_CTRANSPLANTE_H

