#include <iostream>

#include "cMENU.h"

int main()
{
	time_t fecha1;
	const time_t fecha_act = (const time_t)time(NULL);
	struct tm fecha;
	localtime_s(&fecha, &fecha_act);
	fecha.tm_mon -= 6; //le resto 6 meses a la fecha actual para que cumpla con los requitos
	time_t f_a = mktime(&fecha);
	fecha1 = f_a;


	cCENTRO* centro1 = new cCENTRO("Centro de Salud San Martin", "Avenida San Martin 123", "La Matanza", BuenosAires, "+54 11 1234 - 5678");
	cCENTRO* centro2 = new cCENTRO("Hospital Central de Córdoba", "Calle Principal 456", "Cordoba", Cordoba, "+54 351 9876 - 5432");
	cCENTRO* centro3 = new cCENTRO("Clinica Santa Rosa", "Avenida Libertador 789", "Santa Rosa", LaPampa, "+54 2954 123 - 456");
	cCENTRO* centro4 = new cCENTRO("Hospital Publico San Juan", "Calle Principal 987", "San Juan", SanJuan, "+54 264 987 - 6543");
	cCENTRO* centro5 = new cCENTRO("Centro de Atencion Medica Rosario", "Calle Principal 321", "Rosario", SantaFe, "+54 341 6543 - 2109");
	cCENTRO* centro6 = new cCENTRO("Hospital Regional Mendoza", "Avenida Principal 567", "Mendoza", Mendoza, "+54 261 4321 - 0987");
	cCENTRO* centro7 = new cCENTRO("Clinica Del Valle", "Calle Principal 654", "Neuquen", Neuquen, "+54 299 2109 - 8765");
	cCENTRO* centro8 = new cCENTRO("Hospital Publico Salta", "Avenida Principal 890", "Salta", Salta, "+54 387 8765 - 4321");
	cCENTRO* centro9 = new cCENTRO("Centro de Salud Tucuman", "Calle Principal 432", "San Miguel de Tucuman", Tucuman, "+54 381 543 - 2109");
	cCENTRO* centro10 = new cCENTRO("Hospital Publico Rio Negro", "Avenida Principal 1098", " Viedma", RioNegro, " +54 2920 876 - 5432");
	 
	vector<cCENTRO> lista_centros;
	lista_centros.push_back(*centro1);
	lista_centros.push_back(*centro2);
	lista_centros.push_back(*centro3);
	lista_centros.push_back(*centro4);
	lista_centros.push_back(*centro5);
	lista_centros.push_back(*centro6);
	lista_centros.push_back(*centro7);
	lista_centros.push_back(*centro8);
	lista_centros.push_back(*centro9);
	lista_centros.push_back(*centro10);

	cFLUIDO* fluido1 = new cPLASMA(450, AB);
	cFLUIDO* fluido2 = new cSANGRE(450, B, true);
	cFLUIDO* fluido3 = new cMEDULA(450, amarillo);
	cFLUIDO* fluido4 = new cSANGRE(450, A, false);
	cFLUIDO* fluido5 = new cPLASMA(450, O);
	cFLUIDO* fluido6 = new cMEDULA(450, rojo);
	cFLUIDO* fluido7 = new cPLASMA(450, B);
	cFLUIDO* fluido8 = new cSANGRE(450, AB, true);
	cFLUIDO* fluido9 = new cSANGRE(450, O, false);
	cFLUIDO* fluido10 = new cMEDULA(450, amarillo);

	cRECEPTOR* pac11 = new cRECEPTOR(32, "Maria Garcia", 811334400, "123456789", FEMENINO, fluido1, centro1, "12345678", 1703622400, tres, ESTABLE);
	cRECEPTOR* pac12 = new cRECEPTOR(41, "Juan Gonzalez", 724310400, "987654321", MASCULINO, fluido2, centro2, "98765432", 1692979200, dos, ESTABLE);
	cRECEPTOR* pac13 = new cRECEPTOR(28, "Laura Fernandez", 940054400, "555555555", FEMENINO, fluido3, centro3, "55555555", 1664732800, uno, ESTABLE);
	cRECEPTOR* pac14 = new cRECEPTOR(49, "Carlos Rodriguez", 629372800, "1111111111", MASCULINO, fluido4, centro4, "11111111", 1686803200, cinco, ESTABLE);
	cRECEPTOR* pac15 = new cRECEPTOR(36, "Ana Martinez", 787046400, "999999999", FEMENINO, fluido5, centro5, "99999999", 1672406400, cuatro, ESTABLE);
	cRECEPTOR* pac16 = new cRECEPTOR(39, "Pedro Lopez", 680851200, "777777777", MASCULINO, fluido6, centro6, "77777777", 1680576000, tres, ESTABLE);
	cRECEPTOR* pac17 = new cRECEPTOR(45, "Andrea Ramirez", 594144000, "444444444", FEMENINO, fluido7, centro7, "44444444", 1708934400, dos, ESTABLE);
	cRECEPTOR* pac18 = new cRECEPTOR(31, "Alejandro Torres", 827625600, "666666666",MASCULINO, fluido8, centro8, "66666666", 1697932800, uno, ESTABLE);
	cRECEPTOR* pac19 = new cRECEPTOR(37, "Carolina Vargas", 757084800, "888888888", FEMENINO, fluido9, centro9, "88888888", 1675590400, cinco, ESTABLE);
	cRECEPTOR* pac20 = new cRECEPTOR(43, "Sergio Herrera", 672979200, "222222222", MASCULINO, fluido10, centro10, "22222222", 1700188800, cuatro, ESTABLE);

	VECTOR<cRECEPTOR> lista_receptores;
	lista_receptores + pac11;
	lista_receptores + pac12;
	lista_receptores + pac13;
	lista_receptores + pac14;
	lista_receptores + pac15;
	lista_receptores + pac16;
	lista_receptores + pac17;
	lista_receptores + pac18;
	lista_receptores + pac19;
	lista_receptores + pac20;

	cHISTORIAL* historial1 = new cHISTORIAL(false, fecha1,false);
	cHISTORIAL* historial2 = new cHISTORIAL( true, fecha1, false);
	cHISTORIAL* historial3 = new cHISTORIAL( false, fecha1, false);
	cHISTORIAL* historial4 = new cHISTORIAL( true, fecha1, false);
	cHISTORIAL* historial5 = new cHISTORIAL( true, fecha1, false);
	cHISTORIAL* historial6 = new cHISTORIAL( true, fecha1, false);
	cHISTORIAL* historial7 = new cHISTORIAL(false, fecha1, false);
	cHISTORIAL* historial8 = new cHISTORIAL(false, fecha1, false);
	cHISTORIAL* historial9 = new cHISTORIAL( true, fecha1, false);
	cHISTORIAL* historial10 = new cHISTORIAL(true, fecha1,false);

	vector<cREGISTRO> registros;

	cDONANTE* pac1 = new cDONANTE(35,"Maria Lopez", 534643200, "+1 (555) 123 - 4567", FEMENINO, fluido1, centro1, "12345678", registros, 54.2, historial1);
	cDONANTE* pac2 = new cDONANTE(25,"Juan Perez", 630720000, "+1 (555) 987 - 6543", MASCULINO, fluido2, centro2, "87654321", registros, 68.9, historial2);
	cDONANTE* pac3 = new cDONANTE(20,"Ana Martinez", 757382400, "+1 (555) 246 - 8109", FEMENINO, fluido3, centro3,  "65432187", registros, 62.3, historial3);
	cDONANTE* pac4 = new cDONANTE(28,"Pedro Gonzalez", 662688000, "+1 (555) 555 - 1234", MASCULINO, fluido4, centro4,  "98765432", registros, 78.6, historial4);
	cDONANTE* pac5 = new cDONANTE(22,"Laura Rodriguez", 789331200, "+1 (555) 777 - 8888", FEMENINO, fluido5, centro5, "54321678", registros, 71.4, historial5);
	cDONANTE* pac6 = new cDONANTE(32,"Carlos Sanchez", 703382400, "+1 (555) 444 - 3333", MASCULINO, fluido6, centro6, "87654321", registros, 56.8, historial6);
	cDONANTE* pac7 = new cDONANTE(41,"Sofia Hernandez", 576864000, "+1 (555) 222 - 9999", FEMENINO, fluido7, centro7, "76543210", registros, 64.2, historial7);
	cDONANTE* pac8 = new cDONANTE(36,"Andres Morales", 694310400, "+1 (555) 777 - 1111", MASCULINO, fluido8, centro8, "10293847", registros, 69.7, historial8);
	cDONANTE* pac9 = new cDONANTE(23,"Gabriela Castro", 787948800, "+1 (555) 888 - 7777", FEMENINO, fluido9, centro9,  "93847562", registros, 75.1, historial9);
	cDONANTE* pac10 = new cDONANTE(30,"Alejandro Fernandez", 660816000, "+1 (555) 999 - 0000", MASCULINO, fluido10, centro10,  "74628391", registros, 63.5, historial10);

	vector<cDONANTE*> lista_donantes;
	lista_donantes.push_back(pac1);
	lista_donantes.push_back(pac2);
	lista_donantes.push_back(pac3);
	lista_donantes.push_back(pac4);
	lista_donantes.push_back(pac5);
	lista_donantes.push_back(pac6);
	lista_donantes.push_back(pac7);
	lista_donantes.push_back(pac8);
	lista_donantes.push_back(pac9);
	lista_donantes.push_back(pac10);

	VECTOR<cDONANTE> lista_aux;
	cBSA* banco= new cBSA(lista_aux, lista_receptores, lista_centros);

	for (int i = 0; i < lista_donantes.size(); i++)
	{
		banco->agregar_paciente(lista_donantes[i]);
	}
	
	cMENU menu(banco);
	menu.ejecutar();

	delete banco;

	for (int i = 0; i < lista_donantes.size(); i++)
	{
		if (lista_donantes[i] != nullptr)
			delete lista_donantes[i];
	}
	
	delete pac11;
	delete pac12;
	delete pac13;
	delete pac14;
	delete pac15;
	delete pac16;
	delete pac17;
	delete pac18;
	delete pac19;
	delete pac20;

	delete centro1;
	delete centro2;
	delete centro3;
	delete centro4;
	delete centro5;
	delete centro6;
	delete centro7;
	delete centro8;
	delete centro9;
	delete centro10;

	delete fluido1;
	delete fluido2;
	delete fluido3;
	delete fluido4;
	delete fluido5;
	delete fluido6;
	delete fluido7;
	delete fluido8;
	delete fluido9;
	delete fluido10;

	delete historial1;
	delete historial2;
	delete historial3;
	delete historial4;
	delete historial5;
	delete historial6;
	delete historial7;
	delete historial8;
	delete historial9;
	delete historial10;

	return 0;
}

