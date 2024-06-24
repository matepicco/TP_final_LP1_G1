#pragma once
#include "cVikingo.h"
#include "cDragon.h"

class cJinete :public cVikingo
{
protected:
	string apodoJ;
	struct tm fechaNac;
	eResultado TrainResult;
	list <cDragon*> listaDragonesVivos;
	static vector<string> PosicionNombres;
	static int iterador;
	static int i;
public:

	cJinete(string nom, string ape, string fecha,eCaract caract);
	~cJinete();

	string get_apodoJ();
	eResultado get_trainresult();
	void set_trainresult(eResultado resultado);

	bool RelacionarseConDragon(cDragon* drgNuevo);
	void domar();
	void altaNombre(cDragon* drg);
	bool incorporarDragon(cDragon* ptrDragon);

	bool entrenarDragon();
	void manejarDragon(cDragon* ptrD, int index);
	friend void quitarDragon(list<cDragon*> listaux, cDragon* drg);

	string enumRtostring();
	cDragon* operator[](size_t index);
	string toStringJ();	
};