#include "cFormaAtaque.h"

cFormaAtaque::cFormaAtaque(eTipoAtaque tipoataque, eDanio tipodanio, unsigned int danio)
{
	this->tipodeataque = tipoataque;
	this->tipodedanio = tipodanio;
	this->cantDanioD = danio;
}

void cFormaAtaque::CambiarTipo(eTipoAtaque tipo)
{
	this->tipodeataque = tipo;
}

eDanio cFormaAtaque::get_danio()
{
	return this->tipodedanio;
}

eTipoAtaque cFormaAtaque::get_tipoataque()
{
	return this->tipodeataque;
}

unsigned int cFormaAtaque::getCantDanioD()
{
	return this->cantDanioD;
}

void cFormaAtaque::cambiarDanio(eDanio danio)
{
	this->cambiarDanio(danio);
}

cFormaAtaque::~cFormaAtaque() {}