#pragma once
#include <vector>
using namespace std;

template <class tipo>
class VECTOR : public vector<tipo> {
public:
	void operator-(tipo elemento)
	{
		for (int i = 0; i < lista->size(); i++)
		{
			if (lista[i] == elemento)
				lista->erase(lista->begin() + i);//si tira error hay que hacer como hicimos en el TP3
		}
		return ;

	
	}
};