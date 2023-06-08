#include "cSANGRE.h"

cSANGRE::cSANGRE(unsigned int volumen, eTIPO tipo, bool Rh):cFLUIDO(volumen)
{
	this->tipo = tipo;
	this->Rh = Rh;
}

cSANGRE::~cSANGRE()
{
}


eTIPO cSANGRE::get_tipo()
{
	return this->tipo;
}

bool cSANGRE::get_Rh()
{
	return this->Rh;
}

bool cSANGRE::verificar_fecha_maxima(cREGISTRO* registro) //42 dias
{
	const time_t fecha_act = (const time_t)time(NULL);
	struct tm fecha;
	localtime_s(&fecha, &fecha_act);
	fecha.tm_mday -= 42;//le resto 42 dia a la fecha actual
	time_t f_a = mktime(&fecha);

	//no tiene que pasar mas de un dia desde la fecha de extracción

	if (difftime(registro->get_fecha_extraccion(), f_a) > 0)//la fecha de extr tiene que ser mas actual (mas grande) que la fechaActual-42dias (seria mas chica) 
		return true;
	else
		return false;
}

bool cSANGRE:: compatibilidad(cFLUIDO* donante) 
{
	//se tiene que hacer dynamic cast si o si, porque si cambio el parametro que recibe la funcion, ya no es virtual
	cSANGRE* ptr = dynamic_cast<cSANGRE*>(donante);// estos se hacen en la funcion de la sobrecarga de ==, repetimos codigo
	if (ptr == nullptr)
		return false;

	//con el plasma hay 1° 2° 3° opcion, si lo tomamos en cuenta se vuelve complicado

	if (this->tipo == AB && this->Rh)//AB+ recibe todos los tipos
		return true;
	if (this->tipo == B && this->Rh && ptr->get_tipo() == B || ptr->get_tipo() == O) //B+ recibe B+- y O+-
		return true;
	if (this->tipo == A && this->Rh && ptr->get_tipo() == A || ptr->get_tipo() == O) //A+ recibe A+- y O+-
		return true;
	if (this->tipo == O && this->Rh && ptr->get_tipo() == O)// O+ recibe O+-
		return true;
	if (this->tipo == ptr->get_tipo() && this->Rh == ptr->get_Rh())// O- recibe O-, pero vale para todos
		return true;
	if (this->tipo == A && !(this->Rh) && !(ptr->get_Rh()) && ptr->get_tipo() == A || ptr->get_tipo() == O) //A- recibe A- y O-
		return true;
	if (this->tipo == B && !(this->Rh) && !(ptr->get_Rh()) && ptr->get_tipo() == B || ptr->get_tipo() == O) //B- recibe B- y O-
		return true;
	if (this->tipo == AB && !(this->Rh) && !(ptr->get_Rh())) //AB- recibe AB- y O- B- A-
		return true;
	else
		return false;

}