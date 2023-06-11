#pragma once
#include <vector>
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
		this->push_back(*elemento);
		return;
	}
};
