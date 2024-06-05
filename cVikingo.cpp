#include "cVikingo.h"

cVikingo::cVikingo(string nombrev, string apellidov,eCaract caracteristicasfisicas)
{
    this->nombreV = nombrev;
    this->apellidoV = apellidov;
    this->caractFisicasV = caracteristicasfisicas;
    this->DragonesEliminados = 0;
    trabajarEnBerk();
}

string cVikingo::get_nombreV()
{
    return this->nombreV;
}

string cVikingo::get_apellido()
{
    return this->apellidoV;
}

ePos cVikingo::get_posicionV()
{
    return this->posicion;
}

unsigned int  cVikingo::get_DragonesEliminados()
{
    return this->DragonesEliminados;
}

void cVikingo::set_DragonesEliminados(unsigned int cant)
{
    this->DragonesEliminados = this->DragonesEliminados + cant;
}

void cVikingo::set_posicionV(ePos pos)
{
    this->posicion = pos;
}

void cVikingo::trabajarEnBerk()
{  
    if (caractFisicasV == Fortachon)
        set_posicionV(Leniador);
    if (caractFisicasV == Matematico)
        set_posicionV(Comerciante);
    else
        set_posicionV(Agricultor);
}

void cVikingo::RelacionarseConDragon(cVikingo *ptrV)
{
}

cVikingo::~cVikingo()
{
}