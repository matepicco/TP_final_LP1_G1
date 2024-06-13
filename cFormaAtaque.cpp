#include "cFormaAtaque.h"

cFormaAtaque::cFormaAtaque(unsigned int danio, eDanio tipodanio)
{
	this->cantDanioD = danio;
	this->tipoDanio = tipodanio;
}

cFormaAtaque::~cFormaAtaque()
{}

unsigned int cFormaAtaque::getCantDanioD()
{
	return this->cantDanioD;
}

eDanio cFormaAtaque::getTipoDanio()
{
	return this->tipoDanio;
}

void cFormaAtaque::setCantDanio(unsigned int danio)
{
	this->cantDanioD = danio;
}

void cFormaAtaque::cambiarDanio(eDanio danio)
{
	this->tipoDanio = danio;
}
