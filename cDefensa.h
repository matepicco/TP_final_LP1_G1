#pragma once
#include "cFormaCombate.h"

class cDefensa: public cFormaCombate
{
protected:
	eTipoDefensa tipoDefensa;

public:
	cDefensa(eTipoDefensa tipodefensa, eIntensidad tipodanio, unsigned int danio);
	~cDefensa();

	eTipoDefensa getTipoDefensa();
	void cambiarDefensa(eTipoDefensa tipo);

	string enumTCtoString();
	string toStringFA();
};

