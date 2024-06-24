#include "cFormaCombate.h"

cFormaCombate::cFormaCombate(unsigned int danio, eIntensidad tipodanio)
{
	if (danio <= 0)
		this->cantDanioD = 20;
	if(danio >=100)
		this->cantDanioD = 80;
	else if(danio>=0 || danio<100)
		this->cantDanioD = danio;

	this->tipoDanio = tipodanio;
}

cFormaCombate::~cFormaCombate()
{}

unsigned int cFormaCombate::getCantDanioD()
{
	return this->cantDanioD;
}

eIntensidad cFormaCombate::getTipoDanio()
{
	return this->tipoDanio;
}

void cFormaCombate::setCantDanio(unsigned int danio)
{
	this->cantDanioD = danio;
}

void cFormaCombate::cambiarIntensidad(eIntensidad danio)
{
	this->tipoDanio = danio;
}

string cFormaCombate::enumTItoString()
{
	switch (this->tipoDanio)
	{
	case Poco:
		return "Poca";
	case Moderado:
		return "Moderada";
	case Mucho:
		return "Mucha";
	}
}	