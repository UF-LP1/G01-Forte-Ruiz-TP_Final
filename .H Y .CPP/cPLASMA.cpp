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
	ss << "Volumen: " << this->volumen << endl
		<< "Tipo: " << type << endl; 
	
	return ss.str();
}

bool cPLASMA:: verificar_fecha_maxima(cREGISTRO* registro) // 1 año
{
	const time_t fecha_act = (const time_t)time(NULL);
	struct tm fecha;
	localtime_s(&fecha, &fecha_act);
	fecha.tm_year -= 1;//le resto un año a la fecha actual
	time_t f_a = mktime(&fecha);

	//no tiene que pasar mas de un año desde la fecha de extracción

	if (difftime(registro->get_fecha_extraccion(), f_a) > 0)//la fecha de extr tiene que ser mas actual (mas grande) que la fechaActual-1año (seria mas chica) 
		return true;
	else
		return false;
}

bool cPLASMA:: compatibilidad(cFLUIDO* donante) //evalua si el fluido que "recibe" es compatible con el propio
{	//se tiene que hacer dynamic cast si o si, porque si cambio el parametro que recibe la funcion, ya no es virtual
	cPLASMA* ptr = dynamic_cast<cPLASMA*>(donante);// estos se hacen en la funcion de la sobrecarga de ==, repetimos codigo
	if (ptr == nullptr)
		return false;

	//con el plasma hay 1° 2° 3° opcion, si lo tomamos en cuenta se vuelve complicado
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
