#pragma once
#include <ctime>
#include <string>

using namespace std;

class cHISTORIAL {
	time_t ult_tattoo;
	bool enfermedades;

public:
	cHISTORIAL(time_t ult_tattoo, bool enfermedades);
	~cHISTORIAL();

	void set_ult_tattoo(time_t ult_tattoo);
	void set_enfermedades(bool enfermedades);

	time_t get_ult_tattoo();
	bool get_enfermedades();

	string to_string_HIST() const;


};