#pragma once
#include <exception>

using namespace std;

class ExcepcionFecha : public exception
{
public:
	const char* what() const throw();
};

class ExcepcionEspacio : public exception
{
public:
	const char* what() const throw();
};