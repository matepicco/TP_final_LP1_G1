#pragma once
#include "cVikingo.h"

class cJinete :public cVikingo
{
private:
	string nombreJ;
	string apodoD;
	time_t fechaNac;
	string caractFisicasJ;
	eResultado TrainResult;
	cDragon* dragon;

public:
	cJinete(string nom, time_t fecha, string caracfisic);
	~cJinete();
	string get_nombreJ();
	void incorporarDragon(cDragon* ptrDragon);
	void trabajarBerk();
	void atacarDragones();
	void domar();
	eResultado get_trainresult();
	string get_apodo();
	string get_caracteristicas();
	void set_trainresult(eResultado resultado);

	~cJinete();
};
