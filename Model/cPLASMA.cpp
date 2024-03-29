#include "cPLASMA.h"


cPLASMA::cPLASMA(unsigned int volumen, eTIPO tipo):cFLUIDO(volumen)
{
	this->tipo = tipo;
}

cPLASMA::~cPLASMA()
{
}

eTIPO cPLASMA::get_tipo()
{
	return this->tipo;
}

string cPLASMA::to_string() const
{
	string type;
	const char* tipo[] = { "A","AB","B","O" };
	type = tipo[this->tipo];

	stringstream ss;
	ss << "Fluido: PLASMA" << endl;
	ss << "Volumen: " << this->volumen << " ml" << endl
		<< "Tipo: " << type << endl; 
	
	return ss.str();
}

void cPLASMA::imprimir()
{
	cout << to_string() << endl;
}

bool cPLASMA:: verificar_fecha_maxima(time_t fecha_extraccion) // 1 a�o
{
	const time_t fecha_act = (const time_t)time(NULL);
	struct tm fecha;
	localtime_s(&fecha, &fecha_act);
	fecha.tm_year -= 1;//le resto un a�o a la fecha actual
	time_t f_a = mktime(&fecha);

	//no tiene que pasar mas de un a�o desde la fecha de extracci�n

	if (difftime(fecha_extraccion, f_a) > 0)//la fecha de extr tiene que ser mas actual (mas grande) que la fechaActual-1a�o (seria mas chica) 
		return true;
	else
		return false;
}

bool cPLASMA:: compatibilidad(cFLUIDO* donante) //evalua si el fluido que "recibe" es compatible con el propio
{	
	cPLASMA* ptr = dynamic_cast<cPLASMA*>(donante);
	if (ptr == nullptr)
		return false;

	if (this->tipo == A && ptr->get_tipo() == A || ptr->get_tipo() == AB)
		return true;
	if (this->tipo == AB && ptr->get_tipo() == AB)
		return true;
	if (this->tipo == B && ptr->get_tipo() == B || ptr->get_tipo() == AB)
		return true;
	if (this->tipo == O && ptr->get_tipo() == A || ptr->get_tipo() == AB || ptr->get_tipo() == B || ptr->get_tipo() == O)
		return true;
	else
		return false;
}
