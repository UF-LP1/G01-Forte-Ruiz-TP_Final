#pragma once
#ifndef _VECTOR_H
#define _VECTOR_H
#include <vector>
#include "Excepciones.h"
using namespace std;

template <class tipo>
class VECTOR : public vector<tipo> {
public:
	void operator-(tipo* elemento)
	{
		for (int i = 0; i < this->size(); i++)
		{
			if (this->at(i) == elemento)
				this->erase(this->begin() + i); //elimina el de esa posicion unicamente

		}
		return;
	}
	void operator+(tipo* elemento)
	{
		try 
		{
			if (this->max_size() == this->size())
			{
				ExcepcionEspacio e;
				throw e; 
			}
			else
				this->push_back(*elemento);
			return;
		}
		catch(ExcepcionEspacio& e)
		{
			cout << e.what() << endl;

		}
		
	}
};
#endif // !VECTOR_H

