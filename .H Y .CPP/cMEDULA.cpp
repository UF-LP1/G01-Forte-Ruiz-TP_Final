#include "cMEDULA.h"

cMEDULA::cMEDULA(unsigned int volumen):cFLUIDO(volumen)
{
}

cMEDULA::~cMEDULA()
{
}

bool cMEDULA::verificar_fecha_maxima(cREGISTRO* registro) //1 dia
{
	const time_t fecha_act = (const time_t)time(NULL);
	struct tm fecha;
	localtime_s(&fecha, &fecha_act);
	fecha.tm_mday -= 1;//le resto un dia a la fecha actual
	time_t f_a = mktime(&fecha);

	//no tiene que pasar mas de un dia desde la fecha de extracción

	if (difftime(registro->get_fecha_extraccion(), f_a) > 0)//la fecha de extr tiene que ser mas actual (mas grande) que la fechaActual-1dia (seria mas chica) 
		return true;
	else
		return false;
}

bool cMEDULA:: compatibilidad(cFLUIDO* donante)
{

}