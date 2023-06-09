#include "cCENTRO.h"

cCENTRO::cCENTRO(string nombre, string direccion, string partido, ePROVINCIA provincia, string telefono)
{
	this->nombre = nombre;
	this->direccion = direccion;
	this->partido = partido;
	this->provincia = provincia;
	this->telefono = telefono;
}

cCENTRO::~cCENTRO()
{
}

bool cCENTRO::realizar_transplante(cDONANTE donante, cRECEPTOR receptor)
{
	int a;
	bool b;
	srand(time(NULL));
	a = rand() % 1;// los valores bool son 0 y 1, si no funciona hacer los if
	if (a == 1)
		b = true;
	else if (a == 0) //HICE LO DE LOS IFS POR LAS DUDAS
		b = false;
	time_t t = time(NULL);

	return a;
	cTRANSPLANTE transplante(t, &receptor, receptor.get_centro(), receptor.get_fluido(), b);
	transplante.imprimir();
}

void cCENTRO::set_nombre(string nombre)
{ 
	this->nombre = nombre;
}

void cCENTRO::set_direccion(string direccion)
{
	this->direccion = direccion;
}

void cCENTRO::set_partido(string partido)
{
	this->partido = partido;
}

void cCENTRO::set_provincia(ePROVINCIA provincia)
{
	this->provincia = provincia;
}

void cCENTRO::set_telefono(string telefono)
{
	this->telefono = telefono;
}

void cCENTRO::imprimir()
{
}

//getters

string cCENTRO::get_nombre()
{
	return this->nombre;
}

string cCENTRO::get_direccion()
{
	return this->direccion;
}

string cCENTRO::get_partido()
{
	return this->partido;
}

ePROVINCIA cCENTRO::get_provincia()
{
	return this->provincia;
}

string cCENTRO::get_telefono()
{
	return this->telefono;
}

string cCENTRO::to_string_CENTRO() const
{
	string c, prov;
	const char* provincias[] = { "BuenosAires", "CABA","Catamarca", "Chaco", "Chubut", "Cordoba", "Corrientes", "EntreRios", "Formosa", "Jujuy", "LaPampa", "LaRioja", "Mendoza", "Misiones", "Neuquen", "RioNegro","Salta", "SanJuan", "SanLuis", "SantaCruz", "SantaFe", "SantiagoDelEstero","TierraDelFuego","Tucuman" };
	prov = provincias[this->provincia]; //PE
	c.append(this->nombre);
	c.append(", "); c.append(this->direccion);
	c.append(", "); c.append(this->partido);
	c.append(", "); c.append(prov);
	c.append(", "); c.append(this->telefono);

	return c;
}

void cCENTRO::imprimir_CENTRO()
{
	cout << this->to_string_CENTRO() << endl;
}
