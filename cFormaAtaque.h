#pragma once
#include "Headers.h"

class cFormaAtaque
{
private:
	eTipoAtaque tipodeataque;
	eDanio tipodedanio;
public:
	cFormaAtaque(eTipoAtaque tipoataque, eDanio tipodanio);
	void CambiarTipo(eTipoAtaque tipo);
	eDanio get_danio();
	eTipoAtaque get_tipoataque();
	void cambiarDanio(eDanio danio);

	~cFormaAtaque();
};