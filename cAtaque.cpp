#include "cAtaque.h"

cAtaque::cAtaque(eTipoAtaque tipoataque, eDanio tipodanio, unsigned int danio): cFormaAtaque(danio,tipodanio)
{
	this->tipoAtaque = tipoataque;
}

cAtaque::~cAtaque()
{}

eTipoAtaque cAtaque::getTipoAtaque()
{
	return this->tipoAtaque;
}

void cAtaque::CambiarTipo(eTipoAtaque tipo)
{
	this->tipoAtaque = tipo;
}

void cAtaque::combatir()
{
}
