#include "cFormaAtaque.h"

cFormaAtaque::cFormaAtaque(unsigned int danio, eIntensidad tipodanio)
{
	if (danio <= 0)
		this->cantDanioD = 20;
	if(danio >=100)
		this->cantDanioD = 80;
	else if(danio>=0 || danio<100)
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
