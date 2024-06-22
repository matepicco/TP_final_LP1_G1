#include "cAtaque.h"

cAtaque::cAtaque(eTipoAtaque tipoataque, eIntensidad tipodanio, unsigned int danio): cFormaCombate(danio,tipodanio)
{
	this->tipoAtaque = tipoataque;
}

cAtaque::~cAtaque()
{}

eTipoAtaque cAtaque::getTipoAtaque()
{
	return this->tipoAtaque;
}

void cAtaque::CambiarTipo(eTipoAtaque tipo)
{
	this->tipoAtaque = tipo;
}

void cAtaque::combatir()
{
}

string cAtaque::toStringFA()
{
	stringstream ss;

	ss << ". El tipo de ataque: " << this->tipoAtaque << ", infligiendo una cantidad : " << this->tipoDanio << 
		" de danio, cuantificado en : " << this->cantDanioD << endl;

	return ss.str();
}
