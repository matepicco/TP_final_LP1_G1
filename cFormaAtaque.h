#pragma once
#include "Headers.h"

class cFormaAtaque
{
private:
	eTipo tipodeataque;
	eDamage tipodedanio;

public:
	cFormaAtaque(eTipo tipoataque, eDamage tipodanio);
	void CambiarTipo(eTipo tipo);
	eDamage get_danio();
	eTipo get_tipo();

	~cFormaAtaque();
};