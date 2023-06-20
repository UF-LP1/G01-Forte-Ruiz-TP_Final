#include "Excepciones.h"
#include <iostream>

const char* ExcepcionFecha::what() const throw()
{
    return "EXCEPCION: Fecha invalida, vuelva a ingresar por favor: ";
}

const char* ExcepcionEspacio::what() const throw()
{
    return "EXCEPCION: No hay mas espacio para cargar la lista.";
}
