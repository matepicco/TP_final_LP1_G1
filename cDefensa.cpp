#include "cDefensa.h"

cDefensa:: cDefensa(eTipoDefensa tipodefensa, eIntensidad tipodanio, unsigned int danio) : cFormaCombate(danio, tipodanio)
{
	this->tipoDefensa = tipodefensa;
}

cDefensa::~cDefensa()
{}

eTipoDefensa cDefensa::getTipoDefensa()
{
	return this->tipoDefensa;
}

void cDefensa::cambiarDefensa(eTipoDefensa tipo)
{
	this->tipoDefensa = tipo;
}

void cDefensa::combatir()
{
}
