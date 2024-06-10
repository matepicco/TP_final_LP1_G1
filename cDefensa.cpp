#include "cDefensa.h"

cDefensa:: cDefensa(eTipoDefensa tipodefensa, eDanio tipodanio, unsigned int danio) : cFormaAtaque(danio, tipodanio)
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
