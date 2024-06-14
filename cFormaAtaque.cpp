#include "cFormaAtaque.h"

cFormaAtaque::cFormaAtaque(unsigned int danio, eIntensidad tipodanio)
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

eIntensidad cFormaAtaque::getTipoDanio()
{
	return this->tipoDanio;
}

void cFormaAtaque::setCantDanio(unsigned int danio)
{
	this->cantDanioD = danio;
}

void cFormaAtaque::cambiarIntensidad(eIntensidad danio)
{
	this->tipoDanio = danio;
}
