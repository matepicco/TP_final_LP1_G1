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
	list <cDragon*> listaDragonesMuertos;
	static vector<string> PosicionNombres;
	static int iterador;
public:
	//friend class cDragon;
	cJinete(string nom, string ape, time_t fecha,eCaract caract);
	~cJinete();

	string get_apodoJ();
	eResultado get_trainresult();
	void set_trainresult(eResultado resultado);

	bool RelacionarseConDragon(cDragon* drgNuevo);
	void domar();
	void altaNombre(cDragon* drg);
	void incorporarDragon(cDragon* ptrDragon);

	void entrenarDragon();//tiene que ir dentro de try/catch
	void manejarDragon(cDragon* ptrD, int index);
	friend void quitarDragon(list<cDragon*> listaux, cDragon* drg);

	cDragon* operator[](size_t index);
	string toString();	
};