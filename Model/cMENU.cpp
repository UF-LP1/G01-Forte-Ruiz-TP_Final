#include "cMENU.h"

cMENU::cMENU(cBSA* bsa)
{
	this->BSA = bsa;
}

cMENU::~cMENU()
{
}

void cMENU::ejecutar()
{
	int opcion=0;
	vector<int>* cont1_x_prov = new vector<int>;
	do
	{
		char dummy;

		imprimir();

		opcion = control_entradas(1, 10);

		switch (opcion)	
		{
		case 1: //registrar paciente, podria ser funcion, mas legible el codigo
		{
			int op2;
			cPACIENTE* pac1 =nullptr;

			cout << "¿Ingresa un donante o un receptor? " << endl
				<< "1) Donante." << endl
				<< "2) Receptor." << endl
				<< "3) VOLVER" << endl
				<< "Opcion: ";

			op2 = control_entradas(1, 3);
			
			if (op2 == 1)
			{
				pac1 = escribir_donante(); 
				if (pac1 == nullptr)
					cout << "Proceso cancelado" << endl;
			}
			else if (op2 == 2)
			{
				pac1 = escribir_receptor();
				if (pac1 == nullptr)
					cout << "Proceso cancelado" << endl;
			}

			if (pac1 != nullptr)
			{
				int d = this->BSA->agregar_paciente(pac1); 
				if (d == -1)
					cout << "El paciente que quiso agregar ya se encontraba en el BSA." << endl;
				if (d == 1)
					cout << "El paciente no paso los requisitos necesarios para ser donante." << endl;
			}

			if (pac1 != nullptr)
				delete pac1;
			getchar();
			break;
		}
		case 2: //buscar centro e imprimir lista de espera
		{
			cCENTRO* centro = escribir_centro();

			buscar_centro(centro);
			getchar();
			break;
		}
		case 3: //buscar receptor (opcion modificar)
		{
			int op2;
			string dni;
			cout << "Ingrese DNI del paciente que desea buscar: ";//si se quiere modificar un donante?
			cin >> dni; cout << endl;
			cRECEPTOR* receptor = buscar_receptor(dni);
			if (receptor == nullptr)
			{
				cout << "No se encontro al receptor." << endl;
				break;
			}
			cout << endl 
				<< "¿Desea modificar los datos?" << endl
				<< "1) Si." << endl << "2) No." << endl;

			op2 = control_entradas(1, 2);
			
			if (op2 == 1)
			{
				int op3=-1;

				do
				{
					imprimir_datos_receptor();
					
					op3 = control_entradas(1, 8);
					
					switch (op3)
					{
					case 1://nombre
					{
						string nombre = escribir_nombre();
						receptor->set_nombre(nombre);
						break;
					}
					case 2: //fecha nacimiento
					{
						time_t f = escribir_fecha();
						receptor->set_fecha_nacimiento(f);
						break;
					}
					case 3://telefono
					{
						string telefono = escribir_telefono();
						receptor->set_telefono(telefono);
						break;
					}
					case 4: //sexo
					{
						eSEXO sex= escribir_sexo();
						receptor->set_sexo(sex);
						break;
					}
					case 5://fluido
					{	cFLUIDO* fluid = escribir_fluido();
						receptor->set_fluido(fluid);
						break;
					}
					case 6://centro
					{
						cCENTRO* ptr = escribir_centro();
						if(ptr != nullptr)
							receptor->set_centro(ptr);
						
						cout << "Presione cualquier tecla para volver";
						cin >> dummy;
						
						break;
					}
					case 7: //prioridad
					{
						ePRIORIDAD prioridad = escribir_prioridad();
						receptor->set_prioridad(prioridad);
						break;
					}
					case 8: //estado
					{
						eESTADO estado = escribir_estado();
						receptor->set_estado(estado);
						break;
					}
					
					}//switch
				}//do
				while (op3 != 10);
			}//if

			//si (op2 == 2) no hace nada, deja continuar el programa que va a volver al menu principal
			getchar();
			break;
		}//case 3
		case 4: //buscar donante (opcion de modificar) //=case3, sobrecarga de funciones?
		{
			int op2;
			string dni;
			cout << "Ingrese DNI del paciente que desea buscar: ";//si se quiere modificar un donante?
			cin >> dni; cout << endl;
			cDONANTE* donante = buscar_donante(dni);
			//
			if (donante == nullptr)
			{
				cout << "No se encontro al donante." << endl;
				break;
			}
			imprimir_submenu();

			op2 = control_entradas(1, 3);

			if (op2 == 1)
			{
				int op3 = -1;

				do
				{
					imprimir_datos_donante();

					op3 = control_entradas(1, 8);

					switch (op3)
					{
					case 1://nombre
					{
						string nombre = escribir_nombre();
						donante->set_nombre(nombre);
						break;
					}
					case 2: //fecha nacimiento
					{
						time_t f = escribir_fecha();
						donante->set_fecha_nacimiento(f);
						break;
					}
					case 3://telefono
					{
						string telefono = escribir_telefono();
						donante->set_telefono(telefono);
						break;
					}
					case 4: //sexo
					{
						eSEXO sex = escribir_sexo();
						donante->set_sexo(sex);
						break;
					}
					case 5://fluido
					{	cFLUIDO* fluid = escribir_fluido();
						donante->set_fluido(fluid);
						break;
					}
					case 6://centro
					{
						cCENTRO* ptr = escribir_centro();
						if (ptr != nullptr)
							donante->set_centro(ptr);
						break;
					}
					case 7: //registros
					{
						vector <cREGISTRO> registros = escribir_registros();
						donante->set_registros(registros);
						break;
					}
					case 8: //historial
					{
						cHISTORIAL* hist= escribir_historial();
						donante->set_historial(hist);
						break;
					}
					case 9: //peso
					{
						float peso = escribir_peso();
						donante->set_peso(peso);
						break;
					}

					}//switch
				}//do
				while (op3 != 10);
			}//if

			if (op2 == 2 )
			{

				cPACIENTE* pac = BSA->iniciar_analisis(donante);
				if (pac == nullptr)
					cout << "No hubo ningun match." << endl;
				else
					dynamic_cast<cRECEPTOR*>(pac)->imprimir();			

			}
			//if op== 3 no hace nada, deja continuar el programa que va a volver al menu principal
			cout << endl;
			getchar();
			break;
		}
		case 5: //imprimir listado donantes
		{
			imprimir_listado_donantes();
			getchar();
			break;
		}
		case 6: //imprimir listado receptores
		{
			imprimir_listado_receptores();
			getchar();
			break;
		}
		case 7: //imprimir informe mensual
		{

			informe_mensual(cont1_x_prov); 
			getchar();
			break;
		}
		case 8:
		{
			for (int i = 0; i < this->BSA->get_lista_donantes().size(); i++)
			{
				this->BSA->iniciar_analisis(&(this->BSA->get_lista_donantes()[i]));
			}
			break;
			getchar();
		}
		case 10: //finalizar programa
		{
			delete cont1_x_prov;
			cout << "-----Finalizacion del programa-----";
			break;
		}
		}

	}
	while (opcion != 10);
	return;
}

//funciones extras
int cMENU::control_entradas(int inf, int sup)
{
	string aux;
	int op = 0;
	int ap = 0;

	int k = 0;
	int c = 0;
	do
	{
		c = 0;
		cin >> aux;
		for (int i = aux.length() - 1; i >= 0; i--)
		{
			if (isdigit(aux[i]))
			{
				char a = aux[i];
				ap = ap + pow(10, k) * atoi(&a);
				k++;
			}
			else
				c = -1;
		}
		if (c == -1)
		{
			cout << "Reingrese su eleccion (unicamente validas las opciones del " << inf << " al " << sup << "): ";

		}
		else
			op = ap;
	} while (op<inf || op>sup);


	return op;
}
cCENTRO* cMENU::verificar_centro(string nombre, string partido, ePROVINCIA provincia)
{
	int pos = -1;
	int i;
	for (i = 0; i < this->BSA->get_lista_centros().size(); i++)
	{
		if (this->BSA->get_lista_centros()[i].get_nombre() == nombre && this->BSA->get_lista_centros()[i].get_partido() == partido && this->BSA->get_lista_centros()[i].get_provincia() == provincia)
			pos = i;
			
	}
	if (i== this->BSA->get_lista_centros().size())
	{
		cout << endl << "No se encontro el centro en la lista de centros habilitados." << endl; //que vuelva a ingresar los datos 
		cout << endl;
		return nullptr;
	}

	return &(this->BSA->get_lista_centros()[pos]);
}

//funciones menu principal
void cMENU::buscar_centro(cCENTRO* centro) //imprime la lista de espera del centro
{
	vector<cRECEPTOR> lista_espera;

	for (int i = 0; i < this->BSA->get_lista_receptores().size(); i++)
	{	if(*(this->BSA->get_lista_receptores()[i].get_centro()) == centro) //sobrecarga del ==
			lista_espera.push_back(this->BSA->get_lista_receptores()[i]);
	}

	for (int i = 0; i < lista_espera.size(); i++) //sobrecarga cout?
	{
		lista_espera[i].imprimir();
	}
	return;
}
cRECEPTOR* cMENU::buscar_receptor(string dni)
{

	int pos = -1;
	int i;

	for (i = 0; i < this->BSA->get_lista_receptores().size(); i++)
	{
		if (this->BSA->get_lista_receptores()[i].get_dni() == dni)
		{
			cout << "El paciente: " << endl;
			this->BSA->get_lista_receptores()[i].imprimir(); //imprime la prioridad tmb
			pos = i;
		}
	}
	if (i == this->BSA->get_lista_receptores().size())
		return nullptr;
	return &(this->BSA->get_lista_receptores()[pos]);
}
cDONANTE* cMENU::buscar_donante(string dni)
{
	cDONANTE* donante = nullptr;
	int pos = -1;
	int i;

	for (i = 0; i < this->BSA->get_lista_donantes().size(); i++)
	{
		if (this->BSA->get_lista_donantes()[i].get_dni() == dni)
		{
			cout << "El paciente: " << endl;
			this->BSA->get_lista_donantes()[i].imprimir(); //
			pos = i;
		}
	}
	if (i == this->BSA->get_lista_donantes().size())
		return nullptr;
	return &(this->BSA->get_lista_donantes()[pos]);
}
void cMENU::imprimir_listado_donantes() // sobrecarga de <<?
{
	for (int i = 0; i < this->BSA->get_lista_donantes().size(); i++)
	{
		this->BSA->get_lista_donantes()[i].imprimir();
	}
}
void cMENU::imprimir_listado_receptores() //se podria hacer sobrecarga del << (tipo cout<<BSA.get_lista_donantes())
{
	for (int i = 0; i < this->BSA->get_lista_receptores().size(); i++)
	{
		this->BSA->get_lista_receptores()[i].imprimir();
	}
}//sobrecarga <<?
void cMENU::informe_mensual(vector<int>* cont1_x_prov)
{
	const time_t f_actual = (const time_t)time(NULL);
	struct tm fecha1;
	localtime_s(&fecha1, &f_actual);
	ePROVINCIA prov;

	fecha1.tm_mday = 1; // Entonces así estamos en el dia uno del mes.

	time_t f_a = mktime(&fecha1);

	cont1_x_prov->resize(24, 0);

	for (int i = 0; i < this->BSA->get_lista_donantes().size(); i++)
	{
		if (this->BSA->get_lista_donantes()[i].get_registros().back().get_fecha_extraccion() >= f_a)
			prov = this->BSA->get_lista_donantes()[i].get_centro()->get_provincia();
			cont1_x_prov->at(prov) += 1; //PE
	}

	cout << "-------Cantidad de donaciones por provincia-------" << endl
		<< "Buenos Aires: " << cont1_x_prov->at(0) << endl
		<< "Ciudad Autonoma de Buenos Aires: " << cont1_x_prov->at(1) << endl
		<< "Catamarca: " << cont1_x_prov->at(2) << endl
		<< "Chaco: " << cont1_x_prov->at(3) << endl
		<< "Chubut: " << cont1_x_prov->at(4) << endl
		<< "Cordoba: " << cont1_x_prov->at(5) << endl
		<< "Corrientes: " << cont1_x_prov->at(6) << endl
		<< "Entre Rios: " << cont1_x_prov->at(7) << endl
		<< "Formosa: " << cont1_x_prov->at(8) << endl
		<< "Jujuy: " << cont1_x_prov->at(9) << endl
		<< "La Pampa: " << cont1_x_prov->at(10) << endl
		<< "La Rioja: " << cont1_x_prov->at(11) << endl
		<< "Mendoza: " << cont1_x_prov->at(12) << endl
		<< "Misiones: " << cont1_x_prov->at(13) << endl
		<< "Neuquen: " << cont1_x_prov->at(14) << endl
		<< "Rio Negro: " << cont1_x_prov->at(15) << endl
		<< "Salta: " << cont1_x_prov->at(16) << endl
		<< "San Juan: " << cont1_x_prov->at(17) << endl
		<< "San Luis: " << cont1_x_prov->at(18) << endl
		<< "Santa Cruz: " << cont1_x_prov->at(19) << endl
		<< "Santa Fe: " << cont1_x_prov->at(20) << endl
		<< "Santiago del estero: " << cont1_x_prov->at(21) << endl
		<< "Tierra del Fuego: " << cont1_x_prov->at(22) << endl
		<< "Tucuman: " << cont1_x_prov->at(23) << endl;
}

//funciones escribir
cPACIENTE* cMENU::escribir_donante()
{
	int edad = escribir_edad();
	string nombre = escribir_nombre();
	time_t fecha = escribir_fecha();
	string tel = escribir_telefono();
	eSEXO sex = escribir_sexo();

	cCENTRO* centro = escribir_centro();
	if (centro == nullptr)
		return nullptr;
	cFLUIDO* fluido = escribir_fluido();
	string dni = escribir_dni(); //funcion escribir_paciente()? PARA NO REPETIR CODIGO
	vector <cREGISTRO> registros = escribir_registros();

	float peso = escribir_peso();
	cHISTORIAL* historial = escribir_historial();
	
	cDONANTE* pac = new cDONANTE(edad,nombre, fecha, tel, sex, fluido, centro, dni, registros, peso, historial);

	//cDONANTE pac(edad, nombre, fecha, tel, sex, fluido, centro, dni, registros,peso,historial);
	return pac;
}
cPACIENTE* cMENU:: escribir_receptor() //sobrecarga cin era aca?
{	
	int edad = escribir_edad();
	string nombre = escribir_nombre();
	time_t fecha = escribir_fecha();
	string tel = escribir_telefono();
	eSEXO sex = escribir_sexo();

	cCENTRO* centro = escribir_centro();
	if (centro == nullptr)
		return nullptr;

	cFLUIDO* fluido = escribir_fluido();

	string dni = escribir_dni(); //funcion escribir_paciente()? PARA NO REPETIR CODIGO

	ePRIORIDAD prioridad = escribir_prioridad();
	eESTADO estado = escribir_estado();

	cRECEPTOR* pac=new cRECEPTOR(edad, nombre, fecha, tel, sex, fluido, centro, dni, time(NULL), prioridad, estado);
	
	return pac;
}

//paciente
int cMENU::escribir_edad()
{
	int edad;
	cout << "Ingrese edad: "; cin >> edad; cout << endl;
	return edad;
}

string cMENU::escribir_nombre()
{	
	string nombre;
	cout << "Ingrese nombre: "; cin >> nombre; cout << endl;
	return nombre;
}
time_t cMENU::escribir_fecha()
{
	char dummy;
	int dia, mes, anio;
	cout << "Fecha: "; cin >> dia >> dummy >> mes >> dummy >> anio; cout << endl;
	while (dia <= 0 || mes <= 0 || anio <= 1900) //1900 porque ya todos estan muertos ahi
	{
		cout << "Fecha invalida, vuelva a ingresar por favor: "; 
		cin >> dia >> dummy >> mes >> dummy >> anio;
		cout << endl;
	}
	struct tm f_nac;
	f_nac.tm_mday = dia;
	f_nac.tm_mon = mes - 1;
	f_nac.tm_year = anio - 1900;

	time_t f = mktime(&f_nac); //difftime(f, time(NULL))

	return f;
}
string cMENU::escribir_telefono()
{
	string telefono;
	cout << "Ingrese telefono: "; cin >> telefono; cout << endl;
	
	return telefono;
}
eSEXO cMENU::escribir_sexo() 
{
	vector<eSEXO> sexos = { FEMENINO, MASCULINO };
	int pos;
	cout << "Ingrese sexo: " << endl
		<< "1)Femenino" << endl
		<< "2)Masculino" << endl;
	pos = control_entradas(1, 2);
	pos--;
	return sexos[pos];
}
cCENTRO* cMENU::escribir_centro()
{
	vector<ePROVINCIA> provincias = { BuenosAires, CABA,Catamarca, Chaco, Chubut, Cordoba, Corrientes, EntreRios, Formosa, Jujuy, LaPampa, LaRioja, Mendoza, Misiones, Neuquen, RioNegro,Salta, SanJuan, SanLuis, SantaCruz, SantaFe, SantiagoDelEstero,TierraDelFuego,Tucuman };
	string nombre, partido;
	int prov, op=0;
	cCENTRO* ptr;
	do
	{
		cout << "Datos a ingresar del centro de salud: " << endl
			<< "Nombre: ";
		cin >> nombre; cout << endl;
		cout << "Partido: ";
		cin >> partido; cout << endl;
		cout << "Provincia: ";
	
		imprimir_provincias();

		prov = control_entradas(1, 24);

		prov--;

		ptr = verificar_centro(nombre, partido, provincias[prov]);
		if (ptr == nullptr)
		{
			cout << "¿Desea volver a ingresar datos del centro?" << endl
				<< "1)Si" << endl << "2)No" << endl;
			op = control_entradas(1, 2);
		}
	} while (op==1);

	return ptr;
}
string cMENU::escribir_dni()
{
	string dni;
	cout << "Ingrese DNI del paciente: ";
	cin >> dni; cout << endl;
	return dni;
}
//fluidos
cFLUIDO* cMENU::escribir_fluido()
{
	cFLUIDO* fluid = nullptr;
	int op4;
	cout << "¿Que tipo de fluido es?" << endl //necesita o va a donar
		<< "1) Sangre" << endl
		<< "2) Medula" << endl
		<< "3) Plasma" << endl
		<< "Opcion: "; cin >> op4; cout << endl;
	op4 = control_entradas(1, 3);

	if (op4 == 1)
		fluid = escribir_sangre();

	if (op4 == 2)
		fluid = escribir_medula();

	if (op4 == 3)
		fluid = escribir_plasma();

	return fluid;
}
eTIPO cMENU::escribir_tipos()
{
	vector<eTIPO> tipos = { A,AB,B,O };

	cout << "Tipo sanguíneo: ";
	cout << "1)A" << endl << "2)AB" << endl << "3)B" << "4)O" << endl;
	int type = control_entradas(1, 4);
	type--;
	return tipos[type];
}
cFLUIDO* cMENU::escribir_sangre()
{
	char Rh= '1';
	bool sign;
	eTIPO type = escribir_tipos();

	cout << endl << "Ingresar Rh" << endl;
	cin >> Rh; cout << endl;

	while (Rh != '+' && Rh != '-')
	{
		cout << "Reingrese su eleccion (Ej: AB+): "; cin >> Rh; cout << endl;
	}
	if (Rh == '+')
		sign = true;
	else
		sign = false;
	
	cFLUIDO* ptr = new cSANGRE(450, type, sign);

	return ptr;
}
cFLUIDO* cMENU::escribir_plasma()
{	
	eTIPO type = escribir_tipos();
	cFLUIDO* ptr = new cPLASMA(450,type);

	return ptr;
}
cFLUIDO* cMENU::escribir_medula()
{	
	vector <eCOLOR> colores = {amarillo, rojo};
	cout << "Ingrese tipo de medula:" << endl
		<< "1)Amarilla" << endl << "2)Roja" << endl;
	int op = control_entradas(1, 2);
	op--;
	cFLUIDO* ptr= new cMEDULA(450, colores[op]);

	return ptr;
}

//receptor
ePRIORIDAD cMENU::escribir_prioridad()
{	
	vector<ePRIORIDAD> prioridades = { uno,dos,tres,cuatro,cinco };
	cout << "Ingrese la prioridad del paciente (del 1 al 5):" << endl;
	int op = control_entradas(1, 5);
	op--;
	return prioridades[op];
}
eESTADO cMENU::escribir_estado()
{
	vector<eESTADO> estados = { ESTABLE, INESTABLE, RECIBIO };
	cout << "Ingrese el estado del paciente" << endl
		<< "1)Estable" << endl << "2)Inestable" << endl << "3)Recibio" << endl;
	int op = control_entradas(1, 3);
	op--;
	return estados[op];

}

//donante
float cMENU::escribir_peso() //mayor a tanto (1kg) y menor a tanto(1000kg)?, 
{
	float peso;
	do
	{
		cout << "Ingrese el peso del paciente en kg: ";
		cin >> peso; cout << endl;
	} while (peso > 1.0 && peso < 1000.0);
	return peso;
}
cHISTORIAL* cMENU::escribir_historial()
{
	bool enf, tat;
	time_t fecha1;

	cout << "Tiene enfermedades:" << endl
		<< "1)No" << endl << "2)Si" << endl;
	enf = (control_entradas(1, 2) - 1); //false=0, true=1;
	cout << "Tiene tatuajes:" << endl
		<< "1)No" << endl << "2)Si" << endl;
	tat = (control_entradas(1, 2) - 1); //false=0, true=1;
	if (tat)
	{
		cout << "Ingrese la fecha del ultimo tatuaje:" << endl;
		fecha1 = escribir_fecha();
	}
	else
	{
		const time_t fecha_act = (const time_t)time(NULL);
		struct tm fecha;
		localtime_s(&fecha, &fecha_act);
		fecha.tm_mon -= 6; //le resto 6 meses a la fecha actual para que cumpla con los requitos
		time_t f_a = mktime(&fecha);
		fecha1 = f_a;
	}
	cHISTORIAL* ptr=new cHISTORIAL(tat,fecha1,enf);
	return ptr;

}
vector <cREGISTRO> cMENU::escribir_registros() //tiene que dar la opcion de no ingresar ninguno
{
	vector <cREGISTRO> registros;
	cREGISTRO registro;
	cFLUIDO* fluid;
	cCENTRO* centro;
	time_t fecha;
	int op = 0;
	do
	{
		cout << "1)Ingrese registro:" << endl;
		cout << "2)Volver" << endl;
		op = control_entradas(1, 2);
		if (op == 1)
		{
			fluid = escribir_fluido();
			centro = escribir_centro();
			fecha = escribir_fecha();
			registro.set_fluido(fluid);
			registro.set_fecha_extraccion(fecha);
			registro.set_centro(centro);
			registros.push_back(registro);
		}
	} while (op != 2);
	return registros;
}

// funciones imprimir
void cMENU::imprimir()
{
	cout << "-------------------------" << endl 
		 << "Banco de Sangre Argentino" << endl 
		 << "-------------------------";
	cout << endl << "1) Registrar paciente."
		<< endl << "2) Mostrar lista de espera de un centro de salud."
		<< endl << "3) Buscar un paciente en lista de espera."
		<< endl << "4) Buscar un donante."
		<< endl << "5) Mostrar listado de pacientes donantes."
		<< endl << "6) Mostrar listado de pacientes receptores."
		<< endl << "7) Informe mensual de donanciones en cada provincia."
		<< endl << "8) Iniciar analisis."
		<< endl << "10) CERRAR" << endl<< endl; //agregar opcion comenzar analisis
	
}
void cMENU::imprimir_submenu()
{
	cout << endl
		<< "1) Modificar datos" << endl
		<< "2) Buscar match" << endl
		<< "3) VOLVER" << endl;
}
void cMENU::imprimir_datos_receptor()
{
	cout << "¿Que datos desea modificar?" << endl;
	cout << "1) Nombre" << endl 
		<< "2) Fecha de nacimiento" << endl
		<< "3) Telefono" << endl
		<< "4) Sexo" << endl  
		<< "5) Fluido que precisa" << endl
		<< "6) Centro" << endl  
		<< "7) Prioridad" << endl
		<< "8) Estado" << endl
		<< "10) VOLVER" << endl;
}
void cMENU::imprimir_datos_donante()
{

	cout << "¿Que datos desea modificar?" << endl;
	cout << "1) Nombre" << endl
		<< "2) Fecha de nacimiento" << endl
		<< "3) Telefono" << endl
		<< "4) Sexo" << endl
		<< "5) Fluido que dona" << endl
		<< "6) Centro" << endl
		<< "7) Agregar registro" << endl
		<< "8) Modificar historial" << endl
		<< "9) Peso" << endl
		<< "10) VOLVER" << endl;
}
void cMENU:: imprimir_provincias()
{
	cout << "1)BuenosAires" << endl
		<< "2)CABA" << endl
		<< "3)Catamarca" << endl
		<< "4)Chaco" << endl
		<< "5)Chubut" << endl
		<< "6)Cordoba " << endl
		<< "7)Corrientes" << endl
		<< "8)EntreRios" << endl
		<< "9)Formosa" << endl
		<< "10)Jujuy" << endl
		<< "11)LaPampa" << endl
		<< "12)LaRioja" << endl
		<< "13)Mendoza" << endl
		<< "14)Misiones" << endl
		<< "15)Neuquen" << endl
		<< "16)RioNegro" << endl
		<< "17)Salta" << endl
		<< "18)SanJuan" << endl
		<< "19)SanLuis" << endl
		<< "20)SantaCruz" << endl
		<< "21)SantaFe" << endl
		<< "22)SantiagoDelEstero" << endl
		<< "23)TierraDelFuego" << endl
		<< "24)Tucuman" << endl;
}

/*
void cMENU::void limpiar_pantalla()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
*/