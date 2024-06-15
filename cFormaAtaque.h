#pragma once
#include "Headers.h"

class cFormaAtaque
{
protected:
	unsigned int cantDanioD;
	eIntensidad tipoDanio;

public:
	cFormaAtaque(unsigned int danio, eIntensidad tipodanio);
	virtual ~cFormaAtaque();

	unsigned int getCantDanioD();
	eIntensidad getTipoDanio();
	void setCantDanio(unsigned int danio);
	void cambiarIntensidad(eIntensidad danio);

	virtual void combatir() = 0; //cuando llamado a FA: chequeo si Ata/Def : polimorfismo
};