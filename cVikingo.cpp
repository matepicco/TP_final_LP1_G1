#include "cVikingo.h"

cVikingo::cVikingo()
{
}

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

unsigned int cVikingo::get_DragonesEliminados()
{
    return this->DragonesEliminados;
}

void cVikingo::set_posicionV(string pos)
{
    this->posicionV = pos;
}


void cVikingo::trabajar()//asigna una posicion
{
   //seria como elegir la posicion, granjero, stripper, entrenador, corredor de bolsa, etc.
}  //entrenador, retirado, granjero, 

void cVikingo::AtacarDragon(cDragon& objD)
{
    //random 0 o 1 que hacer q muera el dragon o muera l vikin
    objD.get_estado() = false;
    TerminarDragon();

    //mas adelante iria mas desarrollado con el tema de comparar habilidades
    //o que le baje la vida o simplemente vivan los dos
}

void cVikingo::TerminarDragon()
{
    this->DragonesEliminados++;
}

cVikingo::~cVikingo()
{
}