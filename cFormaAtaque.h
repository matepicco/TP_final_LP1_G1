#pragma once
#include "Headers.h"

class cFormaAtaque
{
private:
	eTipoAtaque tipodeataque;
	eDamage tipodedanio;

public:
	cFormaAtaque(eTipoAtaque tipoataque, eDamage tipodanio);
	void CambiarTipo(eTipoAtaque tipo);
	eDamage get_danio();
	eTipoAtaque get_tipoataque();

	~cFormaAtaque();
};