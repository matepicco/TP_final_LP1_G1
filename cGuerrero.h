#pragma once
#include "cVikingo.h"

class cDragon;

class cGuerrero :public cVikingo
{
protected:
	unsigned int cantDanioG;
	unsigned int cantVidaG;
	bool estadoG;
	//hereda atb del padre: no se repiten ac�
public:
	cGuerrero(string nombrev, string apellidov, eCaract caracfisic, unsigned int danioG);
	~cGuerrero();

	unsigned int getCantDanioG();
	unsigned int getCantVidaG();
	void setEstadoG(bool VM);
	void setCantDanioG(unsigned int danioAct);
	void setCantVidaG(unsigned int vidaAct);

	void RelacionarseConDragon(cDragon* drgNuevo);
	void TerminarDragon(cDragon* objD);

	string toString();
};

