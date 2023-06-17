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

cTRANSPLANTE* cCENTRO::realizar_transplante()
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

	cTRANSPLANTE transplante(t, b); //FALTA NEW
	return &transplante;
	
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


string cCENTRO::to_string() const
{
	string prov;
	const char* provincias[] = { "BuenosAires", "CABA","Catamarca", "Chaco", "Chubut", "Cordoba", "Corrientes", "EntreRios", "Formosa", "Jujuy", "LaPampa", "LaRioja", "Mendoza", "Misiones", "Neuquen", "RioNegro","Salta", "SanJuan", "SanLuis", "SantaCruz", "SantaFe", "SantiagoDelEstero","TierraDelFuego","Tucuman" };
	prov = provincias[this->provincia];
	stringstream ss;
	ss << "Centro de salud: " << endl;

	ss << "Nombre: " << this->nombre << endl
		<< "Direccion: " << this->direccion << endl
		<< "Partido: " << this->partido << endl
		<< "Provincia" << prov << endl
		<< "Telefono" << this->telefono << endl;

	return ss.str();
}

void cCENTRO::imprimir()
{
	cout << this->to_string() << endl;
}

bool cCENTRO::operator==(cCENTRO* centro)
{
	if (this->nombre == centro->get_nombre() && this->partido == centro->get_partido() && this->provincia == centro->get_provincia())
		return true;
	else
		return false;
}
