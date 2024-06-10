#pragma once
#include "cFormaAtaque.h"

class cAtaque: public cFormaAtaque
{
protected:
	eTipoAtaque tipoAtaque;

public:
	cAtaque(eTipoAtaque tipoataque, eDanio tipodanio, unsigned int danio);
	~cAtaque();

	eTipoAtaque getTipoAtaque();
	void CambiarTipo(eTipoAtaque tipo);
};

