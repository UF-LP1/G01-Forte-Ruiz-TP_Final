#pragma once
#include <string>

using namespace std;

class cCENTRO {
	string nombre;
	string direccion;
	string partido;
	string provincia;
	string telefono;
public:
	cCENTRO(string nombre, string direccion, string partido, string provincia, string telefono);
	~cCENTRO();

	//Que pasa si el paciente se debe mudar? Deberia poder modificarse

	string get_nombre();
	string get_direccion();
	string get_partido();
	string get_provincia();
	string get_telefono();
};