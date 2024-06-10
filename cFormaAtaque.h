#pragma once
#include "Headers.h"

class cFormaAtaque
{
protected:
	unsigned int cantDanioD;
	eDanio tipoDanio;

public:
	cFormaAtaque(unsigned int danio, eDanio tipodanio);
	virtual ~cFormaAtaque();

	unsigned int getCantDanioD();
	eDanio getTipoDanio();
	void setCantDanio(unsigned int danio);
	void cambiarDanio(eDanio danio);

	virtual void combatir() = 0; //cuando llamado a FA: chequeo si Ata/Def : polimorfismo
};