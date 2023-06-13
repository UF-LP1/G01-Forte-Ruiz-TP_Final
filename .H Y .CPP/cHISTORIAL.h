#pragma once
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

class cHISTORIAL {
	bool tiene_tattoo;
	time_t ult_tattoo;
	bool enfermedades;

public:
	cHISTORIAL(bool tiene_tattoo, time_t ult_tattoo, bool enfermedades);
	~cHISTORIAL();

	void set_tiene_tattoo(bool tiene_tattoo);
	void set_ult_tattoo(time_t ult_tattoo);
	void set_enfermedades(bool enfermedades);

	bool get_tiene_tattoo();
	time_t get_ult_tattoo();
	bool get_enfermedades() const;

	string to_string();

};