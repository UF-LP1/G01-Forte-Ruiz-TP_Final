#include "Excepciones.h"
#include <iostream>

const char* ExcepcionFecha::what() const throw()
{
    return "EXCEPCION: Fecha invalida, vuelva a ingresar por favor: ";
}
