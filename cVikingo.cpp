#include "cVikingo.h"

cVikingo::cVikingo()
{
}

cVikingo::cVikingo(string nombrev, string apellidov, string posicionv, unsigned int dragoneliminado)
{
    this->nombreV = nombrev;
    this->apellidoV = apellidov;
    this->posicionV = posicionv;
    this->DragonesEliminados = dragoneliminado;
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

void cVikingo::set_DragonesEliminados(unsigned int dragoneseliminados)
{
    this->DragonesEliminados = dragoneseliminados;
}

void cVikingo::trabajar()
{
    //trabajandoooooooooooooooooooooo
}

void cVikingo::atacarDragones(cDragon* objD)
{
    //chachacha..................

    if()
}

unsigned int cVikingo::TerminarDragon()
{
    this->DragonesEliminados++;
}

cVikingo::~cVikingo()
{
}