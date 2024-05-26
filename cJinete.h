#pragma once
#include "cVikingo.h"
#include "cDragon.h"

class cJinete :public cVikingo
{
private:
	string apodoJ;
	time_t fechaNac;
	string caractFisicasJ;
	eResultado TrainResult;
	list <cDragon*> listaDragones;
	
public:
	cJinete(string nom, string ape, time_t fecha, string caracfisic);

	string get_apodoJ();
	string get_caractFisicasJ();
	eResultado get_trainresult();
	void set_trainresult(eResultado resultado);

	void trabajarEnBerk();
	void incorporarDragon(cDragon* ptrDragon);
	void domar();
	void RelacionarseConDragon();
	void manejarDragon();
	void entrenarYrendir(cDragon* ptrDragon);
	void entrenarDragon();

	~cJinete();
};
