#pragma once
#include "cVikingo.h"
#include "cDragon.h"

class cJinete :public cVikingo
{
private:
	string apodoJ;
	time_t fechaNac;
	eResultado TrainResult;
	list <cDragon*> listaDragonesVivos;
	list <cDragon*> listaDragonesMuertos;
public:
	cJinete(string nom, string ape, time_t fecha,eCaract caract);

	string get_apodoJ();
	eResultado get_trainresult();
	void set_trainresult(eResultado resultado);
	friend void quitarDragon(list<cDragon*> listaux,cDragon* drg);
	void incorporarDragon(cDragon* ptrDragon);
	void domar();
	void manejarDragon(int index, cDragon* ptrD);
	cDragon* operator[](size_t index);
	void entrenarYrendir(cDragon* ptrDragon);
	void entrenarDragon();

	~cJinete();
};
