#include "cFormaAtaque.h"

cFormaAtaque::cFormaAtaque(eTipo tipoataque, eDamage tipodanio)
{
	this->tipodeataque = tipoataque;
	this->tipodedanio = tipodanio;
}

void cFormaAtaque::CambiarTipo(eTipo tipo)
{
	this->tipodeataque = tipo;
}

eDamage cFormaAtaque::get_danio()
{
	return this->tipodedanio;
}

eTipo cFormaAtaque::get_tipo()
{
	return this->tipodeataque;
}

cFormaAtaque::~cFormaAtaque() {}
