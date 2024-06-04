#pragma once
#include "cVikingo.h"

class cDragon;

class cGuerrero :public cVikingo
{
	unsigned int cantDanioG;
	unsigned int cantVidaG;
	bool estadoG;
	//hereda atb del padre: no se repiten acá
public:
	cGuerrero(string nombrev, string apellidov, eCaract caracfisic, unsigned int danioG);

	unsigned int getCantDanioG();
	unsigned int getCantVidaG();
	void setEstadoG(bool VM);
	void setCantDanioG(unsigned int danioAct);
	void setCantVidaG(unsigned int vidaAct);

	void RelacionarseConDragon(cVikingo* objV, cDragon* objD);
	void TerminarDragon(cDragon* objD);

	~cGuerrero();
};

