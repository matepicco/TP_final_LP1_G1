#pragma once
#include "cVikingo.h"

class cGuerrero :public cVikingo
{
	//hereda atb del padre: no se repiten acá
public:
	cGuerrero();
	cGuerrero(string nombrev, string apellidov, string posicionv);

	void TerminarDragon(cDragon* objD, cGuerrero *objG);

	~cGuerrero();
};

