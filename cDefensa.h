#pragma once
#include "cFormaAtaque.h"

class cDefensa: public cFormaAtaque
{
protected:
	eTipoDefensa tipoDefensa;

public:
	cDefensa(eTipoDefensa tipodefensa, eIntensidad tipodanio, unsigned int danio);
	~cDefensa();

	eTipoDefensa getTipoDefensa();
	void cambiarDefensa(eTipoDefensa tipo);

	void combatir();
};

