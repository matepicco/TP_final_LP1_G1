#pragma once
#include "cVikingo.h"

class cDragon;

class cGuerrero :public cVikingo
{
protected:
	unsigned int cantDanioG;
	int cantVidaG;
	bool estadoG;

public:
	cGuerrero(string nombrev, string apellidov, eCaract caracfisic, unsigned int danioG);
	~cGuerrero();

	unsigned int getCantDanioG();
	int getCantVidaG();
	void setEstadoG(bool VM);
	void setCantDanioG(unsigned int danioAct);
	void setCantVidaG(unsigned int vidaAct);

	bool RelacionarseConDragon(cDragon* drgNuevo);
	bool PelearDragon(cDragon* objD);

	string toString();
};

