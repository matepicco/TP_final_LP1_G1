#pragma once
#include "Headers.h"

class cFormaCombate
{
protected:
	unsigned int cantDanioD;
	eIntensidad tipoDanio;

public:
	cFormaCombate(unsigned int danio, eIntensidad tipodanio);
	virtual ~cFormaCombate();

	unsigned int getCantDanioD();
	eIntensidad getTipoDanio();
	void setCantDanio(unsigned int danio);
	void cambiarIntensidad(eIntensidad danio);

	virtual void combatir() = 0; 
};