#include "cARCHIVO.h"



cARCHIVO::cARCHIVO(ifstream* fpin, ofstream* fpout)
{
	this->fpin = fpin;
	this->fpout = fpout;
}

cARCHIVO::~cARCHIVO()
{
}

void cARCHIVO::set_fpin(ifstream* fpin)
{
	this->fpin = fpin;
}

void cARCHIVO::set_fpout(ofstream* fpout)
{
	this->fpout = fpout;
}

ifstream* cARCHIVO::get_fpin()
{
	return this->fpin;
}

ofstream* cARCHIVO::get_fpout()
{
	return this->fpout;
}

void cARCHIVO::leer_HISTORIALES(vector<cHISTORIAL>& historiales) //TESTEAR SI DEVUELVE EL VECTOR CARGADO. A cada metodo leer le paso un vector en el que se cargaran las cosas
{
	string dummy;
	int id, i, dia, mes, anio;
	bool tiene_tattoo, enfermedades;
	struct tm fecha_ult_tattoo;
	time_t fecha;
	char coma, slash;

	i = 0;

	fpin->open("HISTORIALES_DONANTES.csv", ios::in); 
	if (!(fpin->is_open()))
		throw "ERROR: El archivo de HISTORIALES no abrio"; //checkear msj que devuelve xq no me acuerdo si era ese el problema. HAY QUE HACERLE CATCH(string).
	*(fpin) >> dummy >> coma >> dummy >> coma >> dummy >> coma >> dummy;

	while (!(fpin->eof()))
	{
		*(fpin) >> id >> coma >> tiene_tattoo >> coma >> dia >> slash >> mes >> slash >> anio >> coma >> enfermedades;
		fecha_ult_tattoo.tm_mon = mes - 1;
		fecha_ult_tattoo.tm_year = anio - 1900;

		fecha = mktime(&fecha_ult_tattoo);

		historiales[id+i].set_tiene_tattoo(tiene_tattoo);
		historiales[id+i].set_ult_tattoo(fecha);
		historiales[id+i].set_enfermedades(enfermedades);

		i++;
	}

	fpin->seekg(fpin->beg); //lo posiciono al ppio para la siguiente vez que habra el archivo (no se si es necesario xq se ejecuta una sola vez mepa) 
	fpin->close();
}

void cARCHIVO::leer_REGISTROS()
{
}

void cARCHIVO::leer_SANGRE()
{
}

void cARCHIVO::leer_MEDULA()
{
}

void cARCHIVO::leer_PLASMA()
{
}

void cARCHIVO::leer_DONANTES()
{
}

void cARCHIVO::leer_RECEPTORES()
{
}

void cARCHIVO::leer_CENTROS()
{
}

void cARCHIVO::escribir_HISTORIALES(cHISTORIAL historial, int pos) // pos es el identificador que tendria en el archivo (que se asocia al donante). Le paso el objeto a cargar
{

	char coma, slash;
	struct tm f;
	int dia, mes, anio;
	
	coma = ',';
	slash = '/';

	localtime_s(&f, (const time_t*)historial.get_ult_tattoo()); //Se me hace raro castear a puntero

	fpout->open("HISTORIALES_DONANTES.csv", ios::app); //Hay que ver si no sobreescribe el archivo xq sino perdemos todo!! 

	//Aca hay que hacer checkeo de is_open?

	dia = f.tm_mday;
	mes = f.tm_mon + 1;
	anio = f.tm_year + 1900;

	*(fpout) << pos << coma << historial.get_tiene_tattoo() << coma << dia << slash << mes << slash << anio << coma << historial.get_enfermedades();
	
	fpout->close();
}

void cARCHIVO::escribir_REGISTROS()
{
}

void cARCHIVO::escribir_SANGRE()
{
}

void cARCHIVO::escribir_MEDULA()
{
}

void cARCHIVO::escribir_PLASMA()
{
}

void cARCHIVO::escribir_DONANTES()
{
}

void cARCHIVO::escribir_RECEPTORES()
{
}

void cARCHIVO::escribir_CENTROS()
{
}
