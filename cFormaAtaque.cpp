#include "cFormaAtaque.h"

cFormaAtaque::cFormaAtaque(eTipoAtaque tipoataque, eDamage tipodanio)
{
	this->tipodeataque = tipoataque;
	this->tipodedanio = tipodanio;
}

void cFormaAtaque::CambiarTipo(eTipoAtaque tipo)
{
	this->tipodeataque = tipo;
}

eDamage cFormaAtaque::get_danio()
{
	return this->tipodedanio;
}

eTipoAtaque cFormaAtaque::get_tipoataque()
{
	return this->tipodeataque;
}

cFormaAtaque::~cFormaAtaque() {}
