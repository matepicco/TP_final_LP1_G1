#pragma once
#include "Headers.h"

class cFormaAtaque
{
private:
	eTipoAtaque tipodeataque;
	eDanio tipodedanio;
	unsigned int cantDanioD;
public:
	cFormaAtaque(eTipoAtaque tipoataque, eDanio tipodanio, unsigned int danio);
	~cFormaAtaque();

	void CambiarTipo(eTipoAtaque tipo);
	eDanio get_danio();
	eTipoAtaque get_tipoataque();
	unsigned int getCantDanioD();
	void cambiarDanio(eDanio danio);
};