#pragma once
#include "cVikingo.h"

class cGuerrero :public cVikingo
{
	unsigned int cantDanioG;
	unsigned int cantVidaG;
	bool estadoG;
	//hereda atb del padre: no se repiten acá
public:
	cGuerrero(string nombrev, string apellidov, string posicionv, unsigned int danioG);

	unsigned int getCantDanioG();
	unsigned int getCantVidaG();
	void setEstadoG(bool VM);
	void setCantDanioG(unsigned int danioAct);
	void setCantVidaG(unsigned int vidaAct);
	void RelacionarseConDragon(cDragon* objD);
	void TerminarDragon(cDragon* objD);

	~cGuerrero();
};

