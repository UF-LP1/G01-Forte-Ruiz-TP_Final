#include "cMENU.h"
#include "ePROVINCIA.h"

cMENU::cMENU(cBSA* bsa)
{
	this->BSA = bsa;
}

cMENU::~cMENU()
{
}

void cMENU::ejecutar()
{
	int opcion;

	while (opcion != 7)
	{
		char dummy;

		imprimir();

		cin >> opcion;

		while (opcion < 1 && opcion > 7)
		{
			cout << "Reingrese su eleccion (unicamente validos las opciones de 1 a 7):  ";
			cin >> opcion;
			cout << endl;
		}

		switch (opcion)
		{
		case 1:
		{
			int op2;
			cPACIENTE* pac1; //ERROR: NO HAY CONSTRUCTOR POR DEFECTO
			cDONANTE* donante;
			cRECEPTOR* receptor;
			vector<cPACIENTE*> vdonante, vreceptor;


			cout << "¿Ingresa un donante o un receptor? " << endl
				<< "1) Donante." << endl
				<< "2) Receptor." << endl
				<< "3) VOLVER" << endl
				<< "Opcion: ";

			cin >> op2; cout << endl;

			while (op2 != 1 && op2 != 2 && op2 != 3)
			{
				cout << "Reingrese su eleccion (unicamente validas las opciones 1 y 2): ";
				cin >> op2; cout << endl;
			}

			if (op2 == 1)
			{
				//pac1 = cDONANTE::escribir(); //LO ESTOY HACIENDO COMO ESTATICO
				donante = dynamic_cast<cDONANTE*>(pac1);
				vdonante[0] = donante;
				this->BSA->agregar_paciente(vdonante);
			}
			else if (op2 == 2)
			{
				//pac1 = cRECEPTOR:: escribir();
				receptor = dynamic_cast<cRECEPTOR*>(pac1);
				vreceptor[0] = receptor;
				this->BSA->agregar_paciente(vreceptor);
			}
			else if (op2 == 3)
				break;

			cout << "Presione cualquier tecla para volver";
			cin >> dummy; cout << endl;
			break;
		}
		case 2:
		{
			string nombre, partido, prov;
			ePROVINCIA provincia;

			cout << "Datos a ingresar del centro de salud: " << endl
				<< "Nombre: ";
			cin >> nombre; cout << endl;
			cout << "Partido: ";
			cin >> partido; cout << endl;
			cout << "Provincia: ";
			cin >> prov; cout << endl;
			if (prov == "Buenos Aires" || prov == "buenos aires")
				provincia = BuenosAires;

			buscar_centro(nombre, partido, provincia);
			cout << endl;
			cout << "Presione cualquier tecla para volver";
			cin >> dummy;
			break;
		}
		case 3:
		{
			int op2;
			string dni;
			cout << "Ingrese DNI del paciente que desea buscar: ";
			cin >> dni; cout << endl;
			cRECEPTOR* receptor = buscar_receptor(dni);
			//
			imprimir_submenu();
			cout << "Opcion: "; cin >> op2; cout << endl;

			while (op2 != 1 && op2 != 2)
			{
				cout << "Reingrese su eleccion (unicamente validas las opciones 1 y 2): ";
				cin >> op2; cout << endl;
			}

			if (op2 == 1)
			{
				int op3;


				while (op3 != 10)
				{
					cout << "¿Que datos desea modificar?" << endl;
					imprimir_datos_receptor();
					cout << "Opcion: "; cin >> op3; cout << endl;

					while (op3 < 0 && op3 > 10)
					{
						cout << "Reingrese su eleccion (unicamente validas las opciones del 1 al 8): ";
						cin >> op3; cout << endl;
					}
					switch (op3)
					{
					case 1:
					{
						string nombre;
						cout << "Ingrese nombre: "; cin >> nombre; cout << endl;
						//receptor->set_nombre(nombre);
						break;
					}
					case 2:
					{
						int dia, mes, anio;
						cout << "Fecha de nacimiento: "; cin >> dia >> dummy >> mes >> dummy >> anio; cout << endl;
						while (dia <= 0 || mes <= 0 || anio <= 1900) //1900 porque ya todos estan muertos ahi
						{
							cout << "Fecha de nacimiento invalida, vuelva a ingresar por favor: "; cin >> dia >> dummy >> mes >> dummy >> anio;
							cout << endl;
						}
						struct tm f_nac;
						f_nac.tm_mday = dia;
						f_nac.tm_mon = mes - 1;
						f_nac.tm_year = anio - 1900;

						time_t f = mktime(&f_nac);
						//receptor->set_fecha_nacimiento(f);
						break;
					}
					case 3:
					{
						string telefono;
						cout << "Ingrese telefono: "; cin >> telefono; cout << endl;
						//receptor->set_telefono(telefono);
						break;
					}
					case 4:
					{
						string sexo;
						eSEXO sex;
						cout << "Ingrese sexo: "; cin >> sexo; cout << endl;
						while (sexo != "femenino" && sexo != "masculino")
						{
							cout << "Escriba todo en minusculas: ";
							cin >> sexo; cout << endl;
						}
						if (sexo == "femenino")
						{
							sex = FEMENINO;
						}
						else if (sexo == "masculino")
						{
							sex = MASCULINO;
						}
						//receptor->set_sexo(sex);
						break;
					}
					case 5:
					{
						int op4;
						cout << "¿Que tipo de fluido es?" << endl
							<< "1) Sangre" << endl
							<< "2) Medula" << endl
							<< "3) Plasma" << endl
							<< "Opcion: "; cin >> op4; cout << endl;
						while (op4 != 1 && op4 != 2 && op4 != 3)
						{
							cout << "Reingrese su eleccion (unicamente validas del 1 al 3): ";
							cin >> op4; cout << endl;
						}
						if (op4 == 1)
						{
							unsigned int volumen = 450;
							string tipo;
							eTIPO type;
							char Rh;
							bool sign;
							cout << "Tipo sanguíneo: "; cin >> tipo >> Rh; cout << endl;
							while (Rh != '+' && Rh != '-')
							{
								cout << "Reingrese su eleccion (Ej: AB+): "; cin >> tipo >> Rh; cout << endl;
							}
							if (tipo == "A")
							{
								type = A;
							}
							else if (tipo == "AB")
							{
								type = AB;
							}
							else if (tipo == "B")
							{
								type = B;
							}
							else if (tipo == "O")
							{
								type = O;
							}
							if (Rh == '+')
								sign = true;
							else
								sign = false;

							cSANGRE sangre(volumen, type, sign);
							//receptor->set_fluido(sangre);

						}
						break;
					}


					}
				}

			}

			//
			cout << endl
				<< "Presiones cualquier tecla para volver";
			cin >> dummy;
			break;
		}
		case 4:
		{
			imprimir_listado_donantes();

			cout << endl
				<< "Presiones cualquier tecla para volver";
			cin >> dummy;
			ejecutar();
			break;
		}
		case 5:
		{
			imprimir_listado_receptores();

			cout << endl
				<< "Presiones cualquier tecla para volver";
			cin >> dummy;
			ejecutar();
			break;
		}
		case 6:
		{

			informe_mensual();
			cout << "Presione cualquier tecla para volver";
			cin >> dummy; cout << endl;
			break;
		}
		case 7:
		{
			cout << "-----Finalizacion del programa-----";
			break;
		}
		}

	}

	return;
}

void cMENU::buscar_centro(string nombre, string partido, ePROVINCIA provincia)
{
	vector<cRECEPTOR> lista_espera;

	for (int i = 0; i < this->BSA->get_lista_receptores().size(); i++)
	{
		if (this->BSA->get_lista_receptores()[i].get_centro().get_nombre() == nombre && this->BSA->get_lista_receptores()[i].get_centro().get_partido() == partido && this->BSA->get_lista_receptores()[i].get_centro().get_provincia() == provincia)
			lista_espera.push_back(this->BSA->get_lista_receptores()[i]);
	}

	for (int i = 0; i < lista_espera.size(); i++)
	{
		lista_espera[i].imprimir();
	}
	return;
}

cRECEPTOR* cMENU::buscar_receptor(string dni)
{

	cRECEPTOR* receptor;

	for (int i = 0; i < this->BSA->get_lista_receptores().size(); i++)
	{
		if (this->BSA->get_lista_receptores()[i].get_dni() == dni)
		{
			cout << "El paciente: " << endl;
				//<< this->BSA.get_lista_receptores()[i].imprimir() //imprime la prioridad tmb
			receptor = &(this->BSA->get_lista_receptores()[i]);
		}
		else
		{
			cout << "No se encontró el paciente" << endl;
			return nullptr;
		}
			
	}
}

void cMENU::imprimir_listado_donantes() //se puede hacer sobrecarga del << (tipo cout<<BSA.get_lista_donantes())
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
}

void cMENU::informe_mensual()
{
	const time_t f_actual = (const time_t)time(NULL);
	struct tm fecha1;
	localtime_s(&fecha1, &f_actual);
	ePROVINCIA prov;

	fecha1.tm_mday == 1; // Entonces así estamos en el dia uno del mes.

	time_t f_a = mktime(&fecha1);

	vector<int> cont1_x_prov;
	cont1_x_prov.resize(24, 0);

	for (int i = 0; i < this->BSA->get_lista_donantes().size(); i++)
	{
		if (this->BSA->get_lista_donantes()[i].get_registros().back().get_fecha_extraccion() >= f_a)
			prov = this->BSA->get_lista_donantes()[i].get_centro().get_provincia();
			cont1_x_prov[prov]; //PE
	}

	cout << "-------Cantidad de donaciones por provincia-------" << endl
		<< "Buenos Aires: " << cont1_x_prov[0] << endl
		<< "Ciudad Autonoma de Buenos Aires: " << cont1_x_prov[1] << endl
		<< "Catamarca: " << cont1_x_prov[2] << endl
		<< "Chaco: " << cont1_x_prov[3] << endl
		<< "Chubut: " << cont1_x_prov[4] << endl
		<< "Cordoba: " << cont1_x_prov[5] << endl
		<< "Corrientes: " << cont1_x_prov[6] << endl
		<< "Entre Rios: " << cont1_x_prov[7] << endl
		<< "Formosa: " << cont1_x_prov[8] << endl
		<< "Jujuy: " << cont1_x_prov[9] << endl
		<< "La Pampa: " << cont1_x_prov[10] << endl
		<< "La Rioja: " << cont1_x_prov[11] << endl
		<< "Mendoza: " << cont1_x_prov[12] << endl
		<< "Misiones: " << cont1_x_prov[13] << endl
		<< "Neuquen: " << cont1_x_prov[14] << endl
		<< "Rio Negro: " << cont1_x_prov[15] << endl
		<< "Salta: " << cont1_x_prov[16] << endl
		<< "San Juan: " << cont1_x_prov[17] << endl
		<< "San Luis: " << cont1_x_prov[18] << endl
		<< "Santa Cruz: " << cont1_x_prov[19] << endl
		<< "Santa Fe: " << cont1_x_prov[20] << endl
		<< "Santiago del estero: " << cont1_x_prov[21] << endl
		<< "Tierra del Fuego: " << cont1_x_prov[22] << endl
		<< "Tucuman: " << cont1_x_prov[23] << endl;
}

void cMENU::imprimir()
{
	cout << "-------------------------" << endl 
		 << "Banco de Sangre Argentino" << endl 
		 << "-------------------------";
	cout << endl << "1) Registrar paciente."
		<< endl << "2) Mostrar lista de espera de un centro de salud."
		<< endl << "3) Buscar un paciente en lista de espera."
		<< endl << "4) Mostrar listado de pacientes donantes."
		<< endl << "5) Mostrar listado de pacientes receptores."
		<< endl << "6) Informe mensual de donanciones en cada provincia."
		<< endl << "7) CERRAR" << endl;
	
}

void cMENU::imprimir_submenu()
{
	cout << endl << "¿Desea modificar los datos?"
		<< "1) Si" << endl << "2) No" << endl;
}

void cMENU::imprimir_datos_receptor()
{
	cout << "1) Nombre" << endl
		<< "2) Fecha de nacimiento" << endl
		<< "3) Telefono" << endl
		<< "4) Sexo" << endl
		<< "5) Fluido que precisa" << endl
		<< "6) Centro" << endl
		<< "7) Fecha que ingreso" << endl
		<< "8) Prioridad" << endl
		<< "9) Estado" << endl
		<< "10) VOLVER" << endl;
}
