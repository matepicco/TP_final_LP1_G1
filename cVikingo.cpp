#include "cVikingo.h"

cVikingo::cVikingo()
{}

cVikingo::cVikingo(string nombrev, string apellidov, string posicionv)
{
    this->nombreV = nombrev;
    this->apellidoV = apellidov;
    this->posicionV = posicionv;
}

string cVikingo::get_nombreV()
{
    return this->nombreV;
}

string cVikingo::get_apellido()
{
    return this->apellidoV;
}

string cVikingo::get_posicionV()
{
    return this->posicionV;
}

unsigned int  cVikingo::get_DragonesEliminados()
{
    return this->DragonesEliminados;
}

void cVikingo::set_DragonesEliminados(unsigned int cant)
{
    this->DragonesEliminados = this->DragonesEliminados + cant;
}

void cVikingo::set_posicionV(string pos)
{
    this->posicionV = pos;
}


void cVikingo::trabajar()//asigna una posicion
{
   //seria como elegir la posicion, granjero, stripper, entrenador, corredor de bolsa, etc.
}  //entrenador, retirado, granjero,

void cVikingo::atacarDragones()
{
}

cVikingo::~cVikingo()
{
}