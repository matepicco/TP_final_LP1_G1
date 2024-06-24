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

string cAtaque::enumTCtoString()
{
	switch (this->tipoAtaque) {
	case BolasFuego:
		return "Bolas de Fuego";
	case Araniar:
		return "Araniar";
	case Coletazo:
		return "Coletazo";
	case Mordidita:
		return "Mordidita";
	}
}

string cAtaque::toStringFA()
{
	stringstream ss;

	ss << ". Su forma de combate: " << this->enumTCtoString() << ", inflige una cantidad : " << this->enumTItoString()
		<<" de danio, cuantificado en : " << this->cantDanioD << endl;

	return ss.str();
}
