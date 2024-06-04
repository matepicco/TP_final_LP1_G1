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

	void RelacionarseConDragon(cVikingo* ptrV);
	void domar();
	void incorporarDragon(cDragon* ptrDragon);
	void entrenarYrendir(cDragon* ptrDragon);
	void entrenarDragon();//tiene que ir dentro de try/catch
	void manejarDragon(cDragon* ptrD);
	friend void quitarDragon(list<cDragon*> listaux, cDragon* drg);
	cDragon* operator[](size_t index);

	~cJinete();
};