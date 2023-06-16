#pragma once
#ifndef _CTRANSPLANTE_H
#define _CTRANSPLANTE_H
#include <ctime>


//nota: no necesite añadir sstream, supongo que viene de fluido y paciente
class cTRANSPLANTE {
	time_t fecha;
	bool resultado;
	static int num_transplante;
public:
	cTRANSPLANTE(time_t fecha, bool resultado);
	~cTRANSPLANTE();
	void imprimir();
	string to_string() const;
};
#endif // !_CTRANSPLANTE_H

