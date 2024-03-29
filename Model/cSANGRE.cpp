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

bool cSANGRE::verificar_fecha_maxima(time_t fecha_extraccion) //42 dias
{
	const time_t fecha_act = (const time_t)time(NULL);
	struct tm fecha;
	localtime_s(&fecha, &fecha_act);
	fecha.tm_mday -= 42;//le resto 42 dia a la fecha actual
	time_t f_a = mktime(&fecha);

	//no tiene que pasar mas de 42 dias desde la fecha de extracción

	if (difftime(fecha_extraccion, f_a) > 0)//la fecha de extr tiene que ser mas actual (mas grande) que la fechaActual-42dias (seria mas chica) 
		return true;
	else
		return false;
}

bool cSANGRE:: compatibilidad(cFLUIDO* donante) 
{
	
	cSANGRE* ptr = dynamic_cast<cSANGRE*>(donante);
	if (ptr == nullptr)
		return false;

	
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

string cSANGRE::to_string() const
{
	string type, signo;
	const char* tipo[] = { "A","AB","B","O" };
	type = tipo[this->tipo];

	if (this->Rh)
		signo = "+";
	else
		signo = "-";

	stringstream ss;
	ss << "Fluido: SANGRE" << endl;
	ss << "Volumen: " << this->volumen << " ml" << endl
		<< "Tipo: " << type << signo << endl;

	return ss.str();
}

void cSANGRE::imprimir()
{
	cout << to_string() << endl;
}
