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

string cDefensa::toStringFA()
{
	stringstream ss;

	ss << ". El tipo de ataque: " << this->tipoDefensa << ", infligiendo una cantidad : " << this->tipoDanio <<
		" de danio, cuantificado en : " << this->cantDanioD << endl;

	return ss.str();
}
