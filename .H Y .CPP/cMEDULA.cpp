#include "cMEDULA.h"

cMEDULA::cMEDULA(unsigned int volumen, eCOLOR color):cFLUIDO(volumen)
{
	this->color = color;
}

cMEDULA::~cMEDULA()
{
}

void cMEDULA::set_color(eCOLOR color)
{
	this->color = color;
}

eCOLOR cMEDULA::get_color()
{
	return this->color;
}

bool cMEDULA::verificar_fecha_maxima(time_t fecha_extraccion) //1 dia
{
	const time_t fecha_act = (const time_t)time(NULL);
	struct tm fecha;
	localtime_s(&fecha, &fecha_act);
	fecha.tm_mday -= 1;//le resto un dia a la fecha actual
	time_t f_a = mktime(&fecha);

	//no tiene que pasar mas de un dia desde la fecha de extracción

	if (difftime(fecha_extraccion, f_a) > 0)//la fecha de extr tiene que ser mas actual (mas grande) que la fechaActual-1dia (seria mas chica) 
		return true;
	else
		return false;
}


string cMEDULA::to_string() const
{
	stringstream ss;
	const char* colores[] = {"amarillo", "rojo"};
	ss << "Fluido: MEDULA" << endl;
	ss << "Volumen: " << this->volumen << endl
	   << "Color: " << colores[this->color]<<endl; //(:p)
	return ss.str();
}

void cMEDULA::imprimir()
{
	cout << to_string() << endl;
}

bool cMEDULA:: compatibilidad(cFLUIDO* donante)
{

	if (this->color == dynamic_cast<cMEDULA*>(donante)->color)
		return true;
	else
		return false;

}