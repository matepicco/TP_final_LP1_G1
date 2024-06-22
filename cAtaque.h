#pragma once
#include "cFormaCombate.h"

class cAtaque: public cFormaCombate
{
protected:
	eTipoAtaque tipoAtaque;

public:
	cAtaque(eTipoAtaque tipoataque, eIntensidad tipodanio, unsigned int danio);
	~cAtaque();

	eTipoAtaque getTipoAtaque();
	void CambiarTipo(eTipoAtaque tipo);
	void combatir();
	string toStringFA();
};

