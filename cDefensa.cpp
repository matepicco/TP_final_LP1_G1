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

string cDefensa::enumTCtoString()
{
	switch (this->tipoDefensa)
	{
	case ResisteFuego:
		return "Resiste Fuego";
	case EscamasResistentes:
		return "Escamas Resistentes";
	case Rapidez:
		return "Rapidez";
	case ArmaduraDrg:
		return "Armadura de Dragon";
	}
}

string cDefensa::toStringFA()
{
	stringstream ss;

	ss << ". Su forma de combate: " << this->enumTCtoString() << ", inflige una cantidad : " 
		<< this->enumTItoString() <<" de danio, cuantificada en : " << this->cantDanioD << endl;

	return ss.str();
}
